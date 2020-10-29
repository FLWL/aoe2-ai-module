#include "ExpertFact.h"

#include <iostream>

#include "misc/Statics.h"

void ExpertFact::UpdateAddresses()
{
	statics::SetFuncAddr(FuncAttackSoldierCount, statics::TranslateAddr(expert_conf::ADDR_FUNC_ATTACK_SOLDIER_COUNT));
	statics::SetFuncAddr(FuncAttackWarboatCount, statics::TranslateAddr(expert_conf::ADDR_FUNC_ATTACK_WARBOAT_COUNT));
	statics::SetFuncAddr(FuncBuildingAvailable, statics::TranslateAddr(expert_conf::ADDR_FUNC_BUILDING_AVAILABLE));
	statics::SetFuncAddr(FuncBuildingCount, statics::TranslateAddr(expert_conf::ADDR_FUNC_BUILDING_COUNT));
	statics::SetFuncAddr(FuncBuildingCountTotal, statics::TranslateAddr(expert_conf::ADDR_FUNC_BUILDING_COUNT_TOTAL));
	statics::SetFuncAddr(FuncBuildingTypeCount, statics::TranslateAddr(expert_conf::ADDR_FUNC_BUILDING_TYPE_COUNT));
	statics::SetFuncAddr(FuncBuildingTypeCountTotal, statics::TranslateAddr(expert_conf::ADDR_FUNC_BUILDING_TYPE_COUNT_TOTAL));
	statics::SetFuncAddr(FuncCanAffordBuilding, statics::TranslateAddr(expert_conf::ADDR_FUNC_CAN_AFFORD_BUILDING));
	statics::SetFuncAddr(FuncCanAffordCompleteWall, statics::TranslateAddr(expert_conf::ADDR_FUNC_CAN_AFFORD_COMPLETE_WALL));
	statics::SetFuncAddr(FuncCanAffordResearch, statics::TranslateAddr(expert_conf::ADDR_FUNC_CAN_AFFORD_RESEARCH));
	statics::SetFuncAddr(FuncCanAffordUnit, statics::TranslateAddr(expert_conf::ADDR_FUNC_CAN_AFFORD_UNIT));
	statics::SetFuncAddr(FuncCanBuild, statics::TranslateAddr(expert_conf::ADDR_FUNC_CAN_BUILD));
	statics::SetFuncAddr(FuncCanBuildGate, statics::TranslateAddr(expert_conf::ADDR_FUNC_CAN_BUILD_GATE));
	statics::SetFuncAddr(FuncCanBuildGateWithEscrow, statics::TranslateAddr(expert_conf::ADDR_FUNC_CAN_BUILD_GATE_WITH_ESCROW));
	statics::SetFuncAddr(FuncCanBuildWall, statics::TranslateAddr(expert_conf::ADDR_FUNC_CAN_BUILD_WALL));
	statics::SetFuncAddr(FuncCanBuildWallWithEscrow, statics::TranslateAddr(expert_conf::ADDR_FUNC_CAN_BUILD_WALL_WITH_ESCROW));
	statics::SetFuncAddr(FuncCanBuildWithEscrow, statics::TranslateAddr(expert_conf::ADDR_FUNC_CAN_BUILD_WITH_ESCROW));
	statics::SetFuncAddr(FuncCanBuyCommodity, statics::TranslateAddr(expert_conf::ADDR_FUNC_CAN_BUY_COMMODITY));
	statics::SetFuncAddr(FuncCanResearch, statics::TranslateAddr(expert_conf::ADDR_FUNC_CAN_RESEARCH));
	statics::SetFuncAddr(FuncCanResearchWithEscrow, statics::TranslateAddr(expert_conf::ADDR_FUNC_CAN_RESEARCH_WITH_ESCROW));
	statics::SetFuncAddr(FuncCanSellCommodity, statics::TranslateAddr(expert_conf::ADDR_FUNC_CAN_SELL_COMMODITY));
	statics::SetFuncAddr(FuncCanSpy, statics::TranslateAddr(expert_conf::ADDR_FUNC_CAN_SPY));
	statics::SetFuncAddr(FuncCanSpyWithEscrow, statics::TranslateAddr(expert_conf::ADDR_FUNC_CAN_SPY_WITH_ESCROW));
	statics::SetFuncAddr(FuncCanTrain, statics::TranslateAddr(expert_conf::ADDR_FUNC_CAN_TRAIN));
	statics::SetFuncAddr(FuncCanTrainWithEscrow, statics::TranslateAddr(expert_conf::ADDR_FUNC_CAN_TRAIN_WITH_ESCROW));
	statics::SetFuncAddr(FuncCcPlayersBuildingCount, statics::TranslateAddr(expert_conf::ADDR_FUNC_CC_PLAYERS_BUILDING_COUNT));
	statics::SetFuncAddr(FuncCcPlayersBuildingTypeCount, statics::TranslateAddr(expert_conf::ADDR_FUNC_CC_PLAYERS_BUILDING_TYPE_COUNT));
	statics::SetFuncAddr(FuncCcPlayersUnitCount, statics::TranslateAddr(expert_conf::ADDR_FUNC_CC_PLAYERS_UNIT_COUNT));
	statics::SetFuncAddr(FuncCcPlayersUnitTypeCount, statics::TranslateAddr(expert_conf::ADDR_FUNC_CC_PLAYERS_UNIT_TYPE_COUNT));
	statics::SetFuncAddr(FuncCheatsEnabled, statics::TranslateAddr(expert_conf::ADDR_FUNC_CHEATS_ENABLED));
	statics::SetFuncAddr(FuncCivSelected, statics::TranslateAddr(expert_conf::ADDR_FUNC_CIV_SELECTED));
	statics::SetFuncAddr(FuncCivilianPopulation, statics::TranslateAddr(expert_conf::ADDR_FUNC_CIVILIAN_POPULATION));
	statics::SetFuncAddr(FuncCommodityBuyingPrice, statics::TranslateAddr(expert_conf::ADDR_FUNC_COMMODITY_BUYING_PRICE));
	statics::SetFuncAddr(FuncCommoditySellingPrice, statics::TranslateAddr(expert_conf::ADDR_FUNC_COMMODITY_SELLING_PRICE));
	statics::SetFuncAddr(FuncCurrentAge, statics::TranslateAddr(expert_conf::ADDR_FUNC_CURRENT_AGE));
	statics::SetFuncAddr(FuncCurrentAgeTime, statics::TranslateAddr(expert_conf::ADDR_FUNC_CURRENT_AGE_TIME));
	statics::SetFuncAddr(FuncCurrentScore, statics::TranslateAddr(expert_conf::ADDR_FUNC_CURRENT_SCORE));
	statics::SetFuncAddr(FuncDeathMatchGame, statics::TranslateAddr(expert_conf::ADDR_FUNC_DEATH_MATCH_GAME));
	statics::SetFuncAddr(FuncDefendSoldierCount, statics::TranslateAddr(expert_conf::ADDR_FUNC_DEFEND_SOLDIER_COUNT));
	statics::SetFuncAddr(FuncDefendWarboatCount, statics::TranslateAddr(expert_conf::ADDR_FUNC_DEFEND_WARBOAT_COUNT));
	statics::SetFuncAddr(FuncDifficulty, statics::TranslateAddr(expert_conf::ADDR_FUNC_DIFFICULTY));
	statics::SetFuncAddr(FuncDoctrine, statics::TranslateAddr(expert_conf::ADDR_FUNC_DOCTRINE));
	statics::SetFuncAddr(FuncDropsiteMinDistance, statics::TranslateAddr(expert_conf::ADDR_FUNC_DROPSITE_MIN_DISTANCE));
	statics::SetFuncAddr(FuncEndingAge, statics::TranslateAddr(expert_conf::ADDR_FUNC_ENDING_AGE));
	statics::SetFuncAddr(FuncEnemyBuildingsInTown, statics::TranslateAddr(expert_conf::ADDR_FUNC_ENEMY_BUILDINGS_IN_TOWN));
	statics::SetFuncAddr(FuncEnemyCapturedRelics, statics::TranslateAddr(expert_conf::ADDR_FUNC_ENEMY_CAPTURED_RELICS));
	statics::SetFuncAddr(FuncEscrowAmount, statics::TranslateAddr(expert_conf::ADDR_FUNC_ESCROW_AMOUNT));
	statics::SetFuncAddr(FuncEventDetected, statics::TranslateAddr(expert_conf::ADDR_FUNC_EVENT_DETECTED));
	statics::SetFuncAddr(FuncFalse, statics::TranslateAddr(expert_conf::ADDR_FUNC_FALSE));
	statics::SetFuncAddr(FuncFeCanBuildAtPoint, statics::TranslateAddr(expert_conf::ADDR_FUNC_FE_CAN_BUILD_AT_POINT));
	statics::SetFuncAddr(FuncFoodAmount, statics::TranslateAddr(expert_conf::ADDR_FUNC_FOOD_AMOUNT));
	statics::SetFuncAddr(FuncGameTime, statics::TranslateAddr(expert_conf::ADDR_FUNC_GAME_TIME));
	statics::SetFuncAddr(FuncGameType, statics::TranslateAddr(expert_conf::ADDR_FUNC_GAME_TYPE));
	statics::SetFuncAddr(FuncGateCount, statics::TranslateAddr(expert_conf::ADDR_FUNC_GATE_COUNT));
	statics::SetFuncAddr(FuncGoal, statics::TranslateAddr(expert_conf::ADDR_FUNC_GOAL));
	statics::SetFuncAddr(FuncGoldAmount, statics::TranslateAddr(expert_conf::ADDR_FUNC_GOLD_AMOUNT));
	statics::SetFuncAddr(FuncHoldKohRuin, statics::TranslateAddr(expert_conf::ADDR_FUNC_HOLD_KOH_RUIN));
	statics::SetFuncAddr(FuncHoldRelics, statics::TranslateAddr(expert_conf::ADDR_FUNC_HOLD_RELICS));
	statics::SetFuncAddr(FuncHousingHeadroom, statics::TranslateAddr(expert_conf::ADDR_FUNC_HOUSING_HEADROOM));
	statics::SetFuncAddr(FuncIdleFarmCount, statics::TranslateAddr(expert_conf::ADDR_FUNC_IDLE_FARM_COUNT));
	statics::SetFuncAddr(FuncMapSize, statics::TranslateAddr(expert_conf::ADDR_FUNC_MAP_SIZE));
	statics::SetFuncAddr(FuncMapType, statics::TranslateAddr(expert_conf::ADDR_FUNC_MAP_TYPE));
	statics::SetFuncAddr(FuncMilitaryPopulation, statics::TranslateAddr(expert_conf::ADDR_FUNC_MILITARY_POPULATION));
	statics::SetFuncAddr(FuncPlayerComputer, statics::TranslateAddr(expert_conf::ADDR_FUNC_PLAYER_COMPUTER));
	statics::SetFuncAddr(FuncPlayerHuman, statics::TranslateAddr(expert_conf::ADDR_FUNC_PLAYER_HUMAN));
	statics::SetFuncAddr(FuncPlayerInGame, statics::TranslateAddr(expert_conf::ADDR_FUNC_PLAYER_IN_GAME));
	statics::SetFuncAddr(FuncPlayerNumber, statics::TranslateAddr(expert_conf::ADDR_FUNC_PLAYER_NUMBER));
	statics::SetFuncAddr(FuncPlayerResigned, statics::TranslateAddr(expert_conf::ADDR_FUNC_PLAYER_RESIGNED));
	statics::SetFuncAddr(FuncPlayerValid, statics::TranslateAddr(expert_conf::ADDR_FUNC_PLAYER_VALID));
	statics::SetFuncAddr(FuncPlayersAchievements, statics::TranslateAddr(expert_conf::ADDR_FUNC_PLAYERS_ACHIEVEMENTS));
	statics::SetFuncAddr(FuncPlayersBuildingCount, statics::TranslateAddr(expert_conf::ADDR_FUNC_PLAYERS_BUILDING_COUNT));
	statics::SetFuncAddr(FuncPlayersBuildingTypeCount, statics::TranslateAddr(expert_conf::ADDR_FUNC_PLAYERS_BUILDING_TYPE_COUNT));
	statics::SetFuncAddr(FuncPlayersCiv, statics::TranslateAddr(expert_conf::ADDR_FUNC_PLAYERS_CIV));
	statics::SetFuncAddr(FuncPlayersCivilianPopulation, statics::TranslateAddr(expert_conf::ADDR_FUNC_PLAYERS_CIVILIAN_POPULATION));
	statics::SetFuncAddr(FuncPlayersCurrentAge, statics::TranslateAddr(expert_conf::ADDR_FUNC_PLAYERS_CURRENT_AGE));
	statics::SetFuncAddr(FuncPlayersCurrentAgeTime, statics::TranslateAddr(expert_conf::ADDR_FUNC_PLAYERS_CURRENT_AGE_TIME));
	statics::SetFuncAddr(FuncPlayersMilitaryPopulation, statics::TranslateAddr(expert_conf::ADDR_FUNC_PLAYERS_MILITARY_POPULATION));
	statics::SetFuncAddr(FuncPlayersPopulation, statics::TranslateAddr(expert_conf::ADDR_FUNC_PLAYERS_POPULATION));
	statics::SetFuncAddr(FuncPlayersScore, statics::TranslateAddr(expert_conf::ADDR_FUNC_PLAYERS_SCORE));
	statics::SetFuncAddr(FuncPlayersStance, statics::TranslateAddr(expert_conf::ADDR_FUNC_PLAYERS_STANCE));
	statics::SetFuncAddr(FuncPlayersTribute, statics::TranslateAddr(expert_conf::ADDR_FUNC_PLAYERS_TRIBUTE));
	statics::SetFuncAddr(FuncPlayersTributeMemory, statics::TranslateAddr(expert_conf::ADDR_FUNC_PLAYERS_TRIBUTE_MEMORY));
	statics::SetFuncAddr(FuncPlayersUnitCount, statics::TranslateAddr(expert_conf::ADDR_FUNC_PLAYERS_UNIT_COUNT));
	statics::SetFuncAddr(FuncPlayersUnitTypeCount, statics::TranslateAddr(expert_conf::ADDR_FUNC_PLAYERS_UNIT_TYPE_COUNT));
	statics::SetFuncAddr(FuncPopulation, statics::TranslateAddr(expert_conf::ADDR_FUNC_POPULATION));
	statics::SetFuncAddr(FuncPopulationCap, statics::TranslateAddr(expert_conf::ADDR_FUNC_POPULATION_CAP));
	statics::SetFuncAddr(FuncPopulationHeadroom, statics::TranslateAddr(expert_conf::ADDR_FUNC_POPULATION_HEADROOM));
	statics::SetFuncAddr(FuncRandomNumber, statics::TranslateAddr(expert_conf::ADDR_FUNC_RANDOM_NUMBER));
	statics::SetFuncAddr(FuncRegicideGame, statics::TranslateAddr(expert_conf::ADDR_FUNC_REGICIDE_GAME));
	statics::SetFuncAddr(FuncResearchAvailable, statics::TranslateAddr(expert_conf::ADDR_FUNC_RESEARCH_AVAILABLE));
	statics::SetFuncAddr(FuncResearchCompleted, statics::TranslateAddr(expert_conf::ADDR_FUNC_RESEARCH_COMPLETED));
	statics::SetFuncAddr(FuncResourceFound, statics::TranslateAddr(expert_conf::ADDR_FUNC_RESOURCE_FOUND));
	statics::SetFuncAddr(FuncSharedGoal, statics::TranslateAddr(expert_conf::ADDR_FUNC_SHARED_GOAL));
	statics::SetFuncAddr(FuncSheepAndForageTooFar, statics::TranslateAddr(expert_conf::ADDR_FUNC_SHEEP_AND_FORAGE_TOO_FAR));
	statics::SetFuncAddr(FuncSoldierCount, statics::TranslateAddr(expert_conf::ADDR_FUNC_SOLDIER_COUNT));
	statics::SetFuncAddr(FuncStanceToward, statics::TranslateAddr(expert_conf::ADDR_FUNC_STANCE_TOWARD));
	statics::SetFuncAddr(FuncStartingAge, statics::TranslateAddr(expert_conf::ADDR_FUNC_STARTING_AGE));
	statics::SetFuncAddr(FuncStartingResources, statics::TranslateAddr(expert_conf::ADDR_FUNC_STARTING_RESOURCES));
	statics::SetFuncAddr(FuncStoneAmount, statics::TranslateAddr(expert_conf::ADDR_FUNC_STONE_AMOUNT));
	statics::SetFuncAddr(FuncStrategicNumber, statics::TranslateAddr(expert_conf::ADDR_FUNC_STRATEGIC_NUMBER));
	statics::SetFuncAddr(FuncTauntDetected, statics::TranslateAddr(expert_conf::ADDR_FUNC_TAUNT_DETECTED));
	statics::SetFuncAddr(FuncTimerTriggered, statics::TranslateAddr(expert_conf::ADDR_FUNC_TIMER_TRIGGERED));
	statics::SetFuncAddr(FuncTownUnderAttack, statics::TranslateAddr(expert_conf::ADDR_FUNC_TOWN_UNDER_ATTACK));
	statics::SetFuncAddr(FuncTraceFact, statics::TranslateAddr(expert_conf::ADDR_FUNC_TRACE_FACT));
	statics::SetFuncAddr(FuncTrue, statics::TranslateAddr(expert_conf::ADDR_FUNC_TRUE));
	statics::SetFuncAddr(FuncUnitAvailable, statics::TranslateAddr(expert_conf::ADDR_FUNC_UNIT_AVAILABLE));
	statics::SetFuncAddr(FuncUnitCount, statics::TranslateAddr(expert_conf::ADDR_FUNC_UNIT_COUNT));
	statics::SetFuncAddr(FuncUnitCountTotal, statics::TranslateAddr(expert_conf::ADDR_FUNC_UNIT_COUNT_TOTAL));
	statics::SetFuncAddr(FuncUnitTypeCount, statics::TranslateAddr(expert_conf::ADDR_FUNC_UNIT_TYPE_COUNT));
	statics::SetFuncAddr(FuncUnitTypeCountTotal, statics::TranslateAddr(expert_conf::ADDR_FUNC_UNIT_TYPE_COUNT_TOTAL));
	statics::SetFuncAddr(FuncUpAlliedGoal, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_ALLIED_GOAL));
	statics::SetFuncAddr(FuncUpAlliedResourceAmount, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_ALLIED_RESOURCE_AMOUNT));
	statics::SetFuncAddr(FuncUpAlliedResourcePercent, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_ALLIED_RESOURCE_PERCENT));
	statics::SetFuncAddr(FuncUpAlliedSn, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_ALLIED_SN));
	statics::SetFuncAddr(FuncUpAttackerClass, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_ATTACKER_CLASS));
	statics::SetFuncAddr(FuncUpBuildingTypeInTown, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_BUILDING_TYPE_IN_TOWN));
	statics::SetFuncAddr(FuncUpCanBuild, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_CAN_BUILD));
	statics::SetFuncAddr(FuncUpCanBuildLine, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_CAN_BUILD_LINE));
	statics::SetFuncAddr(FuncUpCanResearch, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_CAN_RESEARCH));
	statics::SetFuncAddr(FuncUpCanSearch, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_CAN_SEARCH));
	statics::SetFuncAddr(FuncUpCanTrain, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_CAN_TRAIN));
	statics::SetFuncAddr(FuncUpCompareGoal, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_COMPARE_GOAL));
	statics::SetFuncAddr(FuncUpDefenderCount, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_DEFENDER_COUNT));
	statics::SetFuncAddr(FuncUpEnemyBuildingsInTown, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_ENEMY_BUILDINGS_IN_TOWN));
	statics::SetFuncAddr(FuncUpEnemyUnitsInTown, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_ENEMY_UNITS_IN_TOWN));
	statics::SetFuncAddr(FuncUpEnemyVillagersInTown, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_ENEMY_VILLAGERS_IN_TOWN));
	statics::SetFuncAddr(FuncUpGaiaTypeCount, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GAIA_TYPE_COUNT));
	statics::SetFuncAddr(FuncUpGaiaTypeCountTotal, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GAIA_TYPE_COUNT_TOTAL));
	statics::SetFuncAddr(FuncUpGroupSize, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GROUP_SIZE));
	statics::SetFuncAddr(FuncUpIdleUnitCount, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_IDLE_UNIT_COUNT));
	statics::SetFuncAddr(FuncUpObjectData, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_OBJECT_DATA));
	statics::SetFuncAddr(FuncUpObjectTargetData, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_OBJECT_TARGET_DATA));
	statics::SetFuncAddr(FuncUpObjectTypeCount, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_OBJECT_TYPE_COUNT));
	statics::SetFuncAddr(FuncUpObjectTypeCountTotal, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_OBJECT_TYPE_COUNT_TOTAL));
	statics::SetFuncAddr(FuncUpPathDistance, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_PATH_DISTANCE));
	statics::SetFuncAddr(FuncUpPendingObjects, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_PENDING_OBJECTS));
	statics::SetFuncAddr(FuncUpPendingPlacement, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_PENDING_PLACEMENT));
	statics::SetFuncAddr(FuncUpPlayerDistance, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_PLAYER_DISTANCE));
	statics::SetFuncAddr(FuncUpPlayersInGame, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_PLAYERS_IN_GAME));
	statics::SetFuncAddr(FuncUpPointContains, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_POINT_CONTAINS));
	statics::SetFuncAddr(FuncUpPointDistance, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_POINT_DISTANCE));
	statics::SetFuncAddr(FuncUpPointElevation, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_POINT_ELEVATION));
	statics::SetFuncAddr(FuncUpPointExplored, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_POINT_EXPLORED));
	statics::SetFuncAddr(FuncUpPointTerrain, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_POINT_TERRAIN));
	statics::SetFuncAddr(FuncUpPointZone, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_POINT_ZONE));
	statics::SetFuncAddr(FuncUpProjectileDetected, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_PROJECTILE_DETECTED));
	statics::SetFuncAddr(FuncUpProjectileTarget, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_PROJECTILE_TARGET));
	statics::SetFuncAddr(FuncUpRemainingBoarAmount, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_REMAINING_BOAR_AMOUNT));
	statics::SetFuncAddr(FuncUpResearchStatus, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_RESEARCH_STATUS));
	statics::SetFuncAddr(FuncUpResourceAmount, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_RESOURCE_AMOUNT));
	statics::SetFuncAddr(FuncUpResourcePercent, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_RESOURCE_PERCENT));
	statics::SetFuncAddr(FuncUpTimerStatus, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_TIMER_STATUS));
	statics::SetFuncAddr(FuncUpTrainSiteReady, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_TRAIN_SITE_READY));
	statics::SetFuncAddr(FuncUpUnitTypeInTown, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_UNIT_TYPE_IN_TOWN));
	statics::SetFuncAddr(FuncUpVillagerTypeInTown, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_VILLAGER_TYPE_IN_TOWN));
	statics::SetFuncAddr(FuncVictoryCondition, statics::TranslateAddr(expert_conf::ADDR_FUNC_VICTORY_CONDITION));
	statics::SetFuncAddr(FuncWallCompletedPercentage, statics::TranslateAddr(expert_conf::ADDR_FUNC_WALL_COMPLETED_PERCENTAGE));
	statics::SetFuncAddr(FuncWallInvisiblePercentage, statics::TranslateAddr(expert_conf::ADDR_FUNC_WALL_INVISIBLE_PERCENTAGE));
	statics::SetFuncAddr(FuncWarboatCount, statics::TranslateAddr(expert_conf::ADDR_FUNC_WARBOAT_COUNT));
	statics::SetFuncAddr(FuncWoodAmount, statics::TranslateAddr(expert_conf::ADDR_FUNC_WOOD_AMOUNT));

	informationAi = (void**)statics::TranslateAddr(expert_conf::ADDR_VAR_INFORMATION_AI);
}

