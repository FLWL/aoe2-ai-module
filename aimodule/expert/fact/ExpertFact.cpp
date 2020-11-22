#include "ExpertFact.h"

#include <iostream>

#include "misc/Statics.h"
#include "expert/action/ExpertAction.h"

void ExpertFact::UpdateAddresses()
{
	statics::SetFuncAddr(FuncBuildingAvailable, statics::TranslateAddr(expert_conf::ADDR_FUNC_BUILDING_AVAILABLE));
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
	statics::SetFuncAddr(FuncDeathMatchGame, statics::TranslateAddr(expert_conf::ADDR_FUNC_DEATH_MATCH_GAME));
	statics::SetFuncAddr(FuncDoctrine, statics::TranslateAddr(expert_conf::ADDR_FUNC_DOCTRINE));
	statics::SetFuncAddr(FuncEnemyBuildingsInTown, statics::TranslateAddr(expert_conf::ADDR_FUNC_ENEMY_BUILDINGS_IN_TOWN));
	statics::SetFuncAddr(FuncEnemyCapturedRelics, statics::TranslateAddr(expert_conf::ADDR_FUNC_ENEMY_CAPTURED_RELICS));
	statics::SetFuncAddr(FuncEventDetected, statics::TranslateAddr(expert_conf::ADDR_FUNC_EVENT_DETECTED));
	statics::SetFuncAddr(FuncFalse, statics::TranslateAddr(expert_conf::ADDR_FUNC_FALSE));
	statics::SetFuncAddr(FuncHoldKohRuin, statics::TranslateAddr(expert_conf::ADDR_FUNC_HOLD_KOH_RUIN));
	statics::SetFuncAddr(FuncHoldRelics, statics::TranslateAddr(expert_conf::ADDR_FUNC_HOLD_RELICS));
	statics::SetFuncAddr(FuncMapSize, statics::TranslateAddr(expert_conf::ADDR_FUNC_MAP_SIZE));
	statics::SetFuncAddr(FuncMapType, statics::TranslateAddr(expert_conf::ADDR_FUNC_MAP_TYPE));
	statics::SetFuncAddr(FuncPlayerComputer, statics::TranslateAddr(expert_conf::ADDR_FUNC_PLAYER_COMPUTER));
	statics::SetFuncAddr(FuncPlayerHuman, statics::TranslateAddr(expert_conf::ADDR_FUNC_PLAYER_HUMAN));
	statics::SetFuncAddr(FuncPlayerInGame, statics::TranslateAddr(expert_conf::ADDR_FUNC_PLAYER_IN_GAME));
	statics::SetFuncAddr(FuncPlayerNumber, statics::TranslateAddr(expert_conf::ADDR_FUNC_PLAYER_NUMBER));
	statics::SetFuncAddr(FuncPlayerResigned, statics::TranslateAddr(expert_conf::ADDR_FUNC_PLAYER_RESIGNED));
	statics::SetFuncAddr(FuncPlayerValid, statics::TranslateAddr(expert_conf::ADDR_FUNC_PLAYER_VALID));
	statics::SetFuncAddr(FuncPlayersAchievements, statics::TranslateAddr(expert_conf::ADDR_FUNC_PLAYERS_ACHIEVEMENTS));
	statics::SetFuncAddr(FuncPlayersCiv, statics::TranslateAddr(expert_conf::ADDR_FUNC_PLAYERS_CIV));
	statics::SetFuncAddr(FuncPlayersStance, statics::TranslateAddr(expert_conf::ADDR_FUNC_PLAYERS_STANCE));
	statics::SetFuncAddr(FuncRegicideGame, statics::TranslateAddr(expert_conf::ADDR_FUNC_REGICIDE_GAME));
	statics::SetFuncAddr(FuncResearchAvailable, statics::TranslateAddr(expert_conf::ADDR_FUNC_RESEARCH_AVAILABLE));
	statics::SetFuncAddr(FuncResearchCompleted, statics::TranslateAddr(expert_conf::ADDR_FUNC_RESEARCH_COMPLETED));
	statics::SetFuncAddr(FuncResourceFound, statics::TranslateAddr(expert_conf::ADDR_FUNC_RESOURCE_FOUND));
	statics::SetFuncAddr(FuncSharedGoal, statics::TranslateAddr(expert_conf::ADDR_FUNC_SHARED_GOAL));
	statics::SetFuncAddr(FuncSheepAndForageTooFar, statics::TranslateAddr(expert_conf::ADDR_FUNC_SHEEP_AND_FORAGE_TOO_FAR));
	statics::SetFuncAddr(FuncStanceToward, statics::TranslateAddr(expert_conf::ADDR_FUNC_STANCE_TOWARD));
	statics::SetFuncAddr(FuncTauntDetected, statics::TranslateAddr(expert_conf::ADDR_FUNC_TAUNT_DETECTED));
	statics::SetFuncAddr(FuncTimerTriggered, statics::TranslateAddr(expert_conf::ADDR_FUNC_TIMER_TRIGGERED));
	statics::SetFuncAddr(FuncTownUnderAttack, statics::TranslateAddr(expert_conf::ADDR_FUNC_TOWN_UNDER_ATTACK));
	statics::SetFuncAddr(FuncTraceFact, statics::TranslateAddr(expert_conf::ADDR_FUNC_TRACE_FACT));
	statics::SetFuncAddr(FuncTrue, statics::TranslateAddr(expert_conf::ADDR_FUNC_TRUE));
	statics::SetFuncAddr(FuncUnitAvailable, statics::TranslateAddr(expert_conf::ADDR_FUNC_UNIT_AVAILABLE));

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
#if defined GAME_DE
	statics::SetFuncAddr(FuncBuildingCountTotal, statics::TranslateAddr(expert_conf::ADDR_FUNC_BUILDING_COUNT_TOTAL));
	statics::SetFuncAddr(FuncDifficulty, statics::TranslateAddr(expert_conf::ADDR_FUNC_DIFFICULTY));
	statics::SetFuncAddr(FuncEndingAge, statics::TranslateAddr(expert_conf::ADDR_FUNC_ENDING_AGE));
	statics::SetFuncAddr(FuncFeCanBuildAtPoint, statics::TranslateAddr(expert_conf::ADDR_FUNC_FE_CAN_BUILD_AT_POINT));
	statics::SetFuncAddr(FuncFeSubGameType, statics::TranslateAddr(expert_conf::ADDR_FUNC_FE_SUB_GAME_TYPE));
	statics::SetFuncAddr(FuncGameType, statics::TranslateAddr(expert_conf::ADDR_FUNC_GAME_TYPE));
	statics::SetFuncAddr(FuncGateCount, statics::TranslateAddr(expert_conf::ADDR_FUNC_GATE_COUNT));
	statics::SetFuncAddr(FuncStartingAge, statics::TranslateAddr(expert_conf::ADDR_FUNC_STARTING_AGE));
	statics::SetFuncAddr(FuncStartingResources, statics::TranslateAddr(expert_conf::ADDR_FUNC_STARTING_RESOURCES));
	statics::SetFuncAddr(FuncStrategicNumber, statics::TranslateAddr(expert_conf::ADDR_FUNC_STRATEGIC_NUMBER));
	statics::SetFuncAddr(FuncUnitCountTotal, statics::TranslateAddr(expert_conf::ADDR_FUNC_UNIT_COUNT_TOTAL));
	statics::SetFuncAddr(FuncUpAttackerClass, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_ATTACKER_CLASS));
	statics::SetFuncAddr(FuncUpBuildingTypeInTown, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_BUILDING_TYPE_IN_TOWN));
	statics::SetFuncAddr(FuncUpCompareGoal, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_COMPARE_GOAL));
	statics::SetFuncAddr(FuncUpGaiaTypeCount, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GAIA_TYPE_COUNT));
	statics::SetFuncAddr(FuncUpGaiaTypeCountTotal, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GAIA_TYPE_COUNT_TOTAL));
