#pragma once
#include <stdint.h>

#include "misc/Statics.h"

namespace structs
{
	struct MasterUnit
	{
#if defined GAME_DE

#elif defined GAME_AOC
		void* virtualTable;
		SPACER(0x4, 0x10 - 0x4);
		uint16_t id;
		SPACER(0x12, 0x6D - 0x12);
		uint8_t fogFlag;
#endif
	};
}
