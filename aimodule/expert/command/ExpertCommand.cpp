#include "ExpertCommand.h"
#include "expert/action/ExpertAction.h"
#include "expert/fact/ExpertFact.h"

std::array<int, 2> ExpertCommand::GetMapDimensions()
{
	std::array<int, 2> result;

	// cache goals
	int cachedGoals[2];
	for (int i = 0; i < 2; i++) cachedGoals[i] = ExpertFact::Goal(expert_conf::CONST_TEMP_GOAL_ID + i);

	// set a goal pair to a coordinate out of map, bound it, add 1 to max x and y to get map dimensions
	ExpertAction::SetGoal(expert_conf::CONST_TEMP_GOAL_ID, 999);
	ExpertAction::SetGoal(expert_conf::CONST_TEMP_GOAL_ID + 1, 999);
	ExpertAction::UpBoundPoint(expert_conf::CONST_TEMP_GOAL_ID, expert_conf::CONST_TEMP_GOAL_ID);
	for (int i = 0; i < 2; i++) result[i] = ExpertFact::Goal(expert_conf::CONST_TEMP_GOAL_ID + i) + 1;

	// restore goals
	for (int i = 0; i < 2; i++) ExpertAction::SetGoal(expert_conf::CONST_TEMP_GOAL_ID + i, cachedGoals[i]);
	return result;
}