#elif defined GAME_AOC
	statics::SetFuncAddr(FuncInternalGetGoal, statics::TranslateAddr(expert_conf::ADDR_FUNC_INTERNAL_GET_GOAL));
	statics::SetFuncAddr(FuncInternalGameType, statics::TranslateAddr(expert_conf::ADDR_FUNC_INTERNAL_GAME_TYPE));
	statics::SetFuncAddr(FuncInternalGetGateCount, statics::TranslateAddr(expert_conf::ADDR_FUNC_INTERNAL_GET_GATE_COUNT));
	statics::SetFuncAddr(FuncInternalStrategicNumber, statics::TranslateAddr(expert_conf::ADDR_FUNC_INTERNAL_STRATEGIC_NUMBER));
#endif
}

int ExpertFact::AttackSoldierCount()
{
	return ExpertFact::UpGetFact(14, 0);
}

int ExpertFact::AttackWarboatCount()
{
	return ExpertFact::UpGetFact(17, 0);
}

bool ExpertFact::BuildingAvailable(int buildingType)
{
	return FuncBuildingAvailable(buildingType);
}

int ExpertFact::BuildingCount()
{
	return ExpertFact::UpGetFact(27, 0);
}

int ExpertFact::BuildingCountTotal()
{
#if defined GAME_DE
	lastRelOpValue = -1;
	FuncBuildingCountTotal(0, 0);
	return lastRelOpValue;
#elif defined GAME_AOC
	return *(int16_t*)(*(int8_t**)expert_conf::ADDR_PTR_THIS_PLAYER + 0x128E);
#endif
}

