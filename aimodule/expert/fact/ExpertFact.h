#pragma once
#include <array>
#include <string>
#include <unordered_map>
#include <vector>
#include <stdint.h>

#include "misc/Configuration.h"
#include "structs/world/ai_expert/AIExpert.h"

class ExpertFact
{
public:
	~ExpertFact();
	static void Initialize(const structs::AIExpert* aiExpert);

	// facts
	static int AttackSoldierCount();
	static int AttackWarboatCount();
	static bool BuildingAvailable(int buildingType);
	static int BuildingCount();
	static int BuildingCountTotal();
	static int BuildingTypeCount(int buildingType);
	static int BuildingTypeCountTotal(int buildingType);
	static bool CanAffordBuilding(int buildingType);
	static bool CanAffordCompleteWall(int perimeter, int wallType);
	static bool CanAffordResearch(int researchType);
	static bool CanAffordUnit(int unitType);
	static bool CanBuild(int buildingType);
	static bool CanBuildGate(int perimeter);
	static bool CanBuildGateWithEscrow(int perimeter);
	static bool CanBuildWall(int perimeter, int wallType);
	static bool CanBuildWallWithEscrow(int perimeter, int wallType);
	static bool CanBuildWithEscrow(int buildingType);
	static bool CanBuyCommodity(int commodityType);
	static bool CanResearch(int researchType);
	static bool CanResearchWithEscrow(int researchType);
	static bool CanSellCommodity(int commodityType);
	static bool CanSpy();
	static bool CanSpyWithEscrow();
	static bool CanTrain(int unitType);
	static bool CanTrainWithEscrow(int unitType);
	static int CcPlayersBuildingCount(int playerNumber);
	static int CcPlayersBuildingTypeCount(int playerNumber, int buildingType);
	static int CcPlayersUnitCount(int playerNumber);
	static int CcPlayersUnitTypeCount(int playerNumber, int unitType);
	static bool CheatsEnabled();
	static int CivSelected();
	static int CivilianPopulation();
	static int CommodityBuyingPrice(int commodityType);
	static int CommoditySellingPrice(int commodityType);
	static int CurrentAge();
	static int CurrentAgeTime();
	static int CurrentScore();
	static bool DeathMatchGame();
	static int DefendSoldierCount();
	static int DefendWarboatCount();
	static int Difficulty();
	static bool Doctrine(int value);
	static int DropsiteMinDistance(int resourceType);
	static bool EnemyBuildingsInTown();
	static bool EnemyCapturedRelics();
	static int EscrowAmount(int resourceType);
	static bool EventDetected(int eventType, int id);
	static bool False();
	static int FoodAmount();
	static int GameTime();
	static int GameType();
	static int GateCount(int perimeter);
	static int Goal(int goalId);
	static std::vector<int> GoalList();
	static int GoldAmount();
	static bool HoldKohRuin();
	static bool HoldRelics();
	static int HousingHeadroom();
	static int IdleFarmCount();
	static int MapSize();
	static int MapType();
	static int MilitaryPopulation();
	static bool PlayerComputer(int playerNumber);
	static bool PlayerHuman(int playerNumber);
	static bool PlayerInGame(int playerNumber);
	static bool PlayerNumber(int playerNumber);
	static bool PlayerResigned(int playerNumber);
	static bool PlayerValid(int playerNumber);
	static bool PlayersAchievements(int param1, int param2, int param3, int param4);
	static int PlayersBuildingCount(int playerNumber);
	static int PlayersBuildingTypeCount(int playerNumber, int buildingType);
	static bool PlayersCiv(int playerNumber);
	static int PlayersCivilianPopulation(int playerNumber);
	static int PlayersCurrentAge(int playerNumber);
	static int PlayersCurrentAgeTime(int playerNumber);
	static int PlayersMilitaryPopulation(int playerNumber);
	static int PlayersPopulation(int playerNumber);
	static int PlayersScore(int playerNumber);
	static bool PlayersStance(int playerNumber, int stance);
	static int PlayersTribute(int playerNumber, int resourceType);
	static int PlayersTributeMemory(int playerNumber, int resourceType);
	static int PlayersUnitCount(int playerNumber);
	static int PlayersUnitTypeCount(int playerNumber, int unitType);
	static int Population();
	static int PopulationCap();
	static int PopulationHeadroom();
	static int RandomNumber();
	static bool RegicideGame();
	static bool ResearchAvailable(int researchType);
	static bool ResearchCompleted(int researchType);
	static bool ResourceFound(int resourceType);
	static bool SharedGoal(int goalId, int value);
	static bool SheepAndForageTooFar();
	static int SoldierCount();
	static bool StanceToward(int playerNumber, int stance);
	static int StartingAge();
	static int StartingResources();
	static int StoneAmount();
	static int StrategicNumber(int strategicNumber);
	static std::vector<int> StrategicNumberList();
	static bool TauntDetected(int playerNumber, int tauntId);
	static bool TimerTriggered(int timerId);
	static bool TownUnderAttack();
	static bool TraceFact(int param);
	static bool True();
	static bool UnitAvailable(int unitType);
	static int UnitCount();
	static int UnitCountTotal();
	static int UnitTypeCount(int unitType);
	static int UnitTypeCountTotal(int unitType);
	static int UpAlliedGoal(int computerAlly, int goalId);
	static int UpAlliedResourceAmount(int ally, int resourceAmount);
	static int UpAlliedResourcePercent(int ally, int resourceAmount);
	static int UpAlliedSn(int computerAlly, int snId);
	static int UpAttackerClass();
	static int UpBuildingTypeInTown(int typeOp, int buildingId);
	static bool UpCanBuild(int escrowState, int typeOp, int buildingId);
	static bool UpCanBuildLine(int escrowState, int goalPoint, int typeOp, int buildingId);
	static bool UpCanResearch(int escrowState, int typeOp, int techId);
	static bool UpCanSearch(int searchSource);
	static bool UpCanTrain(int escrowState, int typeOp, int unitId);
	static int UpDefenderCount();
	static int UpEnemyBuildingsInTown();
	static int UpEnemyUnitsInTown();
	static int UpEnemyVillagersInTown();
	static int UpGaiaTypeCount(int resource);
	static int UpGaiaTypeCountTotal(int resource);
	static int UpGetFact(int factId, int factParam);
	static int UpGetPlayerFact(int player, int factId, int param);
	static std::array<int, 4> UpGetSearchState();
	static int UpGroupSize(int typeOp, int groupId);
	static int UpIdleUnitCount(int idleType);
	static int UpObjectData(int objectData);
	static std::vector<int> UpObjectDataList();
	static int UpObjectTargetData(int objectData);
	static int UpObjectTypeCount(int typeOp, int objectId);
	static int UpObjectTypeCountTotal(int typeOp, int objectId);
	static int UpPathDistance(int goalPoint, int strict);
	static int UpPendingObjects(int typeOp, int objectId);
	static bool UpPendingPlacement(int typeOp, int buildingId);
	static int UpPlayerDistance(int player);
	static int UpPlayersInGame(int playerStance);
	static bool UpPointContains(int goalPoint, int typeOp, int objectId);
	static int UpPointDistance(int goalPoint1, int goalPoint2);
	static int UpPointElevation(int goalPoint);
	static int UpPointExplored(int goalPoint);
	static int UpPointTerrain(int goalPoint);
	static int UpPointZone(int goalPoint);
	static int UpProjectileDetected(int projectileType);
	static int UpProjectileTarget(int projectileType);
	static int UpRemainingBoarAmount();
	static int UpResearchStatus(int typeOp, int techId);
	static int UpResourceAmount(int resourceAmount);
	static int UpResourcePercent(int resourceAmount);
	static std::vector<int> UpSearchObjectIdList(int searchSource);
	static int UpTimerStatus(int timerId);
	static bool UpTrainSiteReady(int typeOp, int unitId);
	static int UpUnitTypeInTown(int typeOp, int unitId);
	static int UpVillagerTypeInTown(int typeOp, int unitId);
	static bool VictoryCondition(int victoryCondition);
	static int WallCompletedPercentage(int perimeter);
	static int WallInvisiblePercentage(int perimeter);
	static int WarboatCount();
	static int WoodAmount();
	// DE-only facts
	static int EndingAge();
	static bool FeCanBuildAtPoint(int param1, int param2, int param3, int param4);
	static int FeSubGameType();
	// custom facts
	static std::array<int, 2> ModMapDimensions();
	static int ModPointVisibility(int inConstPointX, int inConstPointY, int mapWidth = 0, int mapHeight = 0);

