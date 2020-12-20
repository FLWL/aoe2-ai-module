#pragma once
#include <stdint.h>

#include "misc/Statics.h"
#include "structs/world/player/Player.h"

namespace structs
{
	struct World
	{
#if defined GAME_DE

#elif defined GAME_AOC
		SPACER(0, 76);
		Player** playerList;
#endif
	};
}