int ExpertFact::BuildingTypeCount(int buildingType)
{
	return ExpertFact::UpGetFact(28, buildingType);
}

int ExpertFact::BuildingTypeCountTotal(int buildingType)
{
	return ExpertFact::UpGetFact(29, buildingType);
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

bool ExpertFact::CanBuildWall(int perimeter, int wallType)
{
	return FuncCanBuildWall(perimeter, wallType);
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
#if defined GAME_DE
	lastRelOpValue = -1;
	FuncCcPlayersBuildingCount(playerNumber, 0, 0);
	return lastRelOpValue;
#elif defined GAME_AOC
	// TODO
	return -1;
#endif
}

int ExpertFact::CcPlayersBuildingTypeCount(int playerNumber, int buildingType)
{
#if defined GAME_DE
	lastRelOpValue = -1;
	FuncCcPlayersBuildingTypeCount(playerNumber, buildingType, 0, 0);
	return lastRelOpValue;
#elif defined GAME_AOC
	// TODO
	return -1;
#endif
}

int ExpertFact::CcPlayersUnitCount(int playerNumber)
{
#if defined GAME_DE
	lastRelOpValue = -1;
	FuncCcPlayersUnitCount(playerNumber, 0, 0);
	return lastRelOpValue;
#elif defined GAME_AOC
	// TODO
	return -1;
#endif
}

int ExpertFact::CcPlayersUnitTypeCount(int playerNumber, int unitType)
{
#if defined GAME_DE
	lastRelOpValue = -1;
	FuncCcPlayersUnitTypeCount(playerNumber, unitType, 0, 0);
	return lastRelOpValue;
#elif defined GAME_AOC
	// TODO
	return -1;
#endif
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
	return ExpertFact::UpGetFact(32, 0);
}

int ExpertFact::CommodityBuyingPrice(int commodityType)
{
	return ExpertFact::UpGetFact(10, commodityType);
}

int ExpertFact::CommoditySellingPrice(int commodityType)
{
	return ExpertFact::UpGetFact(11, commodityType);
}

int ExpertFact::CurrentAge()
{
	return ExpertFact::UpGetFact(19, 0);
}

int ExpertFact::CurrentAgeTime()
{
	return ExpertFact::UpGetFact(49, 0);
}

int ExpertFact::CurrentScore()
{
	return ExpertFact::UpGetFact(20, 0);
}

bool ExpertFact::DeathMatchGame()
{
	return FuncDeathMatchGame();
}

int ExpertFact::DefendSoldierCount()
{
	return ExpertFact::UpGetFact(15, 0);
}

int ExpertFact::DefendWarboatCount()
{
	return ExpertFact::UpGetFact(18, 0);
}

int ExpertFact::Difficulty()
{
#if defined GAME_DE
	lastRelOpValue = -1;
	FuncDifficulty(0, 0);
	return lastRelOpValue;
#elif defined GAME_AOC
	return *(int32_t*)expert_conf::ADDR_VAR_DIFFICULTY;
#endif
}

bool ExpertFact::Doctrine(int value)
{
	return FuncDoctrine(value);
}

int ExpertFact::DropsiteMinDistance(int resourceType)
{
	return ExpertFact::UpGetFact(12, resourceType);
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
	return ExpertFact::UpGetFact(9, resourceType);
}

bool ExpertFact::EventDetected(int eventType, int id)
{
	return FuncEventDetected(eventType, id);
}

bool ExpertFact::False()
{
	return FuncFalse();
}

int ExpertFact::FoodAmount()
{
	return ExpertFact::UpGetFact(5, 0);
}

int ExpertFact::GameTime()
{
	return ExpertFact::UpGetFact(0, 0);
}

int ExpertFact::GameType()
{
#if defined GAME_DE
	lastRelOpValue = -1;
	FuncGameType(0, 0);
	return lastRelOpValue;
#elif defined GAME_AOC
	return FuncInternalGameType(*(void**)expert_conf::ADDR_PTR_BASE_GAME) & 0xFF;
#endif
}

int ExpertFact::GateCount(int perimeter)
{
#if defined GAME_DE
	lastRelOpValue = -1;
	FuncGateCount(perimeter, 0, 0);
	return lastRelOpValue;
#elif defined GAME_AOC
	if (perimeter != 1 && perimeter != 2)
		return 0;

	return FuncInternalGetGateCount(*(void**)expert_conf::ADDR_PTR_THIS_INFORMATION_AI, perimeter - 1);
#endif
}

int ExpertFact::Goal(int goalId)
{
#if defined GAME_DE
	lastRelOpValue = -1;
	// Call up-compare-goal instead as the usual goal fact doesn't call EvaluateRelOp
	FuncUpCompareGoal(goalId, 0, 0);
	return lastRelOpValue;
#elif defined GAME_AOC
	return FuncInternalGetGoal(*(void**)expert_conf::ADDR_PTR_THIS_INFORMATION_AI, goalId - 1);
#endif
}

std::vector<int> ExpertFact::Goals()
{
	std::vector<int> result;
	for (int i = 1; i <= 512; i++) result.push_back(Goal(i));

	return result;
}

int ExpertFact::GoldAmount()
{
	return ExpertFact::UpGetFact(8, 0);
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
	return ExpertFact::UpGetFact(3, 0);
}

int ExpertFact::IdleFarmCount()
{
	return ExpertFact::UpGetFact(4, 0);
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
	return ExpertFact::UpGetFact(31, 0);
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
	return ExpertFact::UpGetPlayerFact(playerNumber, 27, 0);
}

int ExpertFact::PlayersBuildingTypeCount(int playerNumber, int buildingType)
{
	return ExpertFact::UpGetPlayerFact(playerNumber, 28, buildingType);
}

bool ExpertFact::PlayersCiv(int playerNumber)
{
	return FuncPlayersCiv(playerNumber);
}

int ExpertFact::PlayersCivilianPopulation(int playerNumber)
{
	return ExpertFact::UpGetPlayerFact(playerNumber, 32, 0);
}

int ExpertFact::PlayersCurrentAge(int playerNumber)
{
	return ExpertFact::UpGetPlayerFact(playerNumber, 19, 0);
}

int ExpertFact::PlayersCurrentAgeTime(int playerNumber)
{
	return ExpertFact::UpGetPlayerFact(playerNumber, 50, 0);
}

int ExpertFact::PlayersMilitaryPopulation(int playerNumber)
{
	return ExpertFact::UpGetPlayerFact(playerNumber, 31, 0);
}

int ExpertFact::PlayersPopulation(int playerNumber)
{
	return ExpertFact::UpGetPlayerFact(playerNumber, 30, 0);
}

int ExpertFact::PlayersScore(int playerNumber)
{
	return ExpertFact::UpGetPlayerFact(playerNumber, 20, 0);
}

bool ExpertFact::PlayersStance(int playerNumber, int stance)
{
	return FuncPlayersStance(playerNumber, stance);
}

int ExpertFact::PlayersTribute(int playerNumber, int resourceType)
{
	return ExpertFact::UpGetPlayerFact(playerNumber, 52, resourceType);
}

int ExpertFact::PlayersTributeMemory(int playerNumber, int resourceType)
{
	return ExpertFact::UpGetPlayerFact(playerNumber, 53, resourceType);
}

int ExpertFact::PlayersUnitCount(int playerNumber)
{
	return ExpertFact::UpGetPlayerFact(playerNumber, 24, 0);
}

int ExpertFact::PlayersUnitTypeCount(int playerNumber, int unitType)
{
	return ExpertFact::UpGetPlayerFact(playerNumber, 25, unitType);
}

int ExpertFact::Population()
{
	return ExpertFact::UpGetFact(30, 0);
}

int ExpertFact::PopulationCap()
{
	return ExpertFact::UpGetFact(1, 0);
}

int ExpertFact::PopulationHeadroom()
{
	return ExpertFact::UpGetFact(2, 0);
}

int ExpertFact::RandomNumber()
{
	return ExpertFact::UpGetFact(33, 0);
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
	return ExpertFact::UpGetFact(13, 0);
}

bool ExpertFact::StanceToward(int playerNumber, int stance)
{
	return FuncStanceToward(playerNumber, stance);
}

int ExpertFact::StartingAge()
{
#if defined GAME_DE
	lastRelOpValue = -1;
	FuncStartingAge(0, 0);
	return lastRelOpValue;
#elif defined GAME_AOC
	switch (*(int*)expert_conf::ADDR_VAR_STARTING_AGE)
	{
		case 2: return 104;
		case 3: return 101;
		case 4: return 102;
		case 5: return 103;
		case 6: return 105;
	}

	return 0;
#endif
}

int ExpertFact::StartingResources()
{
#if defined GAME_DE
	lastRelOpValue = -1;
	FuncStartingResources(0, 0);
	return lastRelOpValue;
#elif defined GAME_AOC
	return *(int*)expert_conf::ADDR_VAR_STARTING_RESOURCES;
#endif
}

int ExpertFact::StoneAmount()
{
	return ExpertFact::UpGetFact(7, 0);
}

int ExpertFact::StrategicNumber(int strategicNumber)
{
#if defined GAME_DE
	lastRelOpValue = -1;
	FuncStrategicNumber(strategicNumber, 0, 0);
	return lastRelOpValue;
#elif defined GAME_AOC
	return FuncInternalStrategicNumber(*(void**)expert_conf::ADDR_PTR_THIS_TACTICAL_AI, strategicNumber);
#endif
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
	return ExpertFact::UpGetFact(23, 0);
}

int ExpertFact::UnitCountTotal()
{
#if defined GAME_DE
	lastRelOpValue = -1;
	FuncUnitCountTotal(0, 0);
	return lastRelOpValue;
#elif defined GAME_AOC
	return *(int16_t*)(*(int8_t**)expert_conf::ADDR_PTR_THIS_PLAYER + 0x128C);
#endif
}

int ExpertFact::UnitTypeCount(int unitType)
{
	return ExpertFact::UpGetFact(25, unitType);
}

int ExpertFact::UnitTypeCountTotal(int unitType)
{
	return ExpertFact::UpGetFact(26, unitType);
}

int ExpertFact::UpAlliedGoal(int computerAlly, int goalId)
{
	lastRelOpValue = -1;
	FuncUpAlliedGoal(computerAlly, goalId, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpAlliedResourceAmount(int ally, int resourceAmount)
{
	lastRelOpValue = -1;
	FuncUpAlliedResourceAmount(ally, resourceAmount, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpAlliedResourcePercent(int ally, int resourceAmount)
{
	lastRelOpValue = -1;
	FuncUpAlliedResourcePercent(ally, resourceAmount, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpAlliedSn(int computerAlly, int snId)
{
	lastRelOpValue = -1;
	FuncUpAlliedSn(computerAlly, snId, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpAttackerClass()
{
	lastRelOpValue = -1;
	FuncUpAttackerClass(0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpBuildingTypeInTown(int typeOp, int buildingId)
{
	lastRelOpValue = -1;
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
	lastRelOpValue = -1;
	FuncUpDefenderCount(0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpEnemyBuildingsInTown()
{
	lastRelOpValue = -1;
	FuncUpEnemyBuildingsInTown(0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpEnemyUnitsInTown()
{
	lastRelOpValue = -1;
	FuncUpEnemyUnitsInTown(0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpEnemyVillagersInTown()
{
	lastRelOpValue = -1;
	FuncUpEnemyVillagersInTown(0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpGaiaTypeCount(int typeOp, int resource)
{
	lastRelOpValue = -1;
	FuncUpGaiaTypeCount(typeOp, resource, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpGaiaTypeCountTotal(int typeOp, int resource)
{
	lastRelOpValue = -1;
	FuncUpGaiaTypeCountTotal(typeOp, resource, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpGetFact(int factId, int factParam)
{
	// Cache goal, read new fact into goal
	int cachedGoal = ExpertFact::Goal(512);
	ExpertAction::UpGetFact(factId, factParam, 512);
	int result = ExpertFact::Goal(512);

	// Restore goal and return result
	ExpertAction::SetGoal(512, cachedGoal);
	return result;
}

int ExpertFact::UpGetPlayerFact(int player, int factId, int param)
{
	// Cache goal, read new fact into goal
	int cachedGoal = ExpertFact::Goal(512);
	ExpertAction::UpGetPlayerFact(player, factId, param, 512);
	int result = ExpertFact::Goal(512);

	// Restore goal and return result
	ExpertAction::SetGoal(512, cachedGoal);
	return result;
}

int ExpertFact::UpGroupSize(int typeOp, int groupId)
{
	lastRelOpValue = -1;
	FuncUpGroupSize(typeOp, groupId, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpIdleUnitCount(int idleType)
{
	lastRelOpValue = -1;
	FuncUpIdleUnitCount(idleType, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpObjectData(int objectData)
{
	lastRelOpValue = -1;
	FuncUpObjectData(objectData, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpObjectTargetData(int objectData)
{
	lastRelOpValue = -1;
	FuncUpObjectTargetData(objectData, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpObjectTypeCount(int typeOp, int objectId)
{
	lastRelOpValue = -1;
	FuncUpObjectTypeCount(typeOp, objectId, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpObjectTypeCountTotal(int typeOp, int objectId)
{
	lastRelOpValue = -1;
	FuncUpObjectTypeCountTotal(typeOp, objectId, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpPathDistance(int goalPoint, int strict)
{
	lastRelOpValue = -1;
	FuncUpPathDistance(goalPoint, strict, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpPendingObjects(int typeOp, int objectId)
{
	lastRelOpValue = -1;
	FuncUpPendingObjects(typeOp, objectId, 0, 0);
	return lastRelOpValue;
}

bool ExpertFact::UpPendingPlacement(int typeOp, int buildingId)
{
	return FuncUpPendingPlacement(typeOp, buildingId);
}

int ExpertFact::UpPlayerDistance(int player)
{
	lastRelOpValue = -1;
	FuncUpPlayerDistance(player, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpPlayersInGame(int playerStance)
{
	lastRelOpValue = -1;
	FuncUpPlayersInGame(playerStance, 0, 0);
	return lastRelOpValue;
}

bool ExpertFact::UpPointContains(int goalPoint, int typeOp, int objectId)
{
	return FuncUpPointContains(goalPoint, typeOp, objectId);
}

int ExpertFact::UpPointDistance(int goalPoint1, int goalPoint2)
{
	lastRelOpValue = -1;
	FuncUpPointDistance(goalPoint1, goalPoint2, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpPointElevation(int goalPoint)
{
	lastRelOpValue = -1;
	FuncUpPointElevation(goalPoint, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpPointExplored(int goalPoint)
{
	lastRelOpValue = -1;
	FuncUpPointExplored(goalPoint, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpPointTerrain(int goalPoint)
{
	lastRelOpValue = -1;
	FuncUpPointTerrain(goalPoint, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpPointZone(int goalPoint)
{
	lastRelOpValue = -1;
	FuncUpPointZone(goalPoint, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpProjectileDetected(int projectileType)
{
	lastRelOpValue = -1;
	FuncUpProjectileDetected(projectileType, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpProjectileTarget(int projectileType)
{
	lastRelOpValue = -1;
	FuncUpProjectileTarget(projectileType, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpRemainingBoarAmount()
{
	lastRelOpValue = -1;
	FuncUpRemainingBoarAmount(0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpResearchStatus(int typeOp, int techId)
{
	lastRelOpValue = -1;
	FuncUpResearchStatus(typeOp, techId, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpResourceAmount(int resourceAmount)
{
	lastRelOpValue = -1;
	FuncUpResourceAmount(resourceAmount, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpResourcePercent(int resourceAmount)
{
	lastRelOpValue = -1;
	FuncUpResourcePercent(resourceAmount, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpTimerStatus(int timerId)
{
	lastRelOpValue = -1;
	FuncUpTimerStatus(timerId, 0, 0);
	return lastRelOpValue;
}

bool ExpertFact::UpTrainSiteReady(int typeOp, int unitId)
{
	return FuncUpTrainSiteReady(typeOp, unitId);
}

int ExpertFact::UpUnitTypeInTown(int typeOp, int unitId)
{
	lastRelOpValue = -1;
	FuncUpUnitTypeInTown(typeOp, unitId, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpVillagerTypeInTown(int typeOp, int unitId)
{
	lastRelOpValue = -1;
	FuncUpVillagerTypeInTown(typeOp, unitId, 0, 0);
	return lastRelOpValue;
}

bool ExpertFact::VictoryCondition(int victoryCondition)
{
	return FuncVictoryCondition(victoryCondition);
}

int ExpertFact::WallCompletedPercentage(int perimeter)
{
#if defined GAME_DE
	lastRelOpValue = -1;
	FuncWallCompletedPercentage(perimeter, 0, 0);
	return lastRelOpValue;
#elif defined GAME_AOC
	return -1;
#endif
}

int ExpertFact::WallInvisiblePercentage(int perimeter)
{
#if defined GAME_DE
	lastRelOpValue = -1;
	FuncWallInvisiblePercentage(perimeter, 0, 0);
	return lastRelOpValue;
#elif defined GAME_AOC
	return -1;
#endif
}

int ExpertFact::WarboatCount()
{
	return ExpertFact::UpGetFact(16, 0);
}

int ExpertFact::WoodAmount()
{
	return ExpertFact::UpGetFact(6, 0);
}

#if defined GAME_DE
int ExpertFact::EndingAge()
{
	lastRelOpValue = -1;
	FuncEndingAge(0, 0);
	return lastRelOpValue;
}

bool ExpertFact::FeCanBuildAtPoint(int param1, int param2, int param3, int param4)
{
	return FuncFeCanBuildAtPoint(param1, param2, param3, param4);
}

int ExpertFact::FeSubGameType()
{
	lastRelOpValue = -1;
	FuncFeSubGameType(0, 0);
	return lastRelOpValue;
}
#elif defined GAME_AOC

#endif