	inline static int lastRelOpValue = -1;

private:
	static void LoadFactFunctions(const structs::AIExpert* aiExpert);
	static void ClearFactFunctions();
	static void UpdateAddresses();
	static void EnableDetours();
	static void DisableDetours();

	struct FactFunction
	{
		uintptr_t address;
		int argc;
	};
	inline static std::unordered_map<std::string, FactFunction*> factFunctionMap;
	static int ExecuteFactFunction(const FactFunction& factFunction, const int arg1 = 0, const int arg2 = 0, const int arg3 = 0, const int arg4 = 0);

#if defined GAME_DE
	static int64_t DetouredEvaluateRelOp(int relOp, int arg1, int arg2, char a4, char a5);
	inline static int64_t(*FuncEvaluateRelOp)(int relOp, int arg1, int arg2, char a4, char a5) = 0;
#elif defined GAME_AOC
	inline static intptr_t(__thiscall* FuncInternalGameType)(void* baseGame) = 0;
	inline static intptr_t(__thiscall* FuncInternalGetGateCount)(void* informationAI, int perimeter) = 0;
	inline static intptr_t(__thiscall* FuncInternalStrategicNumber)(void* tacticalAI, int snId) = 0;
	inline static intptr_t(__thiscall* FuncInternalWallCompletedPercentage)(void* informationAI, int perimeter) = 0;
	inline static intptr_t(__thiscall* FuncInternalWallInvisiblePercentage)(void* informationAI, int perimeter) = 0;
#endif

	static void ChangeTypeOpToConst(int& typeOp, int& opValue);
};
