#pragma once
#include <stdint.h>

#include "misc/Statics.h"

namespace structs
{
	struct AIAction
	{
		uint8_t argc;
		void* actionFn;
		uint8_t arg1Type;
		uint8_t arg2Type;
		uint8_t arg3Type;
		uint8_t arg4Type;
	};
}
