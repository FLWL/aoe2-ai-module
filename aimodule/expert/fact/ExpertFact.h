#pragma once
#include <vector>

#include <stdint.h>

class ExpertFact
{
public:
	static void UpdateAddresses();
	static void EvaluateRelOpCalled(int value);

	static unsigned int Goal(unsigned int goalId);
	static std::vector<unsigned int> Goals();

private:
	ExpertFact() {};

	inline static int lastRelOpValue = 0;
	inline static void** informationAi;
	inline static void** currentPlayer;

	inline static intptr_t(__fastcall* FuncGetGoal)(void* informationAI, unsigned int goalId) = 0;
	inline static intptr_t(__fastcall* FuncGetFactById)(void* player, void* otherPlayer, int factId, int factParam) = 0;
};
