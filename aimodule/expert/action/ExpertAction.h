#pragma once
#include <stdint.h>

class ExpertAction
{
public:
	static void UpdateAddresses();

	static bool Train(int unitType);
	static bool Build(int buildingType);
	static void UpGetFact(int factId, int factParam, int goalId);

private:
	ExpertAction() {};

	inline static char(__fastcall* FuncTrain)(int unitType) = 0;
	inline static char(__fastcall* FuncBuild)(int buildingType) = 0;
	inline static int64_t(__fastcall* FuncUpGetFact)(int factId, int factParam, int goalId) = 0;
};
