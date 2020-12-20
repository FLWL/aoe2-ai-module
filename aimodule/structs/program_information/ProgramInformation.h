#pragma once
#include <stdint.h>

#include "misc/Statics.h"

namespace structs
{
	struct ProgramInformation
	{
#if defined GAME_DE

#elif defined GAME_AOC
		SPACER(0, 504);
		char gameDataFilePath[MAX_PATH + 1];
#endif
	};
}
