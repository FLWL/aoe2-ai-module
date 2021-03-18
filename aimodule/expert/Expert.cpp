#include "Expert.h"

#include <algorithm>
#include <iostream>
#include <sstream>
#include <chrono>

#include <detours/detours.h>

#include "AIModule.h"
#include "misc/Statics.h"
#include "misc/MemoryUtils.h"
#include "expert/action/ExpertActionHandler.h"
#include "expert/command/ExpertCommandHandler.h"
#include "expert/fact/ExpertFactHandler.h"
#include "google/protobuf/dynamic_message.h"

Expert* Expert::instance;

Expert::Expert(AIModule* aiModule) :
	aiModule(aiModule),
	expertService(this),
	commandQueue(),
	expertAction(),
	expertFact()
{
	instance = this;
	factsAndActionsInitialized = false;
	
	UpdateAddresses();
	PopulateCommandMap();
	EnableDetours();
}

void Expert::UpdateAddresses()
{
#if defined GAME_DE
	statics::SetFuncAddr(FuncRunList, memory_utils::FindPatternInGameModule(expert_conf::SIG_FUNC_RUN_LIST));
#elif defined GAME_AOC
	statics::SetFuncAddr(FuncRunList, statics::TranslateAddr(expert_conf::ADDR_FUNC_RUN_LIST));
#endif
}

