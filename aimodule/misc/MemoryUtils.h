#pragma once
#include "misc/Statics.h"

#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include <inttypes.h>
#include <psapi.h>

#include <Zydis/Zydis.h>

namespace memory_utils
{
	static bool MemoryFlagsReadable(DWORD state, DWORD protect)
	{
		return state == MEM_COMMIT && !(protect & (PAGE_GUARD | PAGE_NOACCESS));
	}

	static std::vector<uint8_t> ReadMemory(uintptr_t startAddress, uintptr_t length)
	{
		std::vector<uint8_t> result;
		if (length <= 0) return result;

		MEMORY_BASIC_INFORMATION memoryBasicInformation;
		uintptr_t currentAddress = startAddress;
		uintptr_t endAddress = startAddress + length;
		while (VirtualQuery((void*)currentAddress, &memoryBasicInformation, sizeof(memoryBasicInformation)))
		{
			if (!MemoryFlagsReadable(memoryBasicInformation.State, memoryBasicInformation.Protect))
				return result;

			uintptr_t regionEnd = ((uintptr_t)memoryBasicInformation.BaseAddress) + memoryBasicInformation.RegionSize;
			while (currentAddress < regionEnd)
			{
				result.push_back(*(uint8_t*)(currentAddress));

				if (++currentAddress == endAddress)
					return result;
			}
		}

		return result;
	}

	static uintptr_t GetModuleSize(const uintptr_t moduleBaseAddress)
	{
		std::vector<uint8_t> imageDosHeaderData = memory_utils::ReadMemory(moduleBaseAddress, sizeof(IMAGE_DOS_HEADER));
		if (imageDosHeaderData.size() == sizeof(IMAGE_DOS_HEADER))
		{
			IMAGE_DOS_HEADER* imageDosHeader = (IMAGE_DOS_HEADER*) imageDosHeaderData.data();
			
			std::vector<uint8_t> imageNtHeadersData = memory_utils::ReadMemory(moduleBaseAddress + imageDosHeader->e_lfanew, sizeof(IMAGE_NT_HEADERS));
			if (imageNtHeadersData.size() == sizeof(IMAGE_NT_HEADERS))
			{
				IMAGE_NT_HEADERS* imageNtHeaders = (IMAGE_NT_HEADERS*) imageNtHeadersData.data();
				return imageNtHeaders->OptionalHeader.SizeOfImage;
			}
		}

		return 0;
	}

	static std::vector<uint8_t> ParsePattern(const std::string& pattern)
	{
		std::vector<std::string> splitPattern = statics::SplitString(pattern, ' ');
		std::vector<uint8_t> result;

		for (const std::string& element : splitPattern)
			result.push_back(statics::HexStringToByte(element));

		return result;
	}

	// address range [ )
	static uintptr_t FindPattern(const uintptr_t startAddress, const uintptr_t endAddress, const std::string& pattern)
	{
		std::vector<uint8_t> parsedPattern = ParsePattern(pattern);

		MEMORY_BASIC_INFORMATION memoryBasicInformation;
		uintptr_t searchedAddress = startAddress;
		while (searchedAddress < endAddress)
		{
			if (VirtualQuery((void*) searchedAddress, &memoryBasicInformation, sizeof(memoryBasicInformation)))
			{
				uintptr_t regionEnd = ((uintptr_t) memoryBasicInformation.BaseAddress) + memoryBasicInformation.RegionSize;

				if (MemoryFlagsReadable(memoryBasicInformation.State, memoryBasicInformation.Protect))
				{
					for (uintptr_t pointer = searchedAddress; pointer <= regionEnd - ((uintptr_t) parsedPattern.size()); pointer++)
					{
						for (size_t offset = 0; offset < parsedPattern.size(); offset++)
						{
							if (((uint8_t*) pointer)[offset] != parsedPattern[offset] && parsedPattern[offset] > 0)
								break;

							if (offset == parsedPattern.size() - 1)
								return pointer;
						}
					}
				}

				searchedAddress = regionEnd;
			}
			else
			{
				// could not get information about this memory region, skip ahead
				searchedAddress += 4096;
			}
		}

		return 0;
	}

