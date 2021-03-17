#pragma once
#include <stdint.h>

#include "misc/Statics.h"
#include "structs/world/player/PlayerUnitsList.h"

namespace structs
{
	struct Player
	{
#if defined GAME_DE

#elif defined GAME_AOC
		SPACER(0x0, 0x78 - 0x0);
		PlayerUnitsList* units;
		PlayerUnitsList* sleepingUnits;
		PlayerUnitsList* doppelgangerUnits;
#endif
	};
}
