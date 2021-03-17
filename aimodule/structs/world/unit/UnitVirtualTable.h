#pragma once
#include <stdint.h>

#include "misc/Statics.h"

namespace structs
{
	struct Player;
	struct Unit;

	struct UnitVirtualTable
	{
#if defined GAME_DE

#elif defined GAME_AOC
		SPACER(0x0, 0xFC - 0x0);
		uint8_t(__thiscall* getVisibility)(structs::Unit* unit, structs::Player* player);
#endif
	};
}