void Expert::PopulateCommandMap()
{
	// actions
	commandMap.insert({ "type.googleapis.com/protos.expert.action.AcknowledgeEvent", &ExpertActionHandler::AcknowledgeEvent });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.AcknowledgeTaunt", &ExpertActionHandler::AcknowledgeTaunt });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.AttackNow", &ExpertActionHandler::AttackNow });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.Build", &ExpertActionHandler::Build });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.BuildForward", &ExpertActionHandler::BuildForward });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.BuildGate", &ExpertActionHandler::BuildGate });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.BuildWall", &ExpertActionHandler::BuildWall });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.BuyCommodity", &ExpertActionHandler::BuyCommodity });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.CcAddResource", &ExpertActionHandler::CcAddResource });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.ChatLocal", &ExpertActionHandler::ChatLocal });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.ChatLocalUsingId", &ExpertActionHandler::ChatLocalUsingId });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.ChatLocalUsingRange", &ExpertActionHandler::ChatLocalUsingRange });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.ChatLocalToSelf", &ExpertActionHandler::ChatLocalToSelf });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.ChatToAll", &ExpertActionHandler::ChatToAll });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.ChatToAllUsingId", &ExpertActionHandler::ChatToAllUsingId });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.ChatToAllUsingRange", &ExpertActionHandler::ChatToAllUsingRange });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.ChatToAllies", &ExpertActionHandler::ChatToAllies });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.ChatToAlliesUsingId", &ExpertActionHandler::ChatToAlliesUsingId });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.ChatToAlliesUsingRange", &ExpertActionHandler::ChatToAlliesUsingRange });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.ChatToEnemies", &ExpertActionHandler::ChatToEnemies });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.ChatToEnemiesUsingId", &ExpertActionHandler::ChatToEnemiesUsingId });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.ChatToEnemiesUsingRange", &ExpertActionHandler::ChatToEnemiesUsingRange });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.ChatToPlayer", &ExpertActionHandler::ChatToPlayer });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.ChatToPlayerUsingId", &ExpertActionHandler::ChatToPlayerUsingId });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.ChatToPlayerUsingRange", &ExpertActionHandler::ChatToPlayerUsingRange });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.ChatTrace", &ExpertActionHandler::ChatTrace });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.ClearTributeMemory", &ExpertActionHandler::ClearTributeMemory });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.DeleteBuilding", &ExpertActionHandler::DeleteBuilding });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.DeleteUnit", &ExpertActionHandler::DeleteUnit });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.DisableRule", &ExpertActionHandler::DisableRule });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.DisableSelf", &ExpertActionHandler::DisableSelf });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.DisableTimer", &ExpertActionHandler::DisableTimer });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.DoNothing", &ExpertActionHandler::DoNothing });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.EnableRule", &ExpertActionHandler::EnableRule });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.EnableTimer", &ExpertActionHandler::EnableTimer });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.EnableWallPlacement", &ExpertActionHandler::EnableWallPlacement });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.GenerateRandomNumber", &ExpertActionHandler::GenerateRandomNumber });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.Log", &ExpertActionHandler::Log });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.LogTrace", &ExpertActionHandler::LogTrace });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.ReleaseEscrow", &ExpertActionHandler::ReleaseEscrow });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.Research", &ExpertActionHandler::Research });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.Resign", &ExpertActionHandler::Resign });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.SellCommodity", &ExpertActionHandler::SellCommodity });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.SetAuthorName", &ExpertActionHandler::SetAuthorName });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.SetAuthorEmail", &ExpertActionHandler::SetAuthorEmail });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.SetAuthorVersion", &ExpertActionHandler::SetAuthorVersion });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.SetDifficultyParameter", &ExpertActionHandler::SetDifficultyParameter });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.SetDoctrine", &ExpertActionHandler::SetDoctrine });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.SetEscrowPercentage", &ExpertActionHandler::SetEscrowPercentage });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.SetGoal", &ExpertActionHandler::SetGoal });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.SetSharedGoal", &ExpertActionHandler::SetSharedGoal });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.SetSignal", &ExpertActionHandler::SetSignal });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.SetStance", &ExpertActionHandler::SetStance });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.SetStrategicNumber", &ExpertActionHandler::SetStrategicNumber });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.Spy", &ExpertActionHandler::Spy });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.Taunt", &ExpertActionHandler::Taunt });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.TauntUsingRange", &ExpertActionHandler::TauntUsingRange });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.Train", &ExpertActionHandler::Train });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.TributeToPlayer", &ExpertActionHandler::TributeToPlayer });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpAddCostData", &ExpertActionHandler::UpAddCostData });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpAddObjectById", &ExpertActionHandler::UpAddObjectById });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpAddObjectCost", &ExpertActionHandler::UpAddObjectCost });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpAddPoint", &ExpertActionHandler::UpAddPoint });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpAddResearchCost", &ExpertActionHandler::UpAddResearchCost });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpAssignBuilders", &ExpertActionHandler::UpAssignBuilders });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpBoundPoint", &ExpertActionHandler::UpBoundPoint });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpBoundPrecisePoint", &ExpertActionHandler::UpBoundPrecisePoint });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpBuild", &ExpertActionHandler::UpBuild });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpBuildLine", &ExpertActionHandler::UpBuildLine });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpBuyCommodity", &ExpertActionHandler::UpBuyCommodity });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpCcAddResource", &ExpertActionHandler::UpCcAddResource });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpCcSendCheat", &ExpertActionHandler::UpCcSendCheat });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpChangeName", &ExpertActionHandler::UpChangeName });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpChatDataToAll", &ExpertActionHandler::UpChatDataToAll });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpChatDataToPlayer", &ExpertActionHandler::UpChatDataToPlayer });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpChatDataToSelf", &ExpertActionHandler::UpChatDataToSelf });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpCleanSearch", &ExpertActionHandler::UpCleanSearch });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpCopyPoint", &ExpertActionHandler::UpCopyPoint });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpCreateGroup", &ExpertActionHandler::UpCreateGroup });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpCrossTiles", &ExpertActionHandler::UpCrossTiles });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpDeleteDistantFarms", &ExpertActionHandler::UpDeleteDistantFarms });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpDeleteIdleUnits", &ExpertActionHandler::UpDeleteIdleUnits });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpDeleteObjects", &ExpertActionHandler::UpDeleteObjects });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpDisbandGroupType", &ExpertActionHandler::UpDisbandGroupType });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpDropResources", &ExpertActionHandler::UpDropResources });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpFilterDistance", &ExpertActionHandler::UpFilterDistance });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpFilterExclude", &ExpertActionHandler::UpFilterExclude });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpFilterGarrison", &ExpertActionHandler::UpFilterGarrison });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpFilterInclude", &ExpertActionHandler::UpFilterInclude });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpFilterRange", &ExpertActionHandler::UpFilterRange });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpFilterStatus", &ExpertActionHandler::UpFilterStatus });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpFindFlare", &ExpertActionHandler::UpFindFlare });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpFindLocal", &ExpertActionHandler::UpFindLocal });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpFindNextPlayer", &ExpertActionHandler::UpFindNextPlayer });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpFindPlayer", &ExpertActionHandler::UpFindPlayer });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpFindPlayerFlare", &ExpertActionHandler::UpFindPlayerFlare });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpFindRemote", &ExpertActionHandler::UpFindRemote });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpFindResource", &ExpertActionHandler::UpFindResource });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpFindStatusLocal", &ExpertActionHandler::UpFindStatusLocal });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpFindStatusRemote", &ExpertActionHandler::UpFindStatusRemote });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpFullResetSearch", &ExpertActionHandler::UpFullResetSearch });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGarrison", &ExpertActionHandler::UpGarrison });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGatherInside", &ExpertActionHandler::UpGatherInside });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetAttackerClass", &ExpertActionHandler::UpGetAttackerClass });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetCostDelta", &ExpertActionHandler::UpGetCostDelta });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetEvent", &ExpertActionHandler::UpGetEvent });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetFact", &ExpertActionHandler::UpGetFact });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetFactMax", &ExpertActionHandler::UpGetFactMax });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetFactMin", &ExpertActionHandler::UpGetFactMin });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetFactSum", &ExpertActionHandler::UpGetFactSum });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetFocusFact", &ExpertActionHandler::UpGetFocusFact });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetGroupSize", &ExpertActionHandler::UpGetGroupSize });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetIndirectGoal", &ExpertActionHandler::UpGetIndirectGoal });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetObjectData", &ExpertActionHandler::UpGetObjectData });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetObjectTargetData", &ExpertActionHandler::UpGetObjectTargetData });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetObjectTypeData", &ExpertActionHandler::UpGetObjectTypeData });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetPathDistance", &ExpertActionHandler::UpGetPathDistance });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetPlayerColor", &ExpertActionHandler::UpGetPlayerColor });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetPlayerFact", &ExpertActionHandler::UpGetPlayerFact });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetPoint", &ExpertActionHandler::UpGetPoint });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetPointContains", &ExpertActionHandler::UpGetPointContains });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetPointDistance", &ExpertActionHandler::UpGetPointDistance });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetPointElevation", &ExpertActionHandler::UpGetPointElevation });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetPointTerrain", &ExpertActionHandler::UpGetPointTerrain });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetPointZone", &ExpertActionHandler::UpGetPointZone });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetPreciseTime", &ExpertActionHandler::UpGetPreciseTime });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetProjectilePlayer", &ExpertActionHandler::UpGetProjectilePlayer });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetRuleId", &ExpertActionHandler::UpGetRuleId });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetSearchState", &ExpertActionHandler::UpGetSearchState });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetSharedGoal", &ExpertActionHandler::UpGetSharedGoal });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetSignal", &ExpertActionHandler::UpGetSignal });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetTargetFact", &ExpertActionHandler::UpGetTargetFact });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetThreatData", &ExpertActionHandler::UpGetThreatData });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetTimer", &ExpertActionHandler::UpGetTimer });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetVictoryData", &ExpertActionHandler::UpGetVictoryData });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetVictoryLimit", &ExpertActionHandler::UpGetVictoryLimit });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGuardUnit", &ExpertActionHandler::UpGuardUnit });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpJumpDirect", &ExpertActionHandler::UpJumpDirect });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpJumpDynamic", &ExpertActionHandler::UpJumpDynamic });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpJumpRule", &ExpertActionHandler::UpJumpRule });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpLerpPercent", &ExpertActionHandler::UpLerpPercent });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpLerpTiles", &ExpertActionHandler::UpLerpTiles });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpLogData", &ExpertActionHandler::UpLogData });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpModifyEscrow", &ExpertActionHandler::UpModifyEscrow });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpModifyFlag", &ExpertActionHandler::UpModifyFlag });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpModifyGoal", &ExpertActionHandler::UpModifyGoal });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpModifyGroupFlag", &ExpertActionHandler::UpModifyGroupFlag });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpModifySn", &ExpertActionHandler::UpModifySn });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpReleaseEscrow", &ExpertActionHandler::UpReleaseEscrow });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpRemoveObjects", &ExpertActionHandler::UpRemoveObjects });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpRequestHunters", &ExpertActionHandler::UpRequestHunters });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpResearch", &ExpertActionHandler::UpResearch });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpResetAttackNow", &ExpertActionHandler::UpResetAttackNow });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpResetBuilding", &ExpertActionHandler::UpResetBuilding });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpResetCostData", &ExpertActionHandler::UpResetCostData });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpResetFilters", &ExpertActionHandler::UpResetFilters });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpResetGroup", &ExpertActionHandler::UpResetGroup });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpResetPlacement", &ExpertActionHandler::UpResetPlacement });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpResetScouts", &ExpertActionHandler::UpResetScouts });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpResetSearch", &ExpertActionHandler::UpResetSearch });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpResetTargetPriorities", &ExpertActionHandler::UpResetTargetPriorities });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpResetUnit", &ExpertActionHandler::UpResetUnit });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpRetaskGatherers", &ExpertActionHandler::UpRetaskGatherers });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpRetreatNow", &ExpertActionHandler::UpRetreatNow });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpRetreatTo", &ExpertActionHandler::UpRetreatTo });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpSellCommodity", &ExpertActionHandler::UpSellCommodity });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpSendFlare", &ExpertActionHandler::UpSendFlare });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpSendScout", &ExpertActionHandler::UpSendScout });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpSetAttackStance", &ExpertActionHandler::UpSetAttackStance });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpSetDefensePriority", &ExpertActionHandler::UpSetDefensePriority });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpSetEvent", &ExpertActionHandler::UpSetEvent });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpSetGroup", &ExpertActionHandler::UpSetGroup });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpSetIndirectGoal", &ExpertActionHandler::UpSetIndirectGoal });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpSetOffensePriority", &ExpertActionHandler::UpSetOffensePriority });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpSetPlacementData", &ExpertActionHandler::UpSetPlacementData });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpSetPreciseTargetPoint", &ExpertActionHandler::UpSetPreciseTargetPoint });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpSetSharedGoal", &ExpertActionHandler::UpSetSharedGoal });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpSetSignal", &ExpertActionHandler::UpSetSignal });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpSetTargetById", &ExpertActionHandler::UpSetTargetById });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpSetTargetObject", &ExpertActionHandler::UpSetTargetObject });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpSetTargetPoint", &ExpertActionHandler::UpSetTargetPoint });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpSetTimer", &ExpertActionHandler::UpSetTimer });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpSetupCostData", &ExpertActionHandler::UpSetupCostData });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpStoreMapName", &ExpertActionHandler::UpStoreMapName });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpStoreObjectName", &ExpertActionHandler::UpStoreObjectName });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpStorePlayerChat", &ExpertActionHandler::UpStorePlayerChat });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpStorePlayerName", &ExpertActionHandler::UpStorePlayerName });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpStoreTechName", &ExpertActionHandler::UpStoreTechName });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpStoreText", &ExpertActionHandler::UpStoreText });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpStoreTypeName", &ExpertActionHandler::UpStoreTypeName });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpTargetObjects", &ExpertActionHandler::UpTargetObjects });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpTargetPoint", &ExpertActionHandler::UpTargetPoint });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpTrain", &ExpertActionHandler::UpTrain });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpTributeToPlayer", &ExpertActionHandler::UpTributeToPlayer });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpUngarrison", &ExpertActionHandler::UpUngarrison });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpUpdateTargets", &ExpertActionHandler::UpUpdateTargets });
	// DE-only actions
	commandMap.insert({ "type.googleapis.com/protos.expert.action.ChatDebug", &ExpertActionHandler::ChatDebug });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.FeBreakPoint", &ExpertActionHandler::FeBreakPoint });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.SkyboxClearSignal", &ExpertActionHandler::SkyboxClearSignal });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.SkyboxSetNameMode", &ExpertActionHandler::SkyboxSetNameMode });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpChatDataToAllUsingId", &ExpertActionHandler::UpChatDataToAllUsingId });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpChatDataToPlayerUsingId", &ExpertActionHandler::UpChatDataToPlayerUsingId });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetTreatyData", &ExpertActionHandler::UpGetTreatyData });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpTestharnessReport", &ExpertActionHandler::UpTestharnessReport });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpTestharnessTest", &ExpertActionHandler::UpTestharnessTest });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.FeGetSignal", &ExpertActionHandler::FeGetSignal });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.FeSetSignal", &ExpertActionHandler::FeSetSignal });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.FeCcEffectAmount", &ExpertActionHandler::FeCcEffectAmount });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.FeCcEffectPercent", &ExpertActionHandler::FeCcEffectPercent });
	// AOC-only actions
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetAlliedTarget", &ExpertActionHandler::UpGetAlliedTarget });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetGuardState", &ExpertActionHandler::UpGetGuardState });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetUpgradeId", &ExpertActionHandler::UpGetUpgradeId });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpOutOfSync", &ExpertActionHandler::UpOutOfSync });
	
	// completely custom commands added by the module
	commandMap.insert({ "type.googleapis.com/protos.expert.command.GetMapDimensions", &ExpertCommandHandler::GetMapDimensions });
	commandMap.insert({ "type.googleapis.com/protos.expert.command.GetTiles", &ExpertCommandHandler::GetTiles });
	commandMap.insert({ "type.googleapis.com/protos.expert.command.GetUnits", &ExpertCommandHandler::GetUnits });

	// facts
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.AttackSoldierCount", &ExpertFactHandler::AttackSoldierCount });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.AttackWarboatCount", &ExpertFactHandler::AttackWarboatCount });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.BuildingAvailable", &ExpertFactHandler::BuildingAvailable });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.BuildingCount", &ExpertFactHandler::BuildingCount });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.BuildingCountTotal", &ExpertFactHandler::BuildingCountTotal });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.BuildingTypeCount", &ExpertFactHandler::BuildingTypeCount });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.BuildingTypeCountTotal", &ExpertFactHandler::BuildingTypeCountTotal });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.CanAffordBuilding", &ExpertFactHandler::CanAffordBuilding });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.CanAffordCompleteWall", &ExpertFactHandler::CanAffordCompleteWall });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.CanAffordResearch", &ExpertFactHandler::CanAffordResearch });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.CanAffordUnit", &ExpertFactHandler::CanAffordUnit });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.CanBuild", &ExpertFactHandler::CanBuild });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.CanBuildGate", &ExpertFactHandler::CanBuildGate });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.CanBuildGateWithEscrow", &ExpertFactHandler::CanBuildGateWithEscrow });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.CanBuildWall", &ExpertFactHandler::CanBuildWall });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.CanBuildWallWithEscrow", &ExpertFactHandler::CanBuildWallWithEscrow });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.CanBuildWithEscrow", &ExpertFactHandler::CanBuildWithEscrow });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.CanBuyCommodity", &ExpertFactHandler::CanBuyCommodity });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.CanResearch", &ExpertFactHandler::CanResearch });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.CanResearchWithEscrow", &ExpertFactHandler::CanResearchWithEscrow });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.CanSellCommodity", &ExpertFactHandler::CanSellCommodity });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.CanSpy", &ExpertFactHandler::CanSpy });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.CanSpyWithEscrow", &ExpertFactHandler::CanSpyWithEscrow });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.CanTrain", &ExpertFactHandler::CanTrain });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.CanTrainWithEscrow", &ExpertFactHandler::CanTrainWithEscrow });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.CcPlayersBuildingCount", &ExpertFactHandler::CcPlayersBuildingCount });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.CcPlayersBuildingTypeCount", &ExpertFactHandler::CcPlayersBuildingTypeCount });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.CcPlayersUnitCount", &ExpertFactHandler::CcPlayersUnitCount });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.CcPlayersUnitTypeCount", &ExpertFactHandler::CcPlayersUnitTypeCount });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.CheatsEnabled", &ExpertFactHandler::CheatsEnabled });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.CivSelected", &ExpertFactHandler::CivSelected });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.CivilianPopulation", &ExpertFactHandler::CivilianPopulation });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.CommodityBuyingPrice", &ExpertFactHandler::CommodityBuyingPrice });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.CommoditySellingPrice", &ExpertFactHandler::CommoditySellingPrice });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.CurrentAge", &ExpertFactHandler::CurrentAge });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.CurrentAgeTime", &ExpertFactHandler::CurrentAgeTime });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.CurrentScore", &ExpertFactHandler::CurrentScore });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.DeathMatchGame", &ExpertFactHandler::DeathMatchGame });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.DefendSoldierCount", &ExpertFactHandler::DefendSoldierCount });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.DefendWarboatCount", &ExpertFactHandler::DefendWarboatCount });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.Difficulty", &ExpertFactHandler::Difficulty });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.Doctrine", &ExpertFactHandler::Doctrine });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.DropsiteMinDistance", &ExpertFactHandler::DropsiteMinDistance });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.EnemyBuildingsInTown", &ExpertFactHandler::EnemyBuildingsInTown });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.EnemyCapturedRelics", &ExpertFactHandler::EnemyCapturedRelics });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.EscrowAmount", &ExpertFactHandler::EscrowAmount });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.EventDetected", &ExpertFactHandler::EventDetected });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.False", &ExpertFactHandler::False });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.FoodAmount", &ExpertFactHandler::FoodAmount });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.GameTime", &ExpertFactHandler::GameTime });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.GameType", &ExpertFactHandler::GameType });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.GateCount", &ExpertFactHandler::GateCount });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.Goal", &ExpertFactHandler::Goal });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.GoalList", &ExpertFactHandler::GoalList });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.GoldAmount", &ExpertFactHandler::GoldAmount });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.HoldKohRuin", &ExpertFactHandler::HoldKohRuin });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.HoldRelics", &ExpertFactHandler::HoldRelics });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.HousingHeadroom", &ExpertFactHandler::HousingHeadroom });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.IdleFarmCount", &ExpertFactHandler::IdleFarmCount });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.MapSize", &ExpertFactHandler::MapSize });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.MapType", &ExpertFactHandler::MapType });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.MilitaryPopulation", &ExpertFactHandler::MilitaryPopulation });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.PlayerComputer", &ExpertFactHandler::PlayerComputer });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.PlayerHuman", &ExpertFactHandler::PlayerHuman });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.PlayerInGame", &ExpertFactHandler::PlayerInGame });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.PlayerNumber", &ExpertFactHandler::PlayerNumber });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.PlayerResigned", &ExpertFactHandler::PlayerResigned });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.PlayerValid", &ExpertFactHandler::PlayerValid });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.PlayersAchievements", &ExpertFactHandler::PlayersAchievements });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.PlayersBuildingCount", &ExpertFactHandler::PlayersBuildingCount });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.PlayersBuildingTypeCount", &ExpertFactHandler::PlayersBuildingTypeCount });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.PlayersCiv", &ExpertFactHandler::PlayersCiv });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.PlayersCivilianPopulation", &ExpertFactHandler::PlayersCivilianPopulation });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.PlayersCurrentAge", &ExpertFactHandler::PlayersCurrentAge });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.PlayersCurrentAgeTime", &ExpertFactHandler::PlayersCurrentAgeTime });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.PlayersMilitaryPopulation", &ExpertFactHandler::PlayersMilitaryPopulation });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.PlayersPopulation", &ExpertFactHandler::PlayersPopulation });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.PlayersScore", &ExpertFactHandler::PlayersScore });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.PlayersStance", &ExpertFactHandler::PlayersStance });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.PlayersTribute", &ExpertFactHandler::PlayersTribute });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.PlayersTributeMemory", &ExpertFactHandler::PlayersTributeMemory });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.PlayersUnitCount", &ExpertFactHandler::PlayersUnitCount });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.PlayersUnitTypeCount", &ExpertFactHandler::PlayersUnitTypeCount });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.Population", &ExpertFactHandler::Population });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.PopulationCap", &ExpertFactHandler::PopulationCap });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.PopulationHeadroom", &ExpertFactHandler::PopulationHeadroom });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.RandomNumber", &ExpertFactHandler::RandomNumber });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.RegicideGame", &ExpertFactHandler::RegicideGame });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.ResearchAvailable", &ExpertFactHandler::ResearchAvailable });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.ResearchCompleted", &ExpertFactHandler::ResearchCompleted });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.ResourceFound", &ExpertFactHandler::ResourceFound });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.SharedGoal", &ExpertFactHandler::SharedGoal });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.SheepAndForageTooFar", &ExpertFactHandler::SheepAndForageTooFar });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.SoldierCount", &ExpertFactHandler::SoldierCount });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.StanceToward", &ExpertFactHandler::StanceToward });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.StartingAge", &ExpertFactHandler::StartingAge });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.StartingResources", &ExpertFactHandler::StartingResources });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.StoneAmount", &ExpertFactHandler::StoneAmount });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.StrategicNumber", &ExpertFactHandler::StrategicNumber });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.StrategicNumberList", &ExpertFactHandler::StrategicNumberList });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.TauntDetected", &ExpertFactHandler::TauntDetected });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.TimerTriggered", &ExpertFactHandler::TimerTriggered });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.TownUnderAttack", &ExpertFactHandler::TownUnderAttack });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.TraceFact", &ExpertFactHandler::TraceFact });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.True", &ExpertFactHandler::True });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UnitAvailable", &ExpertFactHandler::UnitAvailable });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UnitCount", &ExpertFactHandler::UnitCount });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UnitCountTotal", &ExpertFactHandler::UnitCountTotal });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UnitTypeCount", &ExpertFactHandler::UnitTypeCount });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UnitTypeCountTotal", &ExpertFactHandler::UnitTypeCountTotal });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpAlliedGoal", &ExpertFactHandler::UpAlliedGoal });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpAlliedResourceAmount", &ExpertFactHandler::UpAlliedResourceAmount });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpAlliedResourcePercent", &ExpertFactHandler::UpAlliedResourcePercent });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpAlliedSn", &ExpertFactHandler::UpAlliedSn });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpAttackerClass", &ExpertFactHandler::UpAttackerClass });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpBuildingTypeInTown", &ExpertFactHandler::UpBuildingTypeInTown });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpCanBuild", &ExpertFactHandler::UpCanBuild });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpCanBuildLine", &ExpertFactHandler::UpCanBuildLine });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpCanResearch", &ExpertFactHandler::UpCanResearch });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpCanSearch", &ExpertFactHandler::UpCanSearch });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpCanTrain", &ExpertFactHandler::UpCanTrain });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpDefenderCount", &ExpertFactHandler::UpDefenderCount });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpEnemyBuildingsInTown", &ExpertFactHandler::UpEnemyBuildingsInTown });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpEnemyUnitsInTown", &ExpertFactHandler::UpEnemyUnitsInTown });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpEnemyVillagersInTown", &ExpertFactHandler::UpEnemyVillagersInTown });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpGaiaTypeCount", &ExpertFactHandler::UpGaiaTypeCount });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpGaiaTypeCountTotal", &ExpertFactHandler::UpGaiaTypeCountTotal });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpGroupSize", &ExpertFactHandler::UpGroupSize });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpIdleUnitCount", &ExpertFactHandler::UpIdleUnitCount });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpObjectData", &ExpertFactHandler::UpObjectData });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpObjectDataList", &ExpertFactHandler::UpObjectDataList });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpObjectTargetData", &ExpertFactHandler::UpObjectTargetData });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpObjectTypeCount", &ExpertFactHandler::UpObjectTypeCount });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpObjectTypeCountTotal", &ExpertFactHandler::UpObjectTypeCountTotal });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpPathDistance", &ExpertFactHandler::UpPathDistance });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpPendingObjects", &ExpertFactHandler::UpPendingObjects });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpPendingPlacement", &ExpertFactHandler::UpPendingPlacement });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpPlayerDistance", &ExpertFactHandler::UpPlayerDistance });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpPlayersInGame", &ExpertFactHandler::UpPlayersInGame });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpPointContains", &ExpertFactHandler::UpPointContains });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpPointDistance", &ExpertFactHandler::UpPointDistance });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpPointElevation", &ExpertFactHandler::UpPointElevation });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpPointExplored", &ExpertFactHandler::UpPointExplored });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpPointTerrain", &ExpertFactHandler::UpPointTerrain });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpPointZone", &ExpertFactHandler::UpPointZone });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpProjectileDetected", &ExpertFactHandler::UpProjectileDetected });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpProjectileTarget", &ExpertFactHandler::UpProjectileTarget });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpRemainingBoarAmount", &ExpertFactHandler::UpRemainingBoarAmount });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpResearchStatus", &ExpertFactHandler::UpResearchStatus });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpResourceAmount", &ExpertFactHandler::UpResourceAmount });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpResourcePercent", &ExpertFactHandler::UpResourcePercent });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpSearchObjectIdList", &ExpertFactHandler::UpSearchObjectIdList });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpTimerStatus", &ExpertFactHandler::UpTimerStatus });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpTrainSiteReady", &ExpertFactHandler::UpTrainSiteReady });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpUnitTypeInTown", &ExpertFactHandler::UpUnitTypeInTown });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpVillagerTypeInTown", &ExpertFactHandler::UpVillagerTypeInTown });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.VictoryCondition", &ExpertFactHandler::VictoryCondition });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.WallCompletedPercentage", &ExpertFactHandler::WallCompletedPercentage });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.WallInvisiblePercentage", &ExpertFactHandler::WallInvisiblePercentage });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.WarboatCount", &ExpertFactHandler::WarboatCount });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.WoodAmount", &ExpertFactHandler::WoodAmount });
	// DE-only facts
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.EndingAge", &ExpertFactHandler::EndingAge });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.FeCanBuildAtPoint", &ExpertFactHandler::FeCanBuildAtPoint });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.FeSubGameType", &ExpertFactHandler::FeSubGameType });
}

