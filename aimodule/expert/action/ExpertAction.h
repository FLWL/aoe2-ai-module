#pragma once
#include <string>
#include <unordered_map>
#include <stdint.h>

#include "misc/Configuration.h"
#include "structs/world/ai_expert/AIExpert.h"

class ExpertAction
{
public:
	~ExpertAction();
	static void Initialize(const structs::AIExpert* aiExpert);

	// actions
	static void AcknowledgeEvent(int eventType, int eventId);
	static void AcknowledgeTaunt(int anyPlayer, int tauntId);
	static void AttackNow();
	static void Build(int buildingId);
	static void BuildForward(int buildingId);
	static void BuildGate(int perimeter);
	static void BuildWall(int perimeter, int wallId);
	static void BuyCommodity(int commodity);
	static void CcAddResource(int resource, int value);
	static void ChatLocal(const std::string& inTextString);
	static void ChatLocalUsingId(int stringId);
	static void ChatLocalUsingRange(int stringIdStart, int stringIdRange);
	static void ChatLocalToSelf(const std::string& inTextString);
	static void ChatToAll(const std::string& inTextString);
	static void ChatToAllUsingId(int stringId);
	static void ChatToAllUsingRange(int stringIdStart, int stringIdRange);
	static void ChatToAllies(const std::string& inTextString);
	static void ChatToAlliesUsingId(int stringId);
	static void ChatToAlliesUsingRange(int stringIdStart, int stringIdRange);
	static void ChatToEnemies(const std::string& inTextString);
	static void ChatToEnemiesUsingId(int stringId);
	static void ChatToEnemiesUsingRange(int stringIdStart, int stringIdRange);
	static void ChatToPlayer(int playerNumber, const std::string& inTextString);
	static void ChatToPlayerUsingId(int playerNumber, int stringId);
	static void ChatToPlayerUsingRange(int playerNumber, int stringIdStart, int stringIdRange);
	static void ChatTrace(int traceNumber);
	static void ClearTributeMemory(int playerNumber, int resourceType);
	static void DeleteBuilding(int buildingType);
	static void DeleteUnit(int unitType);
	static void DisableRule(int groupId);
	static void DisableSelf();
	static void DisableTimer(int timerId);
	static void DoNothing();
	static void EnableRule(int groupId);
	static void EnableTimer(int timerId, int timeInterval);
	static void EnableWallPlacement(int perimeter);
	static void GenerateRandomNumber(int range);
	static void Log(const std::string& inTextString);
	static void LogTrace(int traceNumber);
	static void ReleaseEscrow(int resourceType);
	static void Research(int researchType);
	static void Resign();
	static void SellCommodity(int commodityType);
	static void SetAuthorName(const std::string& inTextString);
	static void SetAuthorEmail(const std::string& inTextString);
	static void SetAuthorVersion(const std::string& inTextString);
	static void SetDifficultyParameter(int difficultyParameter, int value);
	static void SetDoctrine(int doctrine);
	static void SetEscrowPercentage(int resourceType, int percentage);
	static void SetGoal(int goalId, int goalValue);
	static void SetSharedGoal(int goalId, int goal);
	static void SetSignal(int signalId);
	static void SetStance(int playerNumber, int stance);
	static void SetStrategicNumber(int strategicNumber, int value);
	static void Spy();
	static void Taunt(int tauntNumber);
	static void TauntUsingRange(int tauntIdStart, int tauntIdRange);
	static void Train(int unitType);
	static void TributeToPlayer(int playerNumber, int resourceType, int tributeAmount);
	static void UpAddCostData(int goalId, int typeOp, int opValue);
	static void UpAddObjectById(int searchSource, int typeOp, int opId);
	static void UpAddObjectCost(int typeOp1, int objectId, int typeOp2, int value);
	static void UpAddPoint(int goalPoint1, int goalPoint2, int typeOp, int count);
	static void UpAddResearchCost(int typeOp1, int techId, int typeOp2, int value);
	static void UpAssignBuilders(int typeOp1, int buildingId, int typeOp2, int value);
	static void UpBoundPoint(int outGoalPoint, int inGoalPoint);
	static void UpBoundPrecisePoint(int goalPoint, int precise, int typeOp, int border);
	static void UpBuild(int placementType, int escrowState, int typeOp, int buildingId);
	static void UpBuildLine(int goalPoint1, int goalPoint2, int typeOp, int buildingId);
	static void UpBuyCommodity(int typeOp1, int resourceAmount, int typeOp2, int value);
	static void UpCcAddResource(int typeOp1, int resourceAmount, int typeOp2, int value);
	static void UpCcSendCheat(const std::string& inTextCode);
	static void UpChangeName(const std::string& inTextNewName);
	static void UpChatDataToAll(const std::string& inTextFormattedString, int typeOp, int value);
	static void UpChatDataToPlayer(int player, const std::string& inTextFormattedString, int typeOp, int value);
	static void UpChatDataToSelf(const std::string& inTextFormattedString, int typeOp, int value);
	static void UpCleanSearch(int searchSource, int objectData, int searchOrder);
	static void UpCopyPoint(int goalPoint1, int goalPoint2);
	static void UpCreateGroup(int goalIndex, int goalCount, int typeOp, int groupId);
	static void UpCrossTiles(int goalPoint1, int goalPoint2, int typeOp, int tiles);
	static void UpDeleteDistantFarms(int typeOp, int value);
	static void UpDeleteIdleUnits(int idleType);
	static void UpDeleteObjects(int typeOp1, int unitId, int typeOp2, int hitpoints);
	static void UpDisbandGroupType(int groupType);
	static void UpDropResources(int resource, int typeOp, int value);
	static void UpFilterDistance(int typeOp1, int minDistance, int typeOp2, int maxDistance);
	static void UpFilterExclude(int cmdId, int actionId, int orderId, int classId);
	static void UpFilterGarrison(int typeOp1, int minGarrison, int typeOp2, int maxGarrison);
	static void UpFilterInclude(int cmdId, int actionId, int orderId, int onMainland);
	static void UpFilterRange(int minGarrison, int maxGarrison, int minDistance, int maxDistance);
	static void UpFilterStatus(int typeOp1, int objectStatus, int typeOp2, int objectList);
	static void UpFindFlare(int goalPoint);
	static void UpFindLocal(int typeOp1, int unitId, int typeOp2, int count);
	static void UpFindNextPlayer(int playerStance, int findPlayerMethod, int goalPlayerId);
	static void UpFindPlayer(int playerStance, int findPlayerMethod, int goalPlayerId);
	static void UpFindPlayerFlare(int player, int goalPoint);
	static void UpFindRemote(int typeOp1, int unitId, int typeOp2, int count);
	static void UpFindResource(int typeOp1, int resource, int typeOp2, int count);
	static void UpFindStatusLocal(int typeOp1, int unitId, int typeOp2, int count);
	static void UpFindStatusRemote(int typeOp1, int unitId, int typeOp2, int count);
	static void UpFullResetSearch();
	static void UpGarrison(int objectId, int typeOp, int unitId);
	static void UpGatherInside(int typeOp1, int buildingId, int typeOp2, int state);
	static void UpGetAttackerClass(int goalSourceClass);
	static void UpGetCostDelta(int goalId);
	static void UpGetEvent(int typeOp, int eventId, int goalValue);
	static void UpGetFact(int factId, int factParam, int goalId);
	static void UpGetFactMax(int player, int factId, int param, int goalData);
	static void UpGetFactMin(int player, int factId, int param, int goalData);
	static void UpGetFactSum(int player, int factId, int param, int goalData);
	static void UpGetFocusFact(int factId, int param, int goalData);
	static void UpGetGroupSize(int typeOp, int groupId, int goalSize);
	static void UpGetIndirectGoal(int typeOp1, int goalId, int goalValue);
	static void UpGetObjectData(int objectData, int goalData);
	static void UpGetObjectTargetData(int objectData, int goalData);
	static void UpGetObjectTypeData(int typeOp, int objectTypeId, int objectData, int goalData);
	static void UpGetPathDistance(int goalPoint, int strict, int goalData);
	static void UpGetPlayerColor(int player, int goalColorId);
	static void UpGetPlayerFact(int player, int factId, int param, int goalData);
	static void UpGetPoint(int positionType, int goalPoint);
	static void UpGetPointContains(int goalPoint, int goalId, int typeOp, int objectId);
	static void UpGetPointDistance(int goalPoint1, int goalPoint2, int goalDistance);
	static void UpGetPointElevation(int goalPoint, int goalData);
	static void UpGetPointTerrain(int goalPoint, int goalTerrain);
	static void UpGetPointZone(int goalPoint, int goalData);
	static void UpGetPreciseTime(int goalStart, int goalTime);
	static void UpGetProjectilePlayer(int projectileType, int goalPlayerId);
	static void UpGetRuleId(int goalRuleId);
	static void UpGetSearchState(int goalState);
	static void UpGetSharedGoal(int typeOp, int sharedGoalId, int goalValue);
	static void UpGetSignal(int typeOp, int signalId, int goalValue);
	static void UpGetTargetFact(int factId, int param, int goalData);
	static void UpGetThreatData(int goalElapsedTime, int goalPlayerId, int goalSourceClass, int goalTargetClass);
	static void UpGetTimer(int typeOp, int timerId, int goalValue);
	static void UpGetVictoryData(int goalPlayerId, int goalType, int goalTime);
	static void UpGetVictoryLimit(int goalLimit);
	static void UpGuardUnit(int objectId, int typeOp, int unitId);
	static void UpJumpDirect(int typeOp, int ruleId);
	static void UpJumpDynamic(int typeOp, int ruleDelta);
	static void UpJumpRule(int ruleDelta);
	static void UpLerpPercent(int goalPoint1, int goalPoint2, int typeOp, int percent);
	static void UpLerpTiles(int goalPoint1, int goalPoint2, int typeOp, int tiles);
	static void UpLogData(int plain, const std::string& inTextFormattedString, int typeOp, int value);
	static void UpModifyEscrow(int resource, int mathOp, int value);
	static void UpModifyFlag(int goalId, int mathOp, int value);
	static void UpModifyGoal(int goalId, int mathOp, int value);
	static void UpModifyGroupFlag(int on, int typeOp, int groupId);
	static void UpModifySn(int snId, int mathOp, int value);
	static void UpReleaseEscrow();
	static void UpRemoveObjects(int searchSource, int objectData, int typeOp, int value);
	static void UpRequestHunters(int typeOp, int value);
	static void UpResearch(int escrowState, int typeOp, int techId);
	static void UpResetAttackNow();
	static void UpResetBuilding(int preserveResearch, int typeOp, int buildingId);
	static void UpResetCostData(int goalId);
	static void UpResetFilters();
	static void UpResetGroup(int typeOp, int groupId);
	static void UpResetPlacement(int typeOp, int buildingId);
	static void UpResetScouts();
	static void UpResetSearch(int localIndex, int localList, int remoteIndex, int remoteList);
	static void UpResetTargetPriorities(int priorityType, int mode);
	static void UpResetUnit(int typeOp, int unitId);
	static void UpRetaskGatherers(int resource, int typeOp, int value);
	static void UpRetreatNow();
	static void UpRetreatTo(int objectId, int typeOp, int unitId);
	static void UpSellCommodity(int typeOp1, int resourceAmount, int typeOp2, int value);
	static void UpSendFlare(int goalPoint);
	static void UpSendScout(int groupType, int positionType);
	static void UpSetAttackStance(int unitId, int typeOp, int attackStance);
	static void UpSetDefensePriority(int typeOp1, int buildingId, int typeOp2, int value);
	static void UpSetEvent(int typeOp1, int eventId, int typeOp2, int value);
	static void UpSetGroup(int searchSource, int typeOp, int groupId);
	static void UpSetIndirectGoal(int typeOp1, int goalId, int typeOp2, int value);
	static void UpSetOffensePriority(int typeOp1, int objectId, int typeOp2, int value);
	static void UpSetPlacementData(int playerAlly, int objectId, int typeOp, int value);
	static void UpSetPreciseTargetPoint(int goalPoint);
	static void UpSetSharedGoal(int typeOp1, int sharedGoalId, int typeOp2, int value);
	static void UpSetSignal(int typeOp1, int signalId, int typeOp2, int value);
	static void UpSetTargetById(int typeOp, int id);
	static void UpSetTargetObject(int searchSource, int typeOp, int index);
	static void UpSetTargetPoint(int goalPoint);
	static void UpSetTimer(int typeOp1, int timerId, int typeOp2, int value);
	static void UpSetupCostData(int resetCost, int goalId);
	static void UpStoreMapName(int extension);
	static void UpStoreObjectName();
	static void UpStorePlayerChat(int player);
	static void UpStorePlayerName(int player);
	static void UpStoreTechName(int typeOp, int techId);
	static void UpStoreText(int typeOp, int languageId);
	static void UpStoreTypeName(int typeOp, int objectTypeId);
	static void UpTargetObjects(int target, int action, int formation, int attackStance);
	static void UpTargetPoint(int goalPoint, int action, int formation, int attackStance);
	static void UpTrain(int escrowState, int typeOp, int unitId);
	static void UpTributeToPlayer(int player, int resourceAmount, int typeOp, int value);
	static void UpUngarrison(int typeOp, int objectId);
	static void UpUpdateTargets();
	// DE-only actions
	static void ChatDebug(const std::string& inTextString);
	static void FeBreakPoint(int param1, int param2, int param3, int param4);
	static void SkyboxClearSignal(int param);
	static void SkyboxSetNameMode(int param);
	static void UpChatDataToAllUsingId(int param1, int stringId, int param3);
	static void UpChatDataToPlayerUsingId(int stringId, int playerId, int param3, int param4);
	static void UpGetTreatyData(int param);
	static void UpTestharnessReport(int param1, int param2, int param3);
	static void UpTestharnessTest(int param1, int param2, int param3, int param4);
	// AOC-only actions
	static void UpGetAlliedTarget(int param1, int param2);
	static void UpGetGuardState(int goalState);
	static void UpGetUpgradeId(int player, int count, int goalTypeId, int goalUpgradeId);
	static void UpOutOfSync();

private:
	static void LoadActionFunctions(const structs::AIExpert* aiExpert);
	static void ClearActionFunctions();
	static void UpdateAddresses();
	static void EnableDetours();
	static void DisableDetours();

	struct ActionFunction
	{
		uintptr_t address;
		int argc;
	};
	inline static std::unordered_map<std::string, ActionFunction*> actionFunctionMap;
	static void ExecuteActionFunction(const ActionFunction& actionFunction, const int arg1 = 0, const int arg2 = 0, const int arg3 = 0, const int arg4 = 0);

#if defined GAME_DE
	static char* DetouredGetString(void* aiExpertEngine, int stringId);
	inline static char* (*FuncGetString)(void* aiExpertEngine, int stringId) = 0;
#elif defined GAME_AOC
	static char* __fastcall DetouredGetString(void* aiExpertEngine, void* unused, int stringId);
	inline static char* (__thiscall* FuncGetString)(void* aiExpertEngine, int stringId) = 0;
#endif

	static void SetCustomString(const std::string& inTextString);
	inline static char customString[256] = { };
};
