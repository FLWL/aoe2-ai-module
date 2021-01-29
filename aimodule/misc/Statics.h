#pragma once
#include "misc/Configuration.h"

#include <vector>
#include <string>
#include <sstream>

#include <Windows.h>

#define SPACER(from, size) uint8_t _spacer##from[##size]

namespace statics
{
	static uintptr_t GetGameModuleBaseAddr()
	{
		return (uintptr_t) GetModuleHandle(nullptr);
	}
	
#if defined GAME_AOC
	static uintptr_t TranslateAddr(uintptr_t absoluteAddress, uintptr_t absoluteBaseAddress = aimodule_conf::REFERENCE_BASE_ADDR)
	{
		return GetGameModuleBaseAddr() + (absoluteAddress - absoluteBaseAddress);
	}
#endif

	template<typename T>
	static void SetFuncAddr(T& func, uintptr_t newAddr)
	{
		*reinterpret_cast<uintptr_t*>(&func) = newAddr;
	}

	static std::vector<std::string> SplitString(const std::string& inputString, const char deliminator)
	{
		std::vector<std::string> result;
		std::stringstream stringStream(inputString);
		std::string item;

		while (std::getline(stringStream, item, deliminator))
			result.push_back(item);

		return result;
	}

	static uint8_t HexStringToByte(const std::string& inputString)
	{
		try
		{
			return (uint8_t) std::stoul(inputString, nullptr, 16);
		}
		catch (const std::exception&) { }

		return 0;
	}
}