void Expert::EnableDetours()
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)FuncRunList, DetouredRunList);
	LONG transactionResult = DetourTransactionCommit();

	if (transactionResult != NO_ERROR)
	{
		std::cout << "[Expert] Error: failed to detour function 'RunList'."
			<< " Error code " << transactionResult
			<< ", game module base address 0x" << std::hex << statics::GetGameModuleBaseAddr() << std::dec
			<< ", function address 0x" << std::hex << (uintptr_t) FuncRunList << std::dec
			<< ". Commands will not be processed." << std::endl;
	}
}

void Expert::DisableDetours()
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourDetach(&(PVOID&)FuncRunList, DetouredRunList);
	DetourTransactionCommit();
}

#if defined GAME_DE
int64_t Expert::DetouredRunList(structs::AIExpert* aiExpert, int listId, void* statsOutput)
#elif defined GAME_AOC
int32_t __fastcall Expert::DetouredRunList(structs::AIExpert* aiExpert, void* unused, int listId, void* statsOutput)
#endif
{
	if (!Expert::instance->factsAndActionsInitialized)
	{
		ExpertAction::Initialize(aiExpert);
		ExpertFact::Initialize(aiExpert);
		Expert::instance->factsAndActionsInitialized = true;
	}

	auto t1 = std::chrono::high_resolution_clock::now();
	int numCommandsProcessed = Expert::instance->ProcessCommands();
	auto t2 = std::chrono::high_resolution_clock::now();

	if (numCommandsProcessed)
	{
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
		std::cout << "[Expert] Processed " << numCommandsProcessed  << " command" << (numCommandsProcessed == 1 ? "" : "s") << " in " << duration << " us." << std::endl;
	}

	// run the commands from .per AI files after the module's
	return FuncRunList(aiExpert, listId, statsOutput);
}

