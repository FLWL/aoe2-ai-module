#pragma once
#include <vector>

#include <stdint.h>

class ExpertFact
{
public:
	static void UpdateAddresses();

	static int64_t UpGetFact(int factId, int factParam);
	static unsigned int Goal(unsigned int goalId);
	static std::vector<unsigned int> Goals();

private:
	ExpertFact() {};

	inline static void** informationAi;
	inline static void** currentPlayer;

	inline static int64_t(__fastcall* FuncGetFactById)(void* player, void* otherPlayer, int factId, int factParam) = 0;
	inline static int64_t(__fastcall* FuncGetGoal)(void* informationAI, unsigned int goalId) = 0;
};
