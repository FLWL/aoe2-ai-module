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
		SPACER(0x0, 0x2C0 - 0x0);
		ProgramMode* programMode;
		SPACER(0x2C8, 0x2E0 - 0x2C8);
		World* world;
#elif defined GAME_AOC
		SPACER(0x0, 0x28 - 0x0);
		ProgramInformation* programInformation;
		SPACER(0x2C, 0x1E0 - 0x2C);
		int32_t programModeId;
		SPACER(0x1E4, 0x218 - 0x1E4);
		char workingDirectory[MAX_PATH + 1];
		SPACER(0x31D, 0x424 - 0x31D);
		World* world;
#endif
	};
}