int Expert::ProcessCommands()
{
	int numCommandsProcessed = 0;
	std::lock_guard<std::mutex> lguard(*commandQueue.GetMutex());

	auto internalCommandQueue = commandQueue.GetInternalQueue();
	for (auto i = internalCommandQueue->begin(); i != internalCommandQueue->end();  )
	{
		ExpertCommandQueue::Item* item = *i;
		int playerNumber = item->commandList->playernumber();
		bool isCurrentPlayer = false;

		try
		{
			isCurrentPlayer = ExpertFact::PlayerNumber(playerNumber);
		}
		catch (std::exception& e)
		{
			std::cout << "[Expert] Error: required fact 'PlayerNumber' is not operational: '" << e.what() << "'. Commands will not be processed." << std::endl;
		}

		if (isCurrentPlayer)
		{
			// process
			item->commandResultList->set_playernumber(playerNumber);
			numCommandsProcessed += ProcessCommandList(item->commandList, item->commandResultList);

			// remove from queue
			i = internalCommandQueue->erase(i);

			// mark as processed, notify rpc thread to send back response to client
			*item->isProcessed = true;
			item->conditionVar->notify_one();
		}
		else
		{
			// skip execution of this command for now as its not for the current player
			i++;
		}
	}

	return numCommandsProcessed;
}

