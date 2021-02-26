#pragma once
#include <stdint.h>

#include "misc/Statics.h"

namespace structs
{
	struct SymbolHashNode
	{
#if defined GAME_DE

#elif defined GAME_AOC
		SymbolHashNode* next;
		char* symbolText;
		uint8_t type;
		uint16_t id;
#endif
	};
}
