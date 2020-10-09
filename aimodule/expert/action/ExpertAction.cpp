#include "ExpertAction.h"
#include "misc/Statics.h"

#include <iostream>

void ExpertAction::UpdateAddresses()
{
	statics::SetFuncAddr(FuncTrain, statics::TranslateAddr(expert_conf::ADDR_FUNC_TRAIN));
	statics::SetFuncAddr(FuncBuild, statics::TranslateAddr(expert_conf::ADDR_FUNC_BUILD));
	statics::SetFuncAddr(FuncUpGetFact, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_FACT));
}

bool ExpertAction::Train(int unitType)
{
	return FuncTrain(unitType) == 0;
}

bool ExpertAction::Build(int buildingType)
{
	return FuncBuild(buildingType) != 0;
}

void ExpertAction::UpGetFact(int factId, int factParam, int goalId)
{
	FuncUpGetFact(factId, factParam, goalId);
}
