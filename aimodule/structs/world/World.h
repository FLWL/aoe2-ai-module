#pragma once
#include <stdint.h>

#include "misc/Statics.h"
#include "structs/world/ai_expert/AIExpert.h"
#include "structs/world/player/Player.h"

namespace structs
{
	struct World
	{
#if defined GAME_DE
		SPACER(0x0, 0x90 - 0x0);
		int32_t gameState;
#elif defined GAME_AOC
		void* virtualTable;
		SPACER(0x4, 0x28 - 0x4);
		uint8_t gamePaused;
		uint8_t gameState;
		SPACER(0x2C, 0x48 - 0x2C);
		int numPlayers;
		Player** players;
#endif
	};
}
