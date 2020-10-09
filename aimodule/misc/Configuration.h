#pragma once
#include <string>
#include <stdint.h>

namespace aimodule_conf
{
	static const std::string RPC_SERVER_ADDRESS = "0.0.0.0:37412";
	static const int64_t REFERENCE_BASE_ADDR = 0x7FF7C7570000;
}

namespace expert_conf
{
	static const int COMMAND_TIMEOUT_SECONDS = 5;

	// addresses related to expert engine in general
	static const int64_t ADDR_FUNC_RUN_LIST = 0x7FF7C7CAD310;
	static const int64_t ADDR_VAR_INFORMATION_AI = 0x7FF7CA148270;
	static const int64_t ADDR_VAR_CURRENT_PLAYER = 0x7FF7CA144BC0;

	// funcs related to actions
	static const int64_t ADDR_FUNC_TRAIN = 0x7FF7C7CF54E0;
	static const int64_t ADDR_FUNC_BUILD = 0x7FF7C7CF3C00;
	static const int64_t ADDR_FUNC_UP_GET_FACT = 0x7FF7C7CC3DF0;

	// funcs related to facts
	static const int64_t ADDR_FUNC_GET_FACT_BY_ID = 0x7FF7C7CC12E0;
	static const int64_t ADDR_FUNC_GET_GOAL = 0x7FF7C7D2E150;
}