	static uintptr_t FindPatternInModule(const uintptr_t moduleBaseAddress, const std::string& pattern)
	{
		uintptr_t moduleSize = GetModuleSize(moduleBaseAddress);
		uintptr_t moduleEnd = moduleBaseAddress + moduleSize;

		return FindPattern(moduleBaseAddress, moduleEnd, pattern);
	}

	static uintptr_t FindPatternInGameModule(const std::string& pattern)
	{
		uintptr_t gameModuleBaseAddress = statics::GetGameModuleBaseAddr();
		return FindPatternInModule(gameModuleBaseAddress, pattern);
	}

#if defined GAME_DE
	static uintptr_t GetInstructionImmMemOperand(uintptr_t instructionAddress, const std::vector<uint8_t>& instructionData)
	{
		ZydisDecoder decoder;
		ZydisDecoderInit(&decoder, ZYDIS_MACHINE_MODE_LONG_64, ZYDIS_ADDRESS_WIDTH_64);

		ZydisDecodedInstruction decodedInstruction;
		if (ZYAN_SUCCESS(ZydisDecoderDecodeBuffer(&decoder, instructionData.data(), instructionData.size(), &decodedInstruction)))
		{
			for (int operandIndex = 0; operandIndex < decodedInstruction.operand_count; operandIndex++)
			{
				if (decodedInstruction.operands[operandIndex].type == ZydisOperandType::ZYDIS_OPERAND_TYPE_IMMEDIATE ||
					decodedInstruction.operands[operandIndex].type == ZydisOperandType::ZYDIS_OPERAND_TYPE_MEMORY)
				{
					uintptr_t targetAddress;
					if (ZYAN_SUCCESS(ZydisCalcAbsoluteAddress(&decodedInstruction, &decodedInstruction.operands[operandIndex], instructionAddress, &targetAddress)))
					{
						return targetAddress;
					}
				}
			}
		}

		return 0;
	}
#elif defined GAME_AOC
	static void PlaceJumpInstruction(uint8_t* addr, uint8_t* target, size_t length, uint8_t* replacedBytes = nullptr)
	{
		// make memory accessible
		DWORD oldProtect;
		VirtualProtect(addr, length, PAGE_EXECUTE_READWRITE, &oldProtect);

		// copy original bytes in case we want to restore them later
		if (replacedBytes != nullptr)
			memcpy(replacedBytes, addr, length);

		// put a jmp instruction at the desired location
		*(addr + 0) = 0xE9;

		// calculate and set the jmp instruction target
		*(uintptr_t*)(addr + 1) = (uintptr_t)target - (uintptr_t)addr - 5;

		// pad any leftover bytes with nops
		for (size_t i = 5; i < length; i++)
			*(addr + i) = 0x90;

		// restore memory protection flags
		DWORD oldProtectTemp;
		VirtualProtect(addr, length, oldProtect, &oldProtectTemp);
	}

	static void WriteMemory(uint8_t* addr, uint8_t* bytes, size_t size)
	{
		// make memory accessible
		DWORD oldProtect;
		VirtualProtect(addr, size, PAGE_EXECUTE_READWRITE, &oldProtect);

		// copy
		memcpy(addr, bytes, size);

		// restore memory protection flags
		DWORD oldProtectTemp;
		VirtualProtect(addr, size, oldProtect, &oldProtectTemp);
	}

	static std::unordered_map<uint8_t*, std::tuple<uint8_t*, size_t>> registeredJumpMap;

	static void RegisterJump(uintptr_t addr, void* target, size_t length = 5)
	{
		uint8_t* arr = new uint8_t[length];
		PlaceJumpInstruction((uint8_t*)addr, (uint8_t*)target, length, arr);
		registeredJumpMap.emplace((uint8_t*)addr, std::make_tuple(arr, length));
	}

	static void RemoveJump(uintptr_t addr)
	{
		std::tuple<uint8_t*, size_t> jump = registeredJumpMap[(uint8_t*)addr];
		WriteMemory((uint8_t*)addr, std::get<0>(jump), std::get<1>(jump));
		delete std::get<0>(jump);
	}
#endif
}
