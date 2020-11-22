#pragma once
#include "misc/Configuration.h"

#include <vector>

#include <Windows.h>

namespace statics
{
	static uintptr_t GetGameModuleBaseAddr()
	{
		return (uintptr_t) GetModuleHandle(NULL);
	}
	
	static uintptr_t TranslateAddr(uintptr_t absoluteAddress, uintptr_t absoluteBaseAddress = aimodule_conf::REFERENCE_BASE_ADDR)
	{
		return GetGameModuleBaseAddr() + (absoluteAddress - absoluteBaseAddress);
	}

	template<typename T>
	static void SetFuncAddr(T& func, uintptr_t newAddr)
	{
		*reinterpret_cast<uintptr_t*>(&func) = newAddr;
	}

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
#endif
}