void ExpertFact::EvaluateRelOpCalled(int value)
{
	lastRelOpValue = value;
}

int ExpertFact::AttackSoldierCount()
{
	FuncAttackSoldierCount(0, 0);
	return lastRelOpValue;
}

int ExpertFact::AttackWarboatCount()
{
	FuncAttackWarboatCount(0, 0);
	return lastRelOpValue;
}

bool ExpertFact::BuildingAvailable(int buildingType)
{
	return FuncBuildingAvailable(buildingType);
}

int ExpertFact::BuildingCount()
{
	FuncBuildingCount(0, 0);
	return lastRelOpValue;
}

int ExpertFact::BuildingCountTotal()
{
	FuncBuildingCountTotal(0, 0);
	return lastRelOpValue;
}

int ExpertFact::BuildingTypeCount(int buildingType)
{
	FuncBuildingTypeCount(buildingType, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::BuildingTypeCountTotal(int buildingType)
{
	FuncBuildingTypeCountTotal(buildingType, 0, 0);
	return lastRelOpValue;
}

bool ExpertFact::CanAffordBuilding(int buildingType)
{
	return FuncCanAffordBuilding(buildingType);
}

bool ExpertFact::CanAffordCompleteWall(int perimeter, int wallType)
{
	return FuncCanAffordCompleteWall(perimeter, wallType);
}

bool ExpertFact::CanAffordResearch(int researchType)
{
	return FuncCanAffordResearch(researchType);
}

bool ExpertFact::CanAffordUnit(int unitType)
{
	return FuncCanAffordUnit(unitType);
}

bool ExpertFact::CanBuild(int buildingType)
{
	return FuncCanBuild(buildingType);
}

bool ExpertFact::CanBuildGate(int perimeter)
{
	return FuncCanBuildGate(perimeter);
}

bool ExpertFact::CanBuildGateWithEscrow(int perimeter)
{
	return FuncCanBuildGateWithEscrow(perimeter);
}

bool ExpertFact::CanBuildWall(int perimeter, int wallType, int escrowFlag)
{
	return FuncCanBuildWall(perimeter, wallType, escrowFlag);
}

bool ExpertFact::CanBuildWallWithEscrow(int perimeter, int wallType)
{
	return FuncCanBuildWallWithEscrow(perimeter, wallType);
}

bool ExpertFact::CanBuildWithEscrow(int buildingType)
{
	return FuncCanBuildWithEscrow(buildingType);
}

bool ExpertFact::CanBuyCommodity(int commodityType)
{
	return FuncCanBuyCommodity(commodityType);
}

bool ExpertFact::CanResearch(int researchType)
{
	return FuncCanResearch(researchType);
}

bool ExpertFact::CanResearchWithEscrow(int researchType)
{
	return FuncCanResearchWithEscrow(researchType);
}

bool ExpertFact::CanSellCommodity(int commodityType)
{
	return FuncCanSellCommodity(commodityType);
}

bool ExpertFact::CanSpy()
{
	return FuncCanSpy();
}

bool ExpertFact::CanSpyWithEscrow()
{
	return FuncCanSpyWithEscrow();
}

bool ExpertFact::CanTrain(int unitType)
{
	return FuncCanTrain(unitType);
}

bool ExpertFact::CanTrainWithEscrow(int unitType)
{
	return FuncCanTrainWithEscrow(unitType);
}

int ExpertFact::CcPlayersBuildingCount(int playerNumber)
{
	FuncCcPlayersBuildingCount(playerNumber, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::CcPlayersBuildingTypeCount(int playerNumber, int buildingType)
{
	FuncCcPlayersBuildingTypeCount(playerNumber, buildingType, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::CcPlayersUnitCount(int playerNumber)
{
	FuncCcPlayersUnitCount(playerNumber, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::CcPlayersUnitTypeCount(int playerNumber, int unitType)
{
	FuncCcPlayersUnitTypeCount(playerNumber, unitType, 0, 0);
	return lastRelOpValue;
}

bool ExpertFact::CheatsEnabled()
{
	return FuncCheatsEnabled();
}

bool ExpertFact::CivSelected(int civ)
{
	return FuncCivSelected(civ);
}

int ExpertFact::CivilianPopulation()
{
	FuncCivilianPopulation(0, 0);
	return lastRelOpValue;
}

int ExpertFact::CommodityBuyingPrice(int commodityType)
{
	FuncCommodityBuyingPrice(commodityType, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::CommoditySellingPrice(int commodityType)
{
	FuncCommoditySellingPrice(commodityType, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::CurrentAge()
{
	FuncCurrentAge(0, 0);
	return lastRelOpValue;
}

int ExpertFact::CurrentAgeTime()
{
	FuncCurrentAgeTime(0, 0);
	return lastRelOpValue;
}

int ExpertFact::CurrentScore()
{
	FuncCurrentScore(0, 0);
	return lastRelOpValue;
}

bool ExpertFact::DeathMatchGame()
{
	return FuncDeathMatchGame();
}

int ExpertFact::DefendSoldierCount()
{
	FuncDefendSoldierCount(0, 0);
	return lastRelOpValue;
}

int ExpertFact::DefendWarboatCount()
{
	FuncDefendWarboatCount(0, 0);
	return lastRelOpValue;
}

int ExpertFact::Difficulty()
{
	FuncDifficulty(0, 0);
	return lastRelOpValue;
}

bool ExpertFact::Doctrine(int value)
{
	return FuncDoctrine(value);
}

int ExpertFact::DropsiteMinDistance(int resourceType)
{
	FuncDropsiteMinDistance(resourceType, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::EndingAge()
{
	FuncEndingAge(0, 0);
	return lastRelOpValue;
}

bool ExpertFact::EnemyBuildingsInTown()
{
	return FuncEnemyBuildingsInTown();
}

bool ExpertFact::EnemyCapturedRelics()
{
	return FuncEnemyCapturedRelics();
}

int ExpertFact::EscrowAmount(int resourceType)
{
	FuncEscrowAmount(resourceType, 0, 0);
	return lastRelOpValue;
}

bool ExpertFact::EventDetected(int eventType, int id)
{
	return FuncEventDetected(eventType, id);
}

bool ExpertFact::False()
{
	return FuncFalse();
}

bool ExpertFact::FeCanBuildAtPoint(int param1, int param2, int param3, int param4)
{
	return FuncFeCanBuildAtPoint(param1, param2, param3, param4);
}

int ExpertFact::FoodAmount()
{
	FuncFoodAmount(0, 0);
	return lastRelOpValue;
}

int ExpertFact::GameTime()
{
	FuncGameTime(0, 0);
	return lastRelOpValue;
}

int ExpertFact::GameType()
{
	FuncGameType(0, 0);
	return lastRelOpValue;
}

int ExpertFact::GateCount(int perimeter)
{
	FuncGateCount(perimeter, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::Goal(int goalId)
{
	// Call up-compare-goal instead as the usual goal fact doesn't call EvaluateRelOp
	FuncUpCompareGoal(goalId, 0, 0);
	return lastRelOpValue;
}

std::vector<unsigned int> ExpertFact::Goals()
{
	unsigned* goalArray = (unsigned int*)((uintptr_t)*informationAi + 812);

	std::vector<unsigned int> result;
	result.assign(goalArray, goalArray + 512);

	return result;
}

int ExpertFact::GoldAmount()
{
	FuncGoldAmount(0, 0);
	return lastRelOpValue;
}

bool ExpertFact::HoldKohRuin()
{
	return FuncHoldKohRuin();
}

bool ExpertFact::HoldRelics()
{
	return FuncHoldRelics();
}

int ExpertFact::HousingHeadroom()
{
	FuncHousingHeadroom(0, 0);
	return lastRelOpValue;
}

int ExpertFact::IdleFarmCount()
{
	FuncIdleFarmCount(0, 0);
	return lastRelOpValue;
}

bool ExpertFact::MapSize(int mapSize)
{
	return FuncMapSize(mapSize);
}

bool ExpertFact::MapType(int mapType)
{
	return FuncMapType(mapType);
}

int ExpertFact::MilitaryPopulation()
{
	FuncMilitaryPopulation(0, 0);
	return lastRelOpValue;
}

bool ExpertFact::PlayerComputer(int playerNumber)
{
	return FuncPlayerComputer(playerNumber);
}

bool ExpertFact::PlayerHuman(int playerNumber)
{
	return FuncPlayerHuman(playerNumber);
}

bool ExpertFact::PlayerInGame(int playerNumber)
{
	return FuncPlayerInGame(playerNumber);
}

bool ExpertFact::PlayerNumber(int playerNumber)
{
	return FuncPlayerNumber(playerNumber);
}

bool ExpertFact::PlayerResigned(int playerNumber)
{
	return FuncPlayerResigned(playerNumber);
}

bool ExpertFact::PlayerValid(int playerNumber)
{
	return FuncPlayerValid(playerNumber);
}

bool ExpertFact::PlayersAchievements(int param1, int param2, int param3, int param4)
{
	return FuncPlayersAchievements(param1, param2, param3, param4);
}

int ExpertFact::PlayersBuildingCount(int playerNumber)
{
	FuncPlayersBuildingCount(playerNumber, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::PlayersBuildingTypeCount(int playerNumber, int buildingType)
{
	FuncPlayersBuildingTypeCount(playerNumber, buildingType, 0, 0);
	return lastRelOpValue;
}

bool ExpertFact::PlayersCiv(int playerNumber)
{
	return FuncPlayersCiv(playerNumber);
}

int ExpertFact::PlayersCivilianPopulation(int playerNumber)
{
	FuncPlayersCivilianPopulation(playerNumber, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::PlayersCurrentAge(int playerNumber)
{
	FuncPlayersCurrentAge(playerNumber, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::PlayersCurrentAgeTime(int playerNumber)
{
	FuncPlayersCurrentAgeTime(playerNumber, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::PlayersMilitaryPopulation(int playerNumber)
{
	FuncPlayersMilitaryPopulation(playerNumber, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::PlayersPopulation(int playerNumber)
{
	FuncPlayersPopulation(playerNumber, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::PlayersScore(int playerNumber)
{
	FuncPlayersScore(playerNumber, 0, 0);
	return lastRelOpValue;
}

bool ExpertFact::PlayersStance(int playerNumber, int stance)
{
	return FuncPlayersStance(playerNumber, stance);
}

int ExpertFact::PlayersTribute(int playerNumber, int resourceType)
{
	FuncPlayersTribute(playerNumber, resourceType, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::PlayersTributeMemory(int playerNumber, int resourceType)
{
	FuncPlayersTributeMemory(playerNumber, resourceType, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::PlayersUnitCount(int playerNumber)
{
	FuncPlayersUnitCount(playerNumber, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::PlayersUnitTypeCount(int playerNumber, int unitType)
{
	FuncPlayersUnitTypeCount(playerNumber, unitType, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::Population()
{
	FuncPopulation(0, 0);
	return lastRelOpValue;
}

int ExpertFact::PopulationCap()
{
	FuncPopulationCap(0, 0);
	return lastRelOpValue;
}

int ExpertFact::PopulationHeadroom()
{
	FuncPopulationHeadroom(0, 0);
	return lastRelOpValue;
}

int ExpertFact::RandomNumber()
{
	FuncRandomNumber(0, 0);
	return lastRelOpValue;
}

bool ExpertFact::RegicideGame()
{
	return FuncRegicideGame();
}

bool ExpertFact::ResearchAvailable(int researchType)
{
	return FuncResearchAvailable(researchType);
}

bool ExpertFact::ResearchCompleted(int researchType)
{
	return FuncResearchCompleted(researchType);
}

bool ExpertFact::ResourceFound(int resourceType)
{
	return FuncResourceFound(resourceType);
}

bool ExpertFact::SharedGoal(int goalId, int value)
{
	return FuncSharedGoal(goalId, value);
}

bool ExpertFact::SheepAndForageTooFar()
{
	return FuncSheepAndForageTooFar();
}

int ExpertFact::SoldierCount()
{
	FuncSoldierCount(0, 0);
	return lastRelOpValue;
}

bool ExpertFact::StanceToward(int playerNumber, int stance)
{
	return FuncStanceToward(playerNumber, stance);
}

int ExpertFact::StartingAge()
{
	FuncStartingAge(0, 0);
	return lastRelOpValue;
}

int ExpertFact::StartingResources()
{
	FuncStartingResources(0, 0);
	return lastRelOpValue;
}

int ExpertFact::StoneAmount()
{
	FuncStoneAmount(0, 0);
	return lastRelOpValue;
}

int ExpertFact::StrategicNumber(int strategicNumber)
{
	FuncStrategicNumber(strategicNumber, 0, 0);
	return lastRelOpValue;
}

bool ExpertFact::TauntDetected(int playerNumber, int tauntId)
{
	return FuncTauntDetected(playerNumber, tauntId);
}

bool ExpertFact::TimerTriggered(int timerId)
{
	return FuncTimerTriggered(timerId);
}

bool ExpertFact::TownUnderAttack()
{
	return FuncTownUnderAttack();
}

bool ExpertFact::TraceFact(int param)
{
	return FuncTraceFact(param);
}

bool ExpertFact::True()
{
	return FuncTrue();
}

bool ExpertFact::UnitAvailable(int unitType)
{
	return FuncUnitAvailable(unitType);
}

int ExpertFact::UnitCount()
{
	FuncUnitCount(0, 0);
	return lastRelOpValue;
}

int ExpertFact::UnitCountTotal()
{
	FuncUnitCountTotal(0, 0);
	return lastRelOpValue;
}

int ExpertFact::UnitTypeCount(int unitType)
{
	FuncUnitTypeCount(unitType, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UnitTypeCountTotal(int unitType)
{
	FuncUnitTypeCountTotal(unitType, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpAlliedGoal(int computerAlly, int goalId)
{
	FuncUpAlliedGoal(computerAlly, goalId, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpAlliedResourceAmount(int ally, int resourceAmount)
{
	FuncUpAlliedResourceAmount(ally, resourceAmount, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpAlliedResourcePercent(int ally, int resourceAmount)
{
	FuncUpAlliedResourcePercent(ally, resourceAmount, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpAlliedSn(int computerAlly, int snId)
{
	FuncUpAlliedSn(computerAlly, snId, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpAttackerClass()
{
	FuncUpAttackerClass(0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpBuildingTypeInTown(int typeOp, int buildingId)
{
	FuncUpBuildingTypeInTown(typeOp, buildingId, 0, 0);
	return lastRelOpValue;
}

bool ExpertFact::UpCanBuild(int escrowState, int typeOp, int buildingId)
{
	return FuncUpCanBuild(escrowState, typeOp, buildingId);
}

bool ExpertFact::UpCanBuildLine(int escrowState, int goalPoint, int typeOp, int buildingId)
{
	return FuncUpCanBuildLine(escrowState, goalPoint, typeOp, buildingId);
}

bool ExpertFact::UpCanResearch(int escrowState, int typeOp, int techId)
{
	return FuncUpCanResearch(escrowState, typeOp, techId);
}

bool ExpertFact::UpCanSearch(int searchSource)
{
	return FuncUpCanSearch(searchSource);
}

bool ExpertFact::UpCanTrain(int escrowState, int typeOp, int unitId)
{
	return FuncUpCanTrain(escrowState, typeOp, unitId);
}

int ExpertFact::UpDefenderCount()
{
	FuncUpDefenderCount(0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpEnemyBuildingsInTown()
{
	FuncUpEnemyBuildingsInTown(0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpEnemyUnitsInTown()
{
	FuncUpEnemyUnitsInTown(0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpEnemyVillagersInTown()
{
	FuncUpEnemyVillagersInTown(0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpGaiaTypeCount(int typeOp, int resource)
{
	FuncUpGaiaTypeCount(typeOp, resource, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpGaiaTypeCountTotal(int typeOp, int resource)
{
	FuncUpGaiaTypeCountTotal(typeOp, resource, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpGroupSize(int typeOp, int groupId)
{
	FuncUpGroupSize(typeOp, groupId, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpIdleUnitCount(int idleType)
{
	FuncUpIdleUnitCount(idleType, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpObjectData(int objectData)
{
	FuncUpObjectData(objectData, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpObjectTargetData(int objectData)
{
	FuncUpObjectTargetData(objectData, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpObjectTypeCount(int typeOp, int objectId)
{
	FuncUpObjectTypeCount(typeOp, objectId, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpObjectTypeCountTotal(int typeOp, int objectId)
{
	FuncUpObjectTypeCountTotal(typeOp, objectId, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpPathDistance(int goalPoint, int strict)
{
	FuncUpPathDistance(goalPoint, strict, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpPendingObjects(int typeOp, int objectId)
{
	FuncUpPendingObjects(typeOp, objectId, 0, 0);
	return lastRelOpValue;
}

bool ExpertFact::UpPendingPlacement(int typeOp, int buildingId)
{
	return FuncUpPendingPlacement(typeOp, buildingId);
}

int ExpertFact::UpPlayerDistance(int player)
{
	FuncUpPlayerDistance(player, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpPlayersInGame(int playerStance)
{
	FuncUpPlayersInGame(playerStance, 0, 0);
	return lastRelOpValue;
}

bool ExpertFact::UpPointContains(int goalPoint, int typeOp, int objectId)
{
	return FuncUpPointContains(goalPoint, typeOp, objectId);
}

int ExpertFact::UpPointDistance(int goalPoint1, int goalPoint2)
{
	FuncUpPointDistance(goalPoint1, goalPoint2, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpPointElevation(int goalPoint)
{
	FuncUpPointElevation(goalPoint, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpPointExplored(int goalPoint)
{
	FuncUpPointExplored(goalPoint, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpPointTerrain(int goalPoint)
{
	FuncUpPointTerrain(goalPoint, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpPointZone(int goalPoint)
{
	FuncUpPointZone(goalPoint, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpProjectileDetected(int projectileType)
{
	FuncUpProjectileDetected(projectileType, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpProjectileTarget(int projectileType)
{
	FuncUpProjectileTarget(projectileType, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpRemainingBoarAmount()
{
	FuncUpRemainingBoarAmount(0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpResearchStatus(int typeOp, int techId)
{
	FuncUpResearchStatus(typeOp, techId, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpResourceAmount(int resourceAmount)
{
	FuncUpResourceAmount(resourceAmount, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpResourcePercent(int resourceAmount)
{
	FuncUpResourcePercent(resourceAmount, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpTimerStatus(int timerId)
{
	FuncUpTimerStatus(timerId, 0, 0);
	return lastRelOpValue;
}

bool ExpertFact::UpTrainSiteReady(int typeOp, int unitId)
{
	return FuncUpTrainSiteReady(typeOp, unitId);
}

int ExpertFact::UpUnitTypeInTown(int typeOp, int unitId)
{
	FuncUpUnitTypeInTown(typeOp, unitId, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpVillagerTypeInTown(int typeOp, int unitId)
{
	FuncUpVillagerTypeInTown(typeOp, unitId, 0, 0);
	return lastRelOpValue;
}

bool ExpertFact::VictoryCondition(int victoryCondition)
{
	return FuncVictoryCondition(victoryCondition);
}

int ExpertFact::WallCompletedPercentage(int perimeter)
{
	FuncWallCompletedPercentage(perimeter, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::WallInvisiblePercentage(int perimeter)
{
	FuncWallInvisiblePercentage(perimeter, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::WarboatCount()
{
	FuncWarboatCount(0, 0);
	return lastRelOpValue;
}

int ExpertFact::WoodAmount()
{
	FuncWoodAmount(0, 0);
	return lastRelOpValue;
}
