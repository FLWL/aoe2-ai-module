#pragma once
#include <stdint.h>

#include "misc/Statics.h"
#include "structs/world/unit/Unit.h"

namespace structs
{
	struct PlayerUnitsList
	{
#if defined GAME_DE

#elif defined GAME_AOC
		void* virtualTable;
		Unit** units;
		int numUnits;
#endif
	};
}
