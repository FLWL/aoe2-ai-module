#include "ExpertCommandHandler.h"
#include "expert/fact/ExpertFact.h"
#include "expert/command/ExpertCommand.h"
#include "expert/action/ExpertAction.h"
#include "structs/Game.h"
#include "protos/expert/expert_api.pb.h"
#include "AIModule.h"

void ExpertCommandHandler::GetMapDimensions(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::command::GetMapDimensions command;
	anyCommand.UnpackTo(&command);

	std::array<int, 2> factValue = ExpertCommand::GetMapDimensions();
	
	protos::expert::command::GetMapDimensionsResult result;
	result.set_width(factValue[0]);
	result.set_height(factValue[1]);
	anyResult->PackFrom(result);
}

// to prevent scanning for buildings by the foundation terrain type,
// generalize the terrain types so that both foundation and desert would
// for example return the grass terrain type which should be functionally
// equivalent
int ExpertCommandHandler::GeneralizeTerrainType(int terrainId)
{
	switch (terrainId)
	{
		case 1: // terrain-water
		case 15: // terrain-water-old
		case 22: // terrain-water-deep
		case 23: // terrain-water-medium
		case 28: // terrain-water-bridge
		{
			return 1; // terrain-water
		}
		case 2: // terrain-water-beach
		case 37: // terrain-ice-beach
		{
			return 2; // terrain-water-beach
		}
		case 4: // terrain-shallows
		{
			return 4; // terrain-shallows
		}
		case 26: // terrain-ice
		case 35: // terrain-ice2
		{
			return 26; // terrain-ice
		}
	}

	return 0; // terrain-grass
}

void ExpertCommandHandler::GetTiles(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::command::GetTiles command;
	anyCommand.UnpackTo(&command);

	protos::expert::command::GetTilesResult result;
	std::array<int, 2> mapDimensions = ExpertCommand::GetMapDimensions();

	// cache temp goal pair
	int cachedGoals[2];
	for (int i = 0; i < 2; i++) cachedGoals[i] = ExpertFact::Goal(expert_conf::CONST_TEMP_GOAL_ID + i);

	for (int x = 0; x < mapDimensions[0]; x++)
	{
		for (int y = 0; y < mapDimensions[1]; y++)
		{
			ExpertAction::SetGoal(expert_conf::CONST_TEMP_GOAL_ID, x);
			ExpertAction::SetGoal(expert_conf::CONST_TEMP_GOAL_ID + 1, y);

			int visibility = ExpertFact::UpPointExplored(expert_conf::CONST_TEMP_GOAL_ID);
			if (visibility)
			{
				protos::expert::command::Tile* tile = result.add_tiles();
				tile->set_x(x);
				tile->set_y(y);
				tile->set_height(ExpertFact::UpPointElevation(expert_conf::CONST_TEMP_GOAL_ID));
				tile->set_terrain(GeneralizeTerrainType(ExpertFact::UpPointTerrain(expert_conf::CONST_TEMP_GOAL_ID)));
				tile->set_visibility(visibility);
			}
		}
	}

	// restore goals
	for (int i = 0; i < 2; i++) ExpertAction::SetGoal(expert_conf::CONST_TEMP_GOAL_ID + i, cachedGoals[i]);

	anyResult->PackFrom(result);
}

void ExpertCommandHandler::GetUnits(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::command::GetUnits command;
	anyCommand.UnpackTo(&command);

	protos::expert::command::GetUnitsResult result;
	anyResult->PackFrom(result);
}
