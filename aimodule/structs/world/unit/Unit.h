#pragma once
#include <stdint.h>

#include "misc/Statics.h"
#include "structs/world/unit/UnitVirtualTable.h"
#include "structs/world/unit/master_unit/MasterUnit.h"

namespace structs
{
	struct Unit
	{
#if defined GAME_DE

#elif defined GAME_AOC
		UnitVirtualTable* virtualTable;
		int entityId;
		MasterUnit* masterUnit;
		SPACER(0x38, 0x38 - 0xC);
		float positionX;
		float positionY;
		float positionZ;
#endif
	};
}
