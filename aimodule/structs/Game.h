#pragma once
#include <stdint.h>

#include "misc/Statics.h"
#include "structs/program_information/ProgramInformation.h"
#include "structs/program_mode/ProgramMode.h"
#include "structs/world/World.h"

namespace structs
{
	struct Game
	{
#if defined GAME_DE
		SPACER(0, 704);
		ProgramMode* programMode;
#elif defined GAME_AOC
		SPACER(0, 40);
		ProgramInformation* programInformation;
		SPACER(44, 436);
		int32_t programMode;
		SPACER(484, 52);
		char workingDirectory[MAX_PATH + 1];
		SPACER(797, 263);
		World* world;
#endif
	};
}
