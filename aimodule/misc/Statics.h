#pragma once
#include "misc/Configuration.h"
#include <Windows.h>

namespace statics
{
	static int64_t GetGameModuleBaseAddr()
	{
		return (int64_t) GetModuleHandleA("AoE2DE_s.exe");
	}
	
	static int64_t TranslateAddr(int64_t absoluteAddress, int64_t absoluteBaseAddress = aimodule_conf::REFERENCE_BASE_ADDR)
	{
		return GetGameModuleBaseAddr() + (absoluteAddress - absoluteBaseAddress);
	}

	template<typename T>
	static void SetFuncAddr(T func, int64_t newAddr)
	{
		*reinterpret_cast<int64_t*>(func) = newAddr;
	}
}