int Expert::ProcessCommandList(const protos::expert::CommandList* commandList, protos::expert::CommandResultList* commandResultList)
{
	int numCommandsProcessed = 0;

	for (int requestIndex = 0; requestIndex < commandList->commands_size(); requestIndex++)
	{
		google::protobuf::Any anyCommand = commandList->commands(requestIndex);
		google::protobuf::Any* anyResult = commandResultList->add_results();

		try
		{
			numCommandsProcessed += ExecuteCommand(anyCommand, anyResult);
		}
		catch (const std::exception& e)
		{
			std::cout << "[Expert] Failed to execute command '" << anyCommand.type_url() << "': " << e.what() << std::endl;
		}
	}

	return numCommandsProcessed;
}

int Expert::ExecuteCommand(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	if (anyCommand.type_url() == "type.googleapis.com/protos.expert.ConditionalCommand")
	{
		// unpack conditional command message
		protos::expert::ConditionalCommand conditionalCommand;
		anyCommand.UnpackTo(&conditionalCommand);

		// execute fact function and get its result as an integer
		google::protobuf::Any factResultAny;
		int numCommandsProcessed = ExecuteCommand(conditionalCommand.fact(), &factResultAny);
		int factResultInt = GetAnyCommandResult(factResultAny);

		// get the expected fact value as a const
		int expectedValue = 0;
		switch (conditionalCommand.value_case())
		{
			case protos::expert::ConditionalCommand::kInConstValue:
			{
				expectedValue = conditionalCommand.inconstvalue();
				break;
			}
			case protos::expert::ConditionalCommand::kInGoalValue:
			{
				expectedValue = ExpertFact::Goal(conditionalCommand.ingoalvalue());
				break;
			}
			case protos::expert::ConditionalCommand::kInSnValue:
			{
				expectedValue = ExpertFact::StrategicNumber(conditionalCommand.insnvalue());
				break;
			}
		}

		// prepare result message, compare fact result to expected
		protos::expert::ConditionalCommandResult conditionalCommandResult;
		if (CompareFactResult(factResultInt, conditionalCommand.compareop(), expectedValue))
		{
			numCommandsProcessed += ExecuteCommand(conditionalCommand.command(), conditionalCommandResult.mutable_result());
			conditionalCommandResult.set_fired(true);
		}
		
		anyResult->PackFrom(conditionalCommandResult);
		return numCommandsProcessed;
	}

	// execute normal command
	try
	{
		auto commandHandler = commandMap.at(anyCommand.type_url());
		commandHandler(anyCommand, anyResult);
		return 1;
	}
	catch (const std::exception&)
	{
		std::cout << "[Expert] Received unsupported command '" << anyCommand.type_url() << "'." << std::endl;
	}

	return 0;
}

