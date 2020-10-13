#include "ExpertFact.h"

#include <iostream>

#include "misc/Statics.h"

void ExpertFact::UpdateAddresses()
{
	statics::SetFuncAddr(FuncGetGoal, statics::TranslateAddr(expert_conf::ADDR_FUNC_GET_GOAL));
	statics::SetFuncAddr(FuncGetFactById, statics::TranslateAddr(expert_conf::ADDR_FUNC_GET_FACT_BY_ID));

	informationAi = (void**)statics::TranslateAddr(expert_conf::ADDR_VAR_INFORMATION_AI);
	currentPlayer = (void**)statics::TranslateAddr(expert_conf::ADDR_VAR_CURRENT_PLAYER);
}

void ExpertFact::EvaluateRelOpCalled(int value)
{
	lastRelOpValue = value;
}

unsigned int ExpertFact::Goal(unsigned int goalId)
{
	return (unsigned int)FuncGetGoal(*informationAi, goalId - 1);
}

std::vector<unsigned int> ExpertFact::Goals()
{
	unsigned* goalArray = (unsigned int*)((uintptr_t)*informationAi + 812);

	std::vector<unsigned int> result;
	result.assign(goalArray, goalArray + 512);

	return result;
}
