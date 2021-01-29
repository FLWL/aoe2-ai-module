#pragma once
#include <stdint.h>

#include "misc/Statics.h"
#include "structs/world/ai_expert/ai_action/AIAction.h"
#include "structs/world/ai_expert/ai_fact/AIFact.h"
#include "structs/world/ai_expert/symbol_hash_node/SymbolHashNode.h"

namespace structs
{
	struct AIExpert
	{
#if defined GAME_DE
		void* vfptr;
		int16_t maxStrings;
		int16_t numStrings;
		char** string;
		int16_t maxFacts;
		int16_t numFacts;
		AIFact* fact;
		char** factNames;
		int16_t maxActions;
		int16_t numActions;
		AIAction* action;
		char** actionNames;
#elif defined GAME_AOC
		void* vfptr;
		int16_t maxStrings;
		int16_t numStrings;
		char** string;
		int16_t maxFacts;
		int16_t numFacts;
		AIFact* fact;
		int16_t maxActions;
		int16_t numActions;
		AIAction* action;
		int16_t maxLists;
		void* listInfo;
		void* groupTable;
		void* currentRule;
		void* currentList;
		void* currentGroupTable;
		int globalSymbolTableSize;
		SymbolHashNode** bucket;
#endif
	};
}
