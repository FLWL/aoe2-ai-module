#include "Expert.h"

#include <iostream>
#include <chrono>

#include <Windows.h>
#include <detours/detours.h>

#include "AIModule.h"
#include "misc/Statics.h"
#include "expert/action/ExpertAction.h"
#include "expert/action/ExpertActionHandler.h"
#include "expert/fact/ExpertFact.h"
#include "expert/fact/ExpertFactHandler.h"

Expert* Expert::instance;

Expert::Expert(AIModule* aiModule) :
	aiModule(aiModule),
	expertService(this)
{
	instance = this;
	UpdateAddresses();
	PopulateCommandMap();
	EnableDetours();
}

void Expert::UpdateAddresses()
{
	statics::SetFuncAddr(FuncRunList, statics::TranslateAddr(expert_conf::ADDR_FUNC_RUN_LIST));
#ifdef DEBUG_MODE
	statics::SetFuncAddr(FuncDefAction, statics::TranslateAddr(expert_conf::ADDR_FUNC_DEF_ACTION));
#endif

	ExpertAction::UpdateAddresses();
	ExpertFact::UpdateAddresses();
}

void Expert::PopulateCommandMap()
{
	commandMap.insert({ "type.googleapis.com/protos.expert.action.AcknowledgeEvent", &ExpertActionHandler::AcknowledgeEvent });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.AcknowledgeTaunt", &ExpertActionHandler::AcknowledgeTaunt });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.AttackNow", &ExpertActionHandler::AttackNow });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.Build", &ExpertActionHandler::Build });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.BuildForward", &ExpertActionHandler::BuildForward });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.BuildGate", &ExpertActionHandler::BuildGate });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.BuildWall", &ExpertActionHandler::BuildWall });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.BuyCommodity", &ExpertActionHandler::BuyCommodity });
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
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetGuardState", &ExpertActionHandler::UpGetGuardState });
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
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetUpgradeId", &ExpertActionHandler::UpGetUpgradeId });
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
	
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.Goal", &ExpertFactHandler::Goal });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.Goals", &ExpertFactHandler::Goals });
}

void Expert::EnableDetours()
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)FuncRunList, DetouredRunList);
#ifdef DEBUG_MODE
	DetourAttach(&(PVOID&)FuncDefAction, DetouredDefAction);
#endif
	DetourTransactionCommit();
}

void Expert::DisableDetours()
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourDetach(&(PVOID&)FuncRunList, DetouredRunList);
#ifdef DEBUG_MODE
	DetourDetach(&(PVOID&)FuncDefAction, DetouredDefAction);
#endif
	DetourTransactionCommit();
}

intptr_t __fastcall Expert::DetouredRunList(void* aiExpertEngine, int listId, void* statsOutput)
{
	intptr_t result = FuncRunList(aiExpertEngine, listId, statsOutput);

	auto t1 = std::chrono::high_resolution_clock::now();
	int numCommandsProcessed = Expert::instance->ProcessCommands();
	auto t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

	if (numCommandsProcessed)
	{
		std::cout << "Processed " << numCommandsProcessed  << " command(s) in " << duration << " us"<< std::endl;
	}

	return result;
}

#ifdef DEBUG_MODE
intptr_t __fastcall Expert::DetouredDefAction(void* aiExpert, char *name, char argCount, void* function)
{
	uintptr_t reverseTranslatedFunctionPtr = (uintptr_t) function - statics::GetGameModuleBaseAddr() + aimodule_conf::REFERENCE_BASE_ADDR;
	std::cout << "DefAction(): function pointer for " << name << " = 0x" << std::hex << std::uppercase << reverseTranslatedFunctionPtr << std::nouppercase << std::dec << std::endl;

	return FuncDefAction(aiExpert, name, argCount, function);
}
#endif

int Expert::ProcessCommands()
{
	int numCommandsProcessed = 0;
	std::lock_guard<std::mutex> lguard(*commandQueue.GetMutex());
	while (!commandQueue.IsEmpty())
	{
		// work to do
		ExpertCommandQueue::Item* item = commandQueue.Pop();

		// process
		numCommandsProcessed += ProcessCommandList(item->commandList, item->commandResultList);

		// mark as processed and wake up the corresponding rpc thread
		*item->isProcessed = true;
		item->conditionVar->notify_one();
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
		
		auto commandHandler = commandMap[anyCommand.type_url()];
		if (commandHandler)
		{
			commandHandler(anyCommand, anyResult);
			numCommandsProcessed++;
		}
	}

	return numCommandsProcessed;
}

void Expert::PreUnload()
{
	commandQueue.Clear();
}

Expert::~Expert()
{
	DisableDetours();
}