// get the integer value of the result field from any command, fact, or action if applicable
int Expert::GetAnyCommandResult(const google::protobuf::Any& anyResult)
{
	auto descriptorPool = google::protobuf::DescriptorPool::generated_pool();
	auto messageFactory = google::protobuf::MessageFactory::generated_factory();

	if (descriptorPool && messageFactory)
	{
		// look up the message type
		auto messageDescriptor = descriptorPool->FindMessageTypeByName(TypeUrlToTypeName(anyResult.type_url()));

		if (messageDescriptor)
		{
			// look up the prototype for the said message type, get reflection, look up the result field
			auto messagePrototype = messageFactory->GetPrototype(messageDescriptor);
			auto messageReflection = messagePrototype->GetReflection();
			auto resultFieldDescriptor = messageDescriptor->FindFieldByName("result");

			if (messagePrototype && messageReflection && resultFieldDescriptor)
			{
				// initialize a new empty message using given prototype at runtime
				auto message = messagePrototype->New();

				if (message)
				{
					// fill message with data from the Any object passed into this function
					message->ParseFromString(anyResult.value());

					// read the result field, adjust for type
					switch (resultFieldDescriptor->type())
					{
						case google::protobuf::FieldDescriptor::Type::TYPE_BOOL:
						{
							return messageReflection->GetBool(*message, resultFieldDescriptor);
						}
						case google::protobuf::FieldDescriptor::Type::TYPE_SINT32:
						case google::protobuf::FieldDescriptor::Type::TYPE_INT32:
						{
							return messageReflection->GetInt32(*message, resultFieldDescriptor);
						}
						case google::protobuf::FieldDescriptor::Type::TYPE_MESSAGE:
						{
#pragma push_macro("GetMessage")
#undef GetMessage
							// allow extracting the result from ConditionalCommandResult, not really needed
							auto& subMessage = messageReflection->GetMessage(*message, resultFieldDescriptor);
							if (subMessage.GetTypeName() == "google.protobuf.Any")
							{
								return GetAnyCommandResult(dynamic_cast<const google::protobuf::Any&>(subMessage));
							}
#pragma pop_macro("GetMessage")
							break;
						}
					}
				}
			}
		}
	}

	return 0;
}

std::string Expert::TypeUrlToTypeName(const std::string& typeUrl)
{
	return typeUrl.substr(typeUrl.find("/") + 1);
}

bool Expert::CompareFactResult(int factResult, const std::string& compareOp, int expectedValue)
{
	if (compareOp == "==") return factResult == expectedValue;
	if (compareOp == ">=") return factResult >= expectedValue;
	if (compareOp == "<=") return factResult <= expectedValue;
	if (compareOp == ">") return factResult > expectedValue;
	if (compareOp == "<") return factResult < expectedValue;
	if (compareOp == "!=") return factResult != expectedValue;

	return false;
}

Expert::~Expert()
{
	DisableDetours();
}
