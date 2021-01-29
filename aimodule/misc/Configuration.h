#pragma once
#include <string>
#include <stdint.h>

#if defined _WIN64
	#define GAME_DE
#else
	#define GAME_AOC
#endif

namespace aimodule_conf
{
	static const std::wstring VERSION = L"0.2.1";
	static const std::string RPC_SERVER_ADDRESS = "0.0.0.0:37412";

#if defined GAME_AOC
	static const int32_t REFERENCE_BASE_ADDR = 0x400000;
#endif
}

namespace expert_conf
{
	static const int COMMAND_TIMEOUT_SECONDS = 5;

#ifdef GAME_DE
	static const std::string SIG_FUNC_RUN_LIST = "40 53 56 57 41 54 48 83 ec ?? 48 8b 05 ?? ?? ?? ?? 48 33 c4 48 89 44 24 38 4d 8b e0 48 8b d9 85 d2 0f 88 ?? ?? ?? ??";
	static const std::string SIG_FUNC_GAME_TYPE = "40 57 48 83 ec 40 48 c7 44 24 30 fe ff ff ff 48 89 5c 24 50 8b da 8b f9 48 8d 54 24 60 48 8b 0d ?? ?? ?? ?? e8 ?? ?? ?? ??";
#elif defined GAME_AOC
	static const int32_t ADDR_FUNC_RUN_LIST = 0x5F9C10;
	static const int32_t ADDR_FUNC_GET_STRING = 0x5F9950;
	static const int32_t ADDR_FUNC_EVALUATE_FACT = 0x5F7080;
	static const int32_t ADDR_FUNC_INTERNAL_GAME_TYPE = 0x445A50;
	static const int32_t ADDR_FUNC_INTERNAL_GET_GATE_COUNT = 0x496C20;
	static const int32_t ADDR_FUNC_INTERNAL_STRATEGIC_NUMBER = 0x472780;
	static const int32_t ADDR_FUNC_INTERNAL_WALL_COMPLETED_PERCENTAGE = 0x496C50;
	static const int32_t ADDR_FUNC_INTERNAL_WALL_INVISIBLE_PERCENTAGE = 0x496C80;
	static const int32_t ADDR_FUNC_UP_EVALUATE_REL_OP = 0x7A89D9;
	static const int32_t ADDR_FUNC_CC_PLAYERS_BUILDING_COUNT_EVALUATE_REL_OP = 0x49F143;
	static const int32_t ADDR_FUNC_CC_PLAYERS_BUILDING_TYPE_COUNT_EVALUATE_REL_OP = 0x49F25E;
	static const int32_t ADDR_FUNC_CC_PLAYERS_UNIT_COUNT_EVALUATE_REL_OP = 0x49F333;
	static const int32_t ADDR_FUNC_CC_PLAYERS_UNIT_TYPE_COUNT_EVALUATE_REL_OP_1 = 0x49F40E;
	static const int32_t ADDR_FUNC_CC_PLAYERS_UNIT_TYPE_COUNT_EVALUATE_REL_OP_2 = 0x49F4BE;
	static const int32_t ADDR_FUNC_FIND_SYMBOL = 0x4CDEE0;

	static const int32_t ADDR_PTR_THIS_INFORMATION_AI = 0x6B45B4;
	static const int32_t ADDR_PTR_THIS_TACTICAL_AI = 0x6B3998;
	static const int32_t ADDR_PTR_THIS_PLAYER = 0x6B399C;
	static const int32_t ADDR_PTR_BASE_GAME = 0x7912A0;

	static const int32_t ADDR_VAR_DIFFICULTY = 0x6B3594;
	static const int32_t ADDR_VAR_STARTING_AGE = 0x6B358C;
	static const int32_t ADDR_VAR_STARTING_RESOURCES = 0x6B3588;
#endif

	// some constant values that differ between games
#if defined GAME_DE
	static const int CONST_TYPE_OP_CONST = 0;
	static const int CONST_TYPE_OP_GOAL = 2;
	static const int CONST_TYPE_OP_SN = 1;
#elif defined GAME_AOC
	static const int CONST_TYPE_OP_CONST = 6;
	static const int CONST_TYPE_OP_GOAL = 13;
	static const int CONST_TYPE_OP_SN = 20;
#endif

	static const int CONST_CUSTOM_STRING_ID = 89626;
	static const int CONST_TEMP_GOAL_ID = 400;
}
