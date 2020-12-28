#pragma once
#include "misc/Statics.h"

#include <vector>
#include <unordered_map>

namespace memory_utils
{
#if defined GAME_AOC
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
		VirtualProtect((PVOID)addr, length, oldProtect, &oldProtectTemp);
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
		VirtualProtect((PVOID)addr, size, oldProtect, &oldProtectTemp);
	}

	std::unordered_map<uint8_t*, std::tuple<uint8_t*, size_t>> registeredJumpMap;

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
