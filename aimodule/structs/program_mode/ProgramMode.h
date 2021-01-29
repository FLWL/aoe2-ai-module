#pragma once
#include <stdint.h>

#include "misc/Statics.h"

namespace structs
{
#if defined GAME_DE
	struct ProgramMode
	{
		SPACER(0, 8);
		int32_t programModeId;
	};
#endif
}
