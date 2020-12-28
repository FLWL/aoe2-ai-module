#include "ExpertAction.h"

#include <iostream>

#include <Windows.h>
#include <detours/detours.h>

#include "misc/Statics.h"
#include "expert/fact/ExpertFact.h"

ExpertAction::ExpertAction()
{
	UpdateAddresses();
	EnableDetours();
}

ExpertAction::~ExpertAction()
{
	DisableDetours();
}

void ExpertAction::UpdateAddresses()
{
	statics::SetFuncAddr(FuncGetString, statics::TranslateAddr(expert_conf::ADDR_FUNC_GET_STRING));

	statics::SetFuncAddr(FuncAcknowledgeEvent, statics::TranslateAddr(expert_conf::ADDR_FUNC_ACKNOWLEDGE_EVENT));
	statics::SetFuncAddr(FuncAcknowledgeTaunt, statics::TranslateAddr(expert_conf::ADDR_FUNC_ACKNOWLEDGE_TAUNT));
	statics::SetFuncAddr(FuncAttackNow, statics::TranslateAddr(expert_conf::ADDR_FUNC_ATTACK_NOW));
	statics::SetFuncAddr(FuncBuild, statics::TranslateAddr(expert_conf::ADDR_FUNC_BUILD));
	statics::SetFuncAddr(FuncBuildForward, statics::TranslateAddr(expert_conf::ADDR_FUNC_BUILD_FORWARD));
	statics::SetFuncAddr(FuncBuildGate, statics::TranslateAddr(expert_conf::ADDR_FUNC_BUILD_GATE));
	statics::SetFuncAddr(FuncBuildWall, statics::TranslateAddr(expert_conf::ADDR_FUNC_BUILD_WALL));
	statics::SetFuncAddr(FuncBuyCommodity, statics::TranslateAddr(expert_conf::ADDR_FUNC_BUY_COMMODITY));
	statics::SetFuncAddr(FuncCcAddResource, statics::TranslateAddr(expert_conf::ADDR_FUNC_CC_ADD_RESOURCE));
	statics::SetFuncAddr(FuncChatLocal, statics::TranslateAddr(expert_conf::ADDR_FUNC_CHAT_LOCAL));
	statics::SetFuncAddr(FuncChatLocalUsingId, statics::TranslateAddr(expert_conf::ADDR_FUNC_CHAT_LOCAL_USING_ID));
	statics::SetFuncAddr(FuncChatLocalUsingRange, statics::TranslateAddr(expert_conf::ADDR_FUNC_CHAT_LOCAL_USING_RANGE));
	statics::SetFuncAddr(FuncChatLocalToSelf, statics::TranslateAddr(expert_conf::ADDR_FUNC_CHAT_LOCAL_TO_SELF));
	statics::SetFuncAddr(FuncChatToAll, statics::TranslateAddr(expert_conf::ADDR_FUNC_CHAT_TO_ALL));
	statics::SetFuncAddr(FuncChatToAllUsingId, statics::TranslateAddr(expert_conf::ADDR_FUNC_CHAT_TO_ALL_USING_ID));
	statics::SetFuncAddr(FuncChatToAllUsingRange, statics::TranslateAddr(expert_conf::ADDR_FUNC_CHAT_TO_ALL_USING_RANGE));
	statics::SetFuncAddr(FuncChatToAllies, statics::TranslateAddr(expert_conf::ADDR_FUNC_CHAT_TO_ALLIES));
	statics::SetFuncAddr(FuncChatToAlliesUsingId, statics::TranslateAddr(expert_conf::ADDR_FUNC_CHAT_TO_ALLIES_USING_ID));
	statics::SetFuncAddr(FuncChatToAlliesUsingRange, statics::TranslateAddr(expert_conf::ADDR_FUNC_CHAT_TO_ALLIES_USING_RANGE));
	statics::SetFuncAddr(FuncChatToEnemies, statics::TranslateAddr(expert_conf::ADDR_FUNC_CHAT_TO_ENEMIES));
	statics::SetFuncAddr(FuncChatToEnemiesUsingId, statics::TranslateAddr(expert_conf::ADDR_FUNC_CHAT_TO_ENEMIES_USING_ID));
	statics::SetFuncAddr(FuncChatToEnemiesUsingRange, statics::TranslateAddr(expert_conf::ADDR_FUNC_CHAT_TO_ENEMIES_USING_RANGE));
	statics::SetFuncAddr(FuncChatToPlayer, statics::TranslateAddr(expert_conf::ADDR_FUNC_CHAT_TO_PLAYER));
	statics::SetFuncAddr(FuncChatToPlayerUsingId, statics::TranslateAddr(expert_conf::ADDR_FUNC_CHAT_TO_PLAYER_USING_ID));
	statics::SetFuncAddr(FuncChatToPlayerUsingRange, statics::TranslateAddr(expert_conf::ADDR_FUNC_CHAT_TO_PLAYER_USING_RANGE));
	statics::SetFuncAddr(FuncChatTrace, statics::TranslateAddr(expert_conf::ADDR_FUNC_CHAT_TRACE));
	statics::SetFuncAddr(FuncClearTributeMemory, statics::TranslateAddr(expert_conf::ADDR_FUNC_CLEAR_TRIBUTE_MEMORY));
	statics::SetFuncAddr(FuncDeleteBuilding, statics::TranslateAddr(expert_conf::ADDR_FUNC_DELETE_BUILDING));
	statics::SetFuncAddr(FuncDeleteUnit, statics::TranslateAddr(expert_conf::ADDR_FUNC_DELETE_UNIT));
	statics::SetFuncAddr(FuncDisableRule, statics::TranslateAddr(expert_conf::ADDR_FUNC_DISABLE_RULE));
	statics::SetFuncAddr(FuncDisableSelf, statics::TranslateAddr(expert_conf::ADDR_FUNC_DISABLE_SELF));
	statics::SetFuncAddr(FuncDisableTimer, statics::TranslateAddr(expert_conf::ADDR_FUNC_DISABLE_TIMER));
	statics::SetFuncAddr(FuncEnableRule, statics::TranslateAddr(expert_conf::ADDR_FUNC_ENABLE_RULE));
	statics::SetFuncAddr(FuncEnableTimer, statics::TranslateAddr(expert_conf::ADDR_FUNC_ENABLE_TIMER));
	statics::SetFuncAddr(FuncEnableWallPlacement, statics::TranslateAddr(expert_conf::ADDR_FUNC_ENABLE_WALL_PLACEMENT));
	statics::SetFuncAddr(FuncGenerateRandomNumber, statics::TranslateAddr(expert_conf::ADDR_FUNC_GENERATE_RANDOM_NUMBER));
	statics::SetFuncAddr(FuncLog, statics::TranslateAddr(expert_conf::ADDR_FUNC_LOG));
	statics::SetFuncAddr(FuncLogTrace, statics::TranslateAddr(expert_conf::ADDR_FUNC_LOG_TRACE));
	statics::SetFuncAddr(FuncReleaseEscrow, statics::TranslateAddr(expert_conf::ADDR_FUNC_RELEASE_ESCROW));
	statics::SetFuncAddr(FuncResearch, statics::TranslateAddr(expert_conf::ADDR_FUNC_RESEARCH));
	statics::SetFuncAddr(FuncResign, statics::TranslateAddr(expert_conf::ADDR_FUNC_RESIGN));
	statics::SetFuncAddr(FuncSellCommodity, statics::TranslateAddr(expert_conf::ADDR_FUNC_SELL_COMMODITY));
	statics::SetFuncAddr(FuncSetDifficultyParameter, statics::TranslateAddr(expert_conf::ADDR_FUNC_SET_DIFFICULTY_PARAMETER));
	statics::SetFuncAddr(FuncSetDoctrine, statics::TranslateAddr(expert_conf::ADDR_FUNC_SET_DOCTRINE));
	statics::SetFuncAddr(FuncSetEscrowPercentage, statics::TranslateAddr(expert_conf::ADDR_FUNC_SET_ESCROW_PERCENTAGE));
	statics::SetFuncAddr(FuncSetGoal, statics::TranslateAddr(expert_conf::ADDR_FUNC_SET_GOAL));
	statics::SetFuncAddr(FuncSetSharedGoal, statics::TranslateAddr(expert_conf::ADDR_FUNC_SET_SHARED_GOAL));
	statics::SetFuncAddr(FuncSetSignal, statics::TranslateAddr(expert_conf::ADDR_FUNC_SET_SIGNAL));
	statics::SetFuncAddr(FuncSetStance, statics::TranslateAddr(expert_conf::ADDR_FUNC_SET_STANCE));
	statics::SetFuncAddr(FuncSetStrategicNumber, statics::TranslateAddr(expert_conf::ADDR_FUNC_SET_STRATEGIC_NUMBER));
	statics::SetFuncAddr(FuncSpy, statics::TranslateAddr(expert_conf::ADDR_FUNC_SPY));
	statics::SetFuncAddr(FuncTaunt, statics::TranslateAddr(expert_conf::ADDR_FUNC_TAUNT));
	statics::SetFuncAddr(FuncTauntUsingRange, statics::TranslateAddr(expert_conf::ADDR_FUNC_TAUNT_USING_RANGE));
	statics::SetFuncAddr(FuncTrain, statics::TranslateAddr(expert_conf::ADDR_FUNC_TRAIN));
	statics::SetFuncAddr(FuncTributeToPlayer, statics::TranslateAddr(expert_conf::ADDR_FUNC_TRIBUTE_TO_PLAYER));
	statics::SetFuncAddr(FuncUpAddCostData, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_ADD_COST_DATA));
	statics::SetFuncAddr(FuncUpAddObjectById, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_ADD_OBJECT_BY_ID));
	statics::SetFuncAddr(FuncUpAddObjectCost, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_ADD_OBJECT_COST));
	statics::SetFuncAddr(FuncUpAddPoint, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_ADD_POINT));
	statics::SetFuncAddr(FuncUpAddResearchCost, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_ADD_RESEARCH_COST));
	statics::SetFuncAddr(FuncUpAssignBuilders, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_ASSIGN_BUILDERS));
	statics::SetFuncAddr(FuncUpBoundPoint, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_BOUND_POINT));
	statics::SetFuncAddr(FuncUpBoundPrecisePoint, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_BOUND_PRECISE_POINT));
	statics::SetFuncAddr(FuncUpBuild, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_BUILD));
	statics::SetFuncAddr(FuncUpBuildLine, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_BUILD_LINE));
	statics::SetFuncAddr(FuncUpBuyCommodity, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_BUY_COMMODITY));
	statics::SetFuncAddr(FuncUpCcAddResource, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_CC_ADD_RESOURCE));
	statics::SetFuncAddr(FuncUpCcSendCheat, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_CC_SEND_CHEAT));
	statics::SetFuncAddr(FuncUpChangeName, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_CHANGE_NAME));
	statics::SetFuncAddr(FuncUpChatDataToAll, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_CHAT_DATA_TO_ALL));
	statics::SetFuncAddr(FuncUpChatDataToPlayer, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_CHAT_DATA_TO_PLAYER));
	statics::SetFuncAddr(FuncUpChatDataToSelf, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_CHAT_DATA_TO_SELF));
	statics::SetFuncAddr(FuncUpCleanSearch, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_CLEAN_SEARCH));
	statics::SetFuncAddr(FuncUpCopyPoint, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_COPY_POINT));
	statics::SetFuncAddr(FuncUpCreateGroup, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_CREATE_GROUP));
	statics::SetFuncAddr(FuncUpCrossTiles, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_CROSS_TILES));
	statics::SetFuncAddr(FuncUpDeleteDistantFarms, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_DELETE_DISTANT_FARMS));
	statics::SetFuncAddr(FuncUpDeleteIdleUnits, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_DELETE_IDLE_UNITS));
	statics::SetFuncAddr(FuncUpDeleteObjects, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_DELETE_OBJECTS));
	statics::SetFuncAddr(FuncUpDisbandGroupType, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_DISBAND_GROUP_TYPE));
	statics::SetFuncAddr(FuncUpDropResources, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_DROP_RESOURCES));
	statics::SetFuncAddr(FuncUpFilterDistance, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_FILTER_DISTANCE));
	statics::SetFuncAddr(FuncUpFilterExclude, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_FILTER_EXCLUDE));
	statics::SetFuncAddr(FuncUpFilterGarrison, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_FILTER_GARRISON));
	statics::SetFuncAddr(FuncUpFilterInclude, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_FILTER_INCLUDE));
	statics::SetFuncAddr(FuncUpFilterRange, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_FILTER_RANGE));
	statics::SetFuncAddr(FuncUpFilterStatus, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_FILTER_STATUS));
	statics::SetFuncAddr(FuncUpFindFlare, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_FIND_FLARE));
	statics::SetFuncAddr(FuncUpFindLocal, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_FIND_LOCAL));
	statics::SetFuncAddr(FuncUpFindNextPlayer, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_FIND_NEXT_PLAYER));
	statics::SetFuncAddr(FuncUpFindPlayer, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_FIND_PLAYER));
	statics::SetFuncAddr(FuncUpFindPlayerFlare, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_FIND_PLAYER_FLARE));
	statics::SetFuncAddr(FuncUpFindRemote, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_FIND_REMOTE));
	statics::SetFuncAddr(FuncUpFindResource, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_FIND_RESOURCE));
	statics::SetFuncAddr(FuncUpFindStatusLocal, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_FIND_STATUS_LOCAL));
	statics::SetFuncAddr(FuncUpFindStatusRemote, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_FIND_STATUS_REMOTE));
	statics::SetFuncAddr(FuncUpFullResetSearch, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_FULL_RESET_SEARCH));
	statics::SetFuncAddr(FuncUpGarrison, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GARRISON));
	statics::SetFuncAddr(FuncUpGatherInside, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GATHER_INSIDE));
	statics::SetFuncAddr(FuncUpGetAttackerClass, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_ATTACKER_CLASS));
	statics::SetFuncAddr(FuncUpGetCostDelta, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_COST_DELTA));
	statics::SetFuncAddr(FuncUpGetEvent, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_EVENT));
	statics::SetFuncAddr(FuncUpGetFact, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_FACT));
	statics::SetFuncAddr(FuncUpGetFactMax, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_FACT_MAX));
	statics::SetFuncAddr(FuncUpGetFactMin, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_FACT_MIN));
	statics::SetFuncAddr(FuncUpGetFactSum, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_FACT_SUM));
	statics::SetFuncAddr(FuncUpGetFocusFact, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_FOCUS_FACT));
	statics::SetFuncAddr(FuncUpGetGroupSize, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_GROUP_SIZE));
	statics::SetFuncAddr(FuncUpGetIndirectGoal, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_INDIRECT_GOAL));
	statics::SetFuncAddr(FuncUpGetObjectData, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_OBJECT_DATA));
	statics::SetFuncAddr(FuncUpGetObjectTargetData, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_OBJECT_TARGET_DATA));
	statics::SetFuncAddr(FuncUpGetObjectTypeData, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_OBJECT_TYPE_DATA));
	statics::SetFuncAddr(FuncUpGetPathDistance, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_PATH_DISTANCE));
	statics::SetFuncAddr(FuncUpGetPlayerColor, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_PLAYER_COLOR));
	statics::SetFuncAddr(FuncUpGetPlayerFact, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_PLAYER_FACT));
	statics::SetFuncAddr(FuncUpGetPoint, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_POINT));
	statics::SetFuncAddr(FuncUpGetPointContains, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_POINT_CONTAINS));
	statics::SetFuncAddr(FuncUpGetPointDistance, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_POINT_DISTANCE));
	statics::SetFuncAddr(FuncUpGetPointElevation, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_POINT_ELEVATION));
	statics::SetFuncAddr(FuncUpGetPointTerrain, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_POINT_TERRAIN));
	statics::SetFuncAddr(FuncUpGetPointZone, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_POINT_ZONE));
	statics::SetFuncAddr(FuncUpGetPreciseTime, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_PRECISE_TIME));
	statics::SetFuncAddr(FuncUpGetProjectilePlayer, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_PROJECTILE_PLAYER));
	statics::SetFuncAddr(FuncUpGetRuleId, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_RULE_ID));
	statics::SetFuncAddr(FuncUpGetSearchState, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_SEARCH_STATE));
	statics::SetFuncAddr(FuncUpGetSharedGoal, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_SHARED_GOAL));
	statics::SetFuncAddr(FuncUpGetSignal, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_SIGNAL));
	statics::SetFuncAddr(FuncUpGetTargetFact, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_TARGET_FACT));
	statics::SetFuncAddr(FuncUpGetThreatData, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_THREAT_DATA));
	statics::SetFuncAddr(FuncUpGetTimer, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_TIMER));
	statics::SetFuncAddr(FuncUpGetVictoryData, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_VICTORY_DATA));
	statics::SetFuncAddr(FuncUpGetVictoryLimit, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_VICTORY_LIMIT));
	statics::SetFuncAddr(FuncUpGuardUnit, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GUARD_UNIT));
	statics::SetFuncAddr(FuncUpJumpDirect, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_JUMP_DIRECT));
	statics::SetFuncAddr(FuncUpJumpDynamic, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_JUMP_DYNAMIC));
	statics::SetFuncAddr(FuncUpJumpRule, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_JUMP_RULE));
	statics::SetFuncAddr(FuncUpLerpPercent, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_LERP_PERCENT));
	statics::SetFuncAddr(FuncUpLerpTiles, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_LERP_TILES));
	statics::SetFuncAddr(FuncUpLogData, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_LOG_DATA));
	statics::SetFuncAddr(FuncUpModifyEscrow, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_MODIFY_ESCROW));
	statics::SetFuncAddr(FuncUpModifyFlag, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_MODIFY_FLAG));
	statics::SetFuncAddr(FuncUpModifyGoal, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_MODIFY_GOAL));
	statics::SetFuncAddr(FuncUpModifyGroupFlag, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_MODIFY_GROUP_FLAG));
	statics::SetFuncAddr(FuncUpModifySn, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_MODIFY_SN));
	statics::SetFuncAddr(FuncUpReleaseEscrow, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_RELEASE_ESCROW));
	statics::SetFuncAddr(FuncUpRemoveObjects, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_REMOVE_OBJECTS));
	statics::SetFuncAddr(FuncUpRequestHunters, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_REQUEST_HUNTERS));
	statics::SetFuncAddr(FuncUpResearch, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_RESEARCH));
	statics::SetFuncAddr(FuncUpResetAttackNow, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_RESET_ATTACK_NOW));
	statics::SetFuncAddr(FuncUpResetBuilding, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_RESET_BUILDING));
	statics::SetFuncAddr(FuncUpResetCostData, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_RESET_COST_DATA));
	statics::SetFuncAddr(FuncUpResetFilters, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_RESET_FILTERS));
	statics::SetFuncAddr(FuncUpResetGroup, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_RESET_GROUP));
	statics::SetFuncAddr(FuncUpResetPlacement, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_RESET_PLACEMENT));
	statics::SetFuncAddr(FuncUpResetScouts, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_RESET_SCOUTS));
	statics::SetFuncAddr(FuncUpResetSearch, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_RESET_SEARCH));
	statics::SetFuncAddr(FuncUpResetTargetPriorities, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_RESET_TARGET_PRIORITIES));
	statics::SetFuncAddr(FuncUpResetUnit, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_RESET_UNIT));
	statics::SetFuncAddr(FuncUpRetaskGatherers, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_RETASK_GATHERERS));
	statics::SetFuncAddr(FuncUpRetreatNow, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_RETREAT_NOW));
	statics::SetFuncAddr(FuncUpRetreatTo, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_RETREAT_TO));
	statics::SetFuncAddr(FuncUpSellCommodity, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_SELL_COMMODITY));
	statics::SetFuncAddr(FuncUpSendFlare, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_SEND_FLARE));
	statics::SetFuncAddr(FuncUpSendScout, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_SEND_SCOUT));
	statics::SetFuncAddr(FuncUpSetAttackStance, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_SET_ATTACK_STANCE));
	statics::SetFuncAddr(FuncUpSetDefensePriority, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_SET_DEFENSE_PRIORITY));
	statics::SetFuncAddr(FuncUpSetEvent, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_SET_EVENT));
	statics::SetFuncAddr(FuncUpSetGroup, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_SET_GROUP));
	statics::SetFuncAddr(FuncUpSetIndirectGoal, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_SET_INDIRECT_GOAL));
	statics::SetFuncAddr(FuncUpSetOffensePriority, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_SET_OFFENSE_PRIORITY));
	statics::SetFuncAddr(FuncUpSetPlacementData, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_SET_PLACEMENT_DATA));
	statics::SetFuncAddr(FuncUpSetPreciseTargetPoint, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_SET_PRECISE_TARGET_POINT));
	statics::SetFuncAddr(FuncUpSetSharedGoal, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_SET_SHARED_GOAL));
	statics::SetFuncAddr(FuncUpSetSignal, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_SET_SIGNAL));
	statics::SetFuncAddr(FuncUpSetTargetById, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_SET_TARGET_BY_ID));
	statics::SetFuncAddr(FuncUpSetTargetObject, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_SET_TARGET_OBJECT));
	statics::SetFuncAddr(FuncUpSetTargetPoint, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_SET_TARGET_POINT));
	statics::SetFuncAddr(FuncUpSetTimer, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_SET_TIMER));
	statics::SetFuncAddr(FuncUpSetupCostData, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_SETUP_COST_DATA));
	statics::SetFuncAddr(FuncUpStoreMapName, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_STORE_MAP_NAME));
	statics::SetFuncAddr(FuncUpStoreObjectName, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_STORE_OBJECT_NAME));
	statics::SetFuncAddr(FuncUpStorePlayerChat, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_STORE_PLAYER_CHAT));
	statics::SetFuncAddr(FuncUpStorePlayerName, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_STORE_PLAYER_NAME));
	statics::SetFuncAddr(FuncUpStoreTechName, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_STORE_TECH_NAME));
	statics::SetFuncAddr(FuncUpStoreText, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_STORE_TEXT));
	statics::SetFuncAddr(FuncUpStoreTypeName, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_STORE_TYPE_NAME));
	statics::SetFuncAddr(FuncUpTargetObjects, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_TARGET_OBJECTS));
	statics::SetFuncAddr(FuncUpTargetPoint, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_TARGET_POINT));
	statics::SetFuncAddr(FuncUpTrain, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_TRAIN));
	statics::SetFuncAddr(FuncUpTributeToPlayer, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_TRIBUTE_TO_PLAYER));
	statics::SetFuncAddr(FuncUpUngarrison, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_UNGARRISON));
	statics::SetFuncAddr(FuncUpUpdateTargets, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_UPDATE_TARGETS));
#if defined GAME_DE
	statics::SetFuncAddr(FuncChatDebug, statics::TranslateAddr(expert_conf::ADDR_FUNC_CHAT_DEBUG));
	statics::SetFuncAddr(FuncFeBreakPoint, statics::TranslateAddr(expert_conf::ADDR_FUNC_FE_BREAK_POINT));
	statics::SetFuncAddr(FuncSkyboxClearSignal, statics::TranslateAddr(expert_conf::ADDR_FUNC_SKYBOX_CLEAR_SIGNAL));
	statics::SetFuncAddr(FuncSkyboxSetNameMode, statics::TranslateAddr(expert_conf::ADDR_FUNC_SKYBOX_SET_NAME_MODE));
	statics::SetFuncAddr(FuncUpChatDataToAllUsingId, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_CHAT_DATA_TO_ALL_USING_ID));
	statics::SetFuncAddr(FuncUpChatDataToPlayerUsingId, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_CHAT_DATA_TO_PLAYER_USING_ID));
	statics::SetFuncAddr(FuncUpGetTreatyData, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_TREATY_DATA));
	statics::SetFuncAddr(FuncUpTestharnessReport, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_TESTHARNESS_REPORT));
	statics::SetFuncAddr(FuncUpTestharnessTest, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_TESTHARNESS_TEST));
#elif defined GAME_AOC
	statics::SetFuncAddr(FuncUpGetAlliedTarget, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_ALLIED_TARGET));
	statics::SetFuncAddr(FuncUpGetGuardState, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_GUARD_STATE));
	statics::SetFuncAddr(FuncUpGetUpgradeId, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_UPGRADE_ID));
	statics::SetFuncAddr(FuncUpOutOfSync, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_OUT_OF_SYNC));

	// WK quickfix
	if (*(int8_t*)FuncUpGetObjectData != 0x8B)
	{
		statics::SetFuncAddr(FuncUpGetObjectData, (uintptr_t)FuncUpGetObjectData + 0x44);
	}
#endif
}

void ExpertAction::EnableDetours()
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)FuncGetString, DetouredGetString);
	DetourTransactionCommit();
}

void ExpertAction::DisableDetours()
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourDetach(&(PVOID&)FuncGetString, DetouredGetString);
	DetourTransactionCommit();
}

#if defined GAME_DE
char* ExpertAction::DetouredGetString(void* aiExpertEngine, int stringId)
#elif defined GAME_AOC
char* __fastcall ExpertAction::DetouredGetString(void* aiExpertEngine, void* unused, int stringId)
#endif
{
	if (stringId == expert_conf::CONST_CUSTOM_STRING_ID)
		return customString;

	return FuncGetString(aiExpertEngine, stringId);
}

void ExpertAction::SetCustomString(const std::string& inTextString)
{
	snprintf(customString, sizeof(customString), "%s", inTextString.c_str());
}

void ExpertAction::AcknowledgeEvent(int inConstEventType, int inConstEventId)
{
	FuncAcknowledgeEvent(inConstEventType, inConstEventId);
}

void ExpertAction::AcknowledgeTaunt(int inPlayerAnyPlayer, int inConstTauntId)
{
	FuncAcknowledgeTaunt(inPlayerAnyPlayer, inConstTauntId);
}

void ExpertAction::AttackNow()
{
	FuncAttackNow();
}

void ExpertAction::Build(int inConstBuildingId)
{
	if (ExpertFact::CanBuildWithEscrow(inConstBuildingId))
	{
		FuncBuild(inConstBuildingId);
	}
}

void ExpertAction::BuildForward(int inConstBuildingId)
{
	if (ExpertFact::CanBuildWithEscrow(inConstBuildingId))
	{
		FuncBuildForward(inConstBuildingId);
	}
}

void ExpertAction::BuildGate(int inConstPerimeter)
{
	if (ExpertFact::CanBuildGateWithEscrow(inConstPerimeter))
	{
		FuncBuildGate(inConstPerimeter);
	}
}

void ExpertAction::BuildWall(int inConstPerimeter, int inConstWallId)
{
	if (ExpertFact::CanBuildWallWithEscrow(inConstPerimeter, inConstWallId))
	{
		FuncBuildWall(inConstPerimeter, inConstWallId);
	}
}

void ExpertAction::BuyCommodity(int inConstCommodity)
{
	if (ExpertFact::CanBuyCommodity(inConstCommodity))
	{
		FuncBuyCommodity(inConstCommodity);
	}
}

void ExpertAction::CcAddResource(int inConstResource, int inConstValue)
{
	FuncCcAddResource(inConstResource, inConstValue);
}

void ExpertAction::ChatLocal(const std::string& inTextString)
{
	SetCustomString(inTextString);
	FuncChatLocal(expert_conf::CONST_CUSTOM_STRING_ID);
}

void ExpertAction::ChatLocalUsingId(int inConstLanguageId)
{
	FuncChatLocalUsingId(inConstLanguageId);
}

void ExpertAction::ChatLocalUsingRange(int inConstLanguageId, int inConstValue)
{
	if (inConstValue != 0) // crashes otherwise
	{
		FuncChatLocalUsingRange(inConstLanguageId, inConstValue);
	}
}

void ExpertAction::ChatLocalToSelf(const std::string& inTextString)
{
	SetCustomString(inTextString);
	FuncChatLocalToSelf(expert_conf::CONST_CUSTOM_STRING_ID);
}

void ExpertAction::ChatToAll(const std::string& inTextString)
{
	SetCustomString(inTextString);
	FuncChatToAll(expert_conf::CONST_CUSTOM_STRING_ID);
}

void ExpertAction::ChatToAllUsingId(int inConstLanguageId)
{
	FuncChatToAllUsingId(inConstLanguageId);
}

void ExpertAction::ChatToAllUsingRange(int inConstLanguageId, int inConstValue)
{
	if (inConstValue != 0) // crashes otherwise
	{
		FuncChatToAllUsingRange(inConstLanguageId, inConstValue);
	}
}

void ExpertAction::ChatToAllies(const std::string& inTextString)
{
	SetCustomString(inTextString);
	FuncChatToAllies(expert_conf::CONST_CUSTOM_STRING_ID);
}

void ExpertAction::ChatToAlliesUsingId(int inConstLanguageId)
{
	FuncChatToAlliesUsingId(inConstLanguageId);
}

void ExpertAction::ChatToAlliesUsingRange(int inConstLanguageId, int inConstValue)
{
	if (inConstValue != 0) // crashes otherwise
	{
		FuncChatToAlliesUsingRange(inConstLanguageId, inConstValue);
	}
}

void ExpertAction::ChatToEnemies(const std::string& inTextString)
{
	SetCustomString(inTextString);
	FuncChatToEnemies(expert_conf::CONST_CUSTOM_STRING_ID);
}

void ExpertAction::ChatToEnemiesUsingId(int inConstLanguageId)
{
	FuncChatToEnemiesUsingId(inConstLanguageId);
}

void ExpertAction::ChatToEnemiesUsingRange(int inConstLanguageId, int inConstValue)
{
	if (inConstValue != 0) // crashes otherwise
	{
		FuncChatToEnemiesUsingRange(inConstLanguageId, inConstValue);
	}
}

void ExpertAction::ChatToPlayer(int inPlayerAnyPlayer, const std::string& inTextString)
{
	SetCustomString(inTextString);
	FuncChatToPlayer(inPlayerAnyPlayer, expert_conf::CONST_CUSTOM_STRING_ID);
}

void ExpertAction::ChatToPlayerUsingId(int inPlayerAnyPlayer, int inConstLanguageId)
{
	FuncChatToPlayerUsingId(inPlayerAnyPlayer, inConstLanguageId);
}

void ExpertAction::ChatToPlayerUsingRange(int inPlayerAnyPlayer, int inConstLanguageId, int inConstValue)
{
	if (inConstValue != 0) // crashes otherwise
	{
		FuncChatToPlayerUsingRange(inPlayerAnyPlayer, inConstLanguageId, inConstValue);
	}
}

void ExpertAction::ChatTrace(int inConstValue)
{
	FuncChatTrace(inConstValue);
}

void ExpertAction::ClearTributeMemory(int inPlayerAnyPlayer, int inConstResource)
{
	FuncClearTributeMemory(inPlayerAnyPlayer, inConstResource);
}

void ExpertAction::DeleteBuilding(int inConstBuildingId)
{
	FuncDeleteBuilding(inConstBuildingId);
}

void ExpertAction::DeleteUnit(int inConstUnitId)
{
	FuncDeleteUnit(inConstUnitId);
}

void ExpertAction::DisableRule(int inConstRuleGroupId)
{
	FuncDisableRule(inConstRuleGroupId);
}

void ExpertAction::DisableSelf()
{
	FuncDisableSelf();
}

void ExpertAction::DisableTimer(int inConstTimerId)
{
	if (inConstTimerId != 0) // can crash otherwise
	{
		FuncDisableTimer(inConstTimerId);
	}
}

void ExpertAction::DoNothing()
{
	
}

void ExpertAction::EnableRule(int inConstRuleGroupId)
{
	FuncEnableRule(inConstRuleGroupId);
}

void ExpertAction::EnableTimer(int inConstTimerId, int inConstValue)
{
#if defined GAME_AOC
	if (inConstValue != 0) // crashes otherwise
#endif
	{
		FuncEnableTimer(inConstTimerId, inConstValue);
	}
}

void ExpertAction::EnableWallPlacement(int inConstPerimeter)
{
	FuncEnableWallPlacement(inConstPerimeter);
}

void ExpertAction::GenerateRandomNumber(int inConstValue)
{
	if (inConstValue != 0) // crashes otherwise
	{
		FuncGenerateRandomNumber(inConstValue);
	}
}

void ExpertAction::Log(const std::string& inTextString)
{
	SetCustomString(inTextString);
	FuncLog(expert_conf::CONST_CUSTOM_STRING_ID);
}

void ExpertAction::LogTrace(int inConstValue)
{
	FuncLogTrace(inConstValue);
}

void ExpertAction::ReleaseEscrow(int inConstResource)
{
	FuncReleaseEscrow(inConstResource);
}

void ExpertAction::Research(int inConstTechId)
{
	if (ExpertFact::CanResearchWithEscrow(inConstTechId)) // fixes a potential crash, at least in aoc
	{
		FuncResearch(inConstTechId);
	}
}

void ExpertAction::Resign()
{
	FuncResign();
}

void ExpertAction::SellCommodity(int inConstCommodity)
{
	if (ExpertFact::CanSellCommodity(inConstCommodity))
	{
		FuncSellCommodity(inConstCommodity);
	}
}

void ExpertAction::SetAuthorName(const std::string& inTextString)
{
	
}

void ExpertAction::SetAuthorEmail(const std::string& inTextString)
{
	
}

void ExpertAction::SetAuthorVersion(const std::string& inTextString)
{
	
}

void ExpertAction::SetDifficultyParameter(int inConstDiffParameterId, int inConstValue)
{
	FuncSetDifficultyParameter(inConstDiffParameterId, inConstValue);
}

void ExpertAction::SetDoctrine(int inConstValue)
{
	FuncSetDoctrine(inConstValue);
}

void ExpertAction::SetEscrowPercentage(int inConstResource, int inConstValue)
{
	FuncSetEscrowPercentage(inConstResource, inConstValue);
}

void ExpertAction::SetGoal(int inConstGoalId, int inConstValue)
{
	FuncSetGoal(inConstGoalId, inConstValue);
}

void ExpertAction::SetSharedGoal(int inConstGoalId, int inConstValue)
{
	FuncSetSharedGoal(inConstGoalId, inConstValue);
}

void ExpertAction::SetSignal(int inConstSignalId)
{
	FuncSetSignal(inConstSignalId);
}

void ExpertAction::SetStance(int inPlayerAnyPlayer, int inConstESPlayerStance)
{
	FuncSetStance(inPlayerAnyPlayer, inConstESPlayerStance);
}

void ExpertAction::SetStrategicNumber(int inConstSnId, int inConstValue)
{
	FuncSetStrategicNumber(inConstSnId, inConstValue);
}

void ExpertAction::Spy()
{
	if (ExpertFact::CanSpyWithEscrow())
	{
		FuncSpy();
	}
}

void ExpertAction::Taunt(int inConstTauntId)
{
	FuncTaunt(inConstTauntId);
}

void ExpertAction::TauntUsingRange(int inConstTauntId, int inConstValue)
{
	if (inConstValue != 0) // crashes otherwise
	{
		FuncTauntUsingRange(inConstTauntId, inConstValue);
	}
}

void ExpertAction::Train(int inConstUnitId)
{
	if (ExpertFact::CanTrainWithEscrow(inConstUnitId))
	{
		FuncTrain(inConstUnitId);
	}
}

void ExpertAction::TributeToPlayer(int inPlayerAnyPlayer, int inConstResource, int inConstValue)
{
	FuncTributeToPlayer(inPlayerAnyPlayer, inConstResource, inConstValue);
}

void ExpertAction::UpAddCostData(int inGoalId, int typeOp, int inOpValue)
{
	FuncUpAddCostData(inGoalId, typeOp, inOpValue);
}

void ExpertAction::UpAddObjectById(int inConstSearchSource, int typeOp, int inOpId)
{
	FuncUpAddObjectById(inConstSearchSource, typeOp, inOpId);
}

void ExpertAction::UpAddObjectCost(int typeOp1, int inOp1ObjectId, int typeOp2, int inOp2Value)
{
	FuncUpAddObjectCost(typeOp1, inOp1ObjectId, typeOp2, inOp2Value);
}

void ExpertAction::UpAddPoint(int inGoalPoint1, int inGoalPoint2, int typeOp, int inOpCount)
{
	FuncUpAddPoint(inGoalPoint1, inGoalPoint2, typeOp, inOpCount);
}

void ExpertAction::UpAddResearchCost(int typeOp1, int inOp1TechId, int typeOp2, int inOp2Value)
{
	FuncUpAddResearchCost(typeOp1, inOp1TechId, typeOp2, inOp2Value);
}

void ExpertAction::UpAssignBuilders(int typeOp1, int inOp1BuildingId, int typeOp2, int inOp2Value)
{
	FuncUpAssignBuilders(typeOp1, inOp1BuildingId, typeOp2, inOp2Value);
}

void ExpertAction::UpBoundPoint(int inGoalPoint1, int inGoalPoint2)
{
	FuncUpBoundPoint(inGoalPoint1, inGoalPoint2);
}

void ExpertAction::UpBoundPrecisePoint(int inGoalPoint, int inConstPrecise, int typeOp, int inOpBorder)
{
	FuncUpBoundPrecisePoint(inGoalPoint, inConstPrecise, typeOp, inOpBorder);
}

void ExpertAction::UpBuild(int inConstPlacementType, int inGoalEscrowState, int typeOp, int inOpBuildingId)
{
	if (ExpertFact::UpCanBuild(inGoalEscrowState, typeOp, inOpBuildingId))
	{
		FuncUpBuild(inConstPlacementType, inGoalEscrowState, typeOp, inOpBuildingId);
	}
}

void ExpertAction::UpBuildLine(int inGoalPoint1, int inGoalPoint2, int typeOp, int inOpBuildingId)
{
	int cachedGoal = ExpertFact::Goal(512);
	ExpertAction::SetGoal(512, 0); // with-escrow

	if (ExpertFact::UpCanBuildLine(512, inGoalPoint1, typeOp, inOpBuildingId))
	{
		ExpertAction::SetGoal(512, cachedGoal);
		FuncUpBuildLine(inGoalPoint1, inGoalPoint2, typeOp, inOpBuildingId);
		return;
	}

	ExpertAction::SetGoal(512, cachedGoal);
}

void ExpertAction::UpBuyCommodity(int typeOp1, int inOp1ResourceAmount, int typeOp2, int inOp2Value)
{
	FuncUpBuyCommodity(typeOp1, inOp1ResourceAmount, typeOp2, inOp2Value);
}

void ExpertAction::UpCcAddResource(int typeOp1, int inOp1ResourceAmount, int typeOp2, int inOp2Value)
{
	FuncUpCcAddResource(typeOp1, inOp1ResourceAmount, typeOp2, inOp2Value);
}

void ExpertAction::UpCcSendCheat(const std::string& inTextCode)
{
	SetCustomString(inTextCode);
	FuncUpCcSendCheat(expert_conf::CONST_CUSTOM_STRING_ID);
}

void ExpertAction::UpChangeName(const std::string& inTextNewName)
{
	SetCustomString(inTextNewName);
	FuncUpChangeName(expert_conf::CONST_CUSTOM_STRING_ID);
}

void ExpertAction::UpChatDataToAll(const std::string& inTextFormattedString, int typeOp, int inOpValue)
{
	SetCustomString(inTextFormattedString);
	FuncUpChatDataToAll(expert_conf::CONST_CUSTOM_STRING_ID, typeOp, inOpValue);
}

void ExpertAction::UpChatDataToPlayer(int inPlayerAnyPlayer, const std::string& inTextFormattedString, int typeOp, int inOpValue)
{
	SetCustomString(inTextFormattedString);
	FuncUpChatDataToPlayer(inPlayerAnyPlayer, expert_conf::CONST_CUSTOM_STRING_ID, typeOp, inOpValue);
}

void ExpertAction::UpChatDataToSelf(const std::string& inTextFormattedString, int typeOp, int inOpValue)
{
	SetCustomString(inTextFormattedString);
	FuncUpChatDataToSelf(expert_conf::CONST_CUSTOM_STRING_ID, typeOp, inOpValue);
}

void ExpertAction::UpCleanSearch(int inConstSearchSource, int inConstObjectData, int inConstSearchOrder)
{
#if defined GAME_DE
	if (inConstSearchSource != 0) // crashes otherwise
#endif
	{
		FuncUpCleanSearch(inConstSearchSource, inConstObjectData, inConstSearchOrder);
	}
}

void ExpertAction::UpCopyPoint(int outGoalPoint, int inGoalPoint)
{
	FuncUpCopyPoint(outGoalPoint, inGoalPoint);
}

void ExpertAction::UpCreateGroup(int inGoalIndex, int inGoalCount, int typeOp, int inOpGroupId)
{
	FuncUpCreateGroup(inGoalIndex, inGoalCount, typeOp, inOpGroupId);
}

void ExpertAction::UpCrossTiles(int ioGoalPoint, int inGoalPoint, int typeOp, int inOpTiles)
{
	FuncUpCrossTiles(ioGoalPoint, inGoalPoint, typeOp, inOpTiles);
}

void ExpertAction::UpDeleteDistantFarms(int typeOp, int inOpValue)
{
	FuncUpDeleteDistantFarms(typeOp, inOpValue);
}

void ExpertAction::UpDeleteIdleUnits(int inConstIdleType)
{
	FuncUpDeleteIdleUnits(inConstIdleType);
}

void ExpertAction::UpDeleteObjects(int typeOp1, int inOpUnitId, int typeOp2, int inOpHitPoints)
{
	FuncUpDeleteObjects(typeOp1, inOpUnitId, typeOp2, inOpHitPoints);
}

void ExpertAction::UpDisbandGroupType(int inConstGroupType)
{
	FuncUpDisbandGroupType(inConstGroupType);
}

void ExpertAction::UpDropResources(int inConstResource, int typeOp, int inOpValue)
{
	FuncUpDropResources(inConstResource, typeOp, inOpValue);
}

void ExpertAction::UpFilterDistance(int typeOp1, int inOp1MinDistance, int typeOp2, int inOp2MaxDistance)
{
	FuncUpFilterDistance(typeOp1, inOp1MinDistance, typeOp2, inOp2MaxDistance);
}

void ExpertAction::UpFilterExclude(int inConstCmdId, int inConstActionId, int inConstOrderId, int inConstClassId)
{
	FuncUpFilterExclude(inConstCmdId, inConstActionId, inConstOrderId, inConstClassId);
}

void ExpertAction::UpFilterGarrison(int typeOp1, int inOp1MinGarrison, int typeOp2, int inOp2MaxGarrison)
{
	FuncUpFilterGarrison(typeOp1, inOp1MinGarrison, typeOp2, inOp2MaxGarrison);
}

void ExpertAction::UpFilterInclude(int inConstCmdId, int inConstActionId, int inConstOrderId, int inConstOnMainland)
{
	FuncUpFilterInclude(inConstCmdId, inConstActionId, inConstOrderId, inConstOnMainland);
}

void ExpertAction::UpFilterRange(int inConstMinGarrison, int inConstMaxGarrison, int inConstMinDistance, int inConstMaxDistance)
{
	FuncUpFilterRange(inConstMinGarrison, inConstMaxGarrison, inConstMinDistance, inConstMaxDistance);
}

void ExpertAction::UpFilterStatus(int typeOp1, int inOp1ObjectStatus, int typeOp2, int inOp2ObjectList)
{
	FuncUpFilterStatus(typeOp1, inOp1ObjectStatus, typeOp2, inOp2ObjectList);
}

void ExpertAction::UpFindFlare(int outGoalPoint)
{
	FuncUpFindFlare(outGoalPoint);
}

void ExpertAction::UpFindLocal(int typeOp1, int inOp1UnitId, int typeOp2, int inOp2Count)
{
	FuncUpFindLocal(typeOp1, inOp1UnitId, typeOp2, inOp2Count);
}

void ExpertAction::UpFindNextPlayer(int inConstPlayerStance, int inConstFindPlayerMethod, int ioGoalPlayerId)
{
	FuncUpFindNextPlayer(inConstPlayerStance, inConstFindPlayerMethod, ioGoalPlayerId);
}

void ExpertAction::UpFindPlayer(int inConstPlayerStance, int inConstFindPlayerMethod, int outGoalPlayerId)
{
	FuncUpFindPlayer(inConstPlayerStance, inConstFindPlayerMethod, outGoalPlayerId);
}

void ExpertAction::UpFindPlayerFlare(int inPlayerAnyPlayer, int outGoalPoint)
{
#if defined GAME_AOC
	if (outGoalPoint >= 40 && outGoalPoint <= 510) // crashes otherwise
#endif
	{
		FuncUpFindPlayerFlare(inPlayerAnyPlayer, outGoalPoint);
	}
}

void ExpertAction::UpFindRemote(int typeOp1, int inOp1UnitId, int typeOp2, int inOp2Count)
{
	FuncUpFindRemote(typeOp1, inOp1UnitId, typeOp2, inOp2Count);
}

void ExpertAction::UpFindResource(int typeOp1, int inOp1Resource, int typeOp2, int inOp2Count)
{
	FuncUpFindResource(typeOp1, inOp1Resource, typeOp2, inOp2Count);
}

void ExpertAction::UpFindStatusLocal(int typeOp1, int inOp1UnitId, int typeOp2, int inOp2Count)
{
	FuncUpFindStatusLocal(typeOp1, inOp1UnitId, typeOp2, inOp2Count);
}

void ExpertAction::UpFindStatusRemote(int typeOp1, int inOp1UnitId, int typeOp2, int inOp2Count)
{
	FuncUpFindStatusRemote(typeOp1, inOp1UnitId, typeOp2, inOp2Count);
}

void ExpertAction::UpFullResetSearch()
{
	FuncUpFullResetSearch();
}

void ExpertAction::UpGarrison(int inConstObjectId, int typeOp, int inOpUnitId)
{
	FuncUpGarrison(inConstObjectId, typeOp, inOpUnitId);
}

void ExpertAction::UpGatherInside(int typeOp1, int inOp1BuildingId, int typeOp2, int inOp2State)
{
	FuncUpGatherInside(typeOp1, inOp1BuildingId, typeOp2, inOp2State);
}

void ExpertAction::UpGetAttackerClass(int outGoalSourceClass)
{
	FuncUpGetAttackerClass(outGoalSourceClass);
}

void ExpertAction::UpGetCostDelta(int outGoalId)
{
	FuncUpGetCostDelta(outGoalId);
}

void ExpertAction::UpGetEvent(int typeOp, int inOpEventId, int outGoalValue)
{
	FuncUpGetEvent(typeOp, inOpEventId, outGoalValue);
}

void ExpertAction::UpGetFact(int inConstFactId, int inConstParam, int outGoalData)
{
	FuncUpGetFact(inConstFactId, inConstParam, outGoalData);
}

void ExpertAction::UpGetFactMax(int player, int factId, int param, int goalData)
{
	FuncUpGetFactMax(player, factId, param, goalData);
}

void ExpertAction::UpGetFactMin(int inPlayerAnyPlayer, int inConstFactId, int inConstParam, int outGoalData)
{
	FuncUpGetFactMin(inPlayerAnyPlayer, inConstFactId, inConstParam, outGoalData);
}

void ExpertAction::UpGetFactSum(int inPlayerAnyPlayer, int inConstFactId, int inConstParam, int outGoalData)
{
	FuncUpGetFactSum(inPlayerAnyPlayer, inConstFactId, inConstParam, outGoalData);
}

void ExpertAction::UpGetFocusFact(int inConstFactId, int inConstParam, int outGoalData)
{
	FuncUpGetFocusFact(inConstFactId, inConstParam, outGoalData);
}

void ExpertAction::UpGetGroupSize(int typeOp, int inOpGroupId, int outGoalSize)
{
	FuncUpGetGroupSize(typeOp, inOpGroupId, outGoalSize);
}

void ExpertAction::UpGetIndirectGoal(int typeOp, int inOpGoalId, int outGoalValue)
{
	FuncUpGetIndirectGoal(typeOp, inOpGoalId, outGoalValue);
}

void ExpertAction::UpGetObjectData(int inConstObjectData, int outGoalData)
{
	FuncUpGetObjectData(inConstObjectData, outGoalData);
}

void ExpertAction::UpGetObjectTargetData(int inConstObjectData, int outGoalData)
{
	FuncUpGetObjectTargetData(inConstObjectData, outGoalData);
}

void ExpertAction::UpGetObjectTypeData(int typeOp, int inOpTypeId, int inConstObjectData, int outGoalData)
{
	FuncUpGetObjectTypeData(typeOp, inOpTypeId, inConstObjectData, outGoalData);
}

void ExpertAction::UpGetPathDistance(int inGoalPoint, int inConstStrict, int outGoalData)
{
	FuncUpGetPathDistance(inGoalPoint, inConstStrict, outGoalData);
}

void ExpertAction::UpGetPlayerColor(int inPlayerAnyPlayer, int outGoalColorId)
{
	FuncUpGetPlayerColor(inPlayerAnyPlayer, outGoalColorId);
}

void ExpertAction::UpGetPlayerFact(int inPlayerAnyPlayer, int inConstFactId, int inConstParam, int outGoalData)
{
	FuncUpGetPlayerFact(inPlayerAnyPlayer, inConstFactId, inConstParam, outGoalData);
}

void ExpertAction::UpGetPoint(int inConstPositionType, int outGoalPoint)
{
	FuncUpGetPoint(inConstPositionType, outGoalPoint);
}

void ExpertAction::UpGetPointContains(int inGoalPoint, int outGoalGoalId, int typeOp, int inOpObjectId)
{
	FuncUpGetPointContains(inGoalPoint, outGoalGoalId, typeOp, inOpObjectId);
}

void ExpertAction::UpGetPointDistance(int inGoalPoint1, int inGoalPoint2, int outGoalDistance)
{
	FuncUpGetPointDistance(inGoalPoint1, inGoalPoint2, outGoalDistance);
}

void ExpertAction::UpGetPointElevation(int inGoalPoint, int outGoalData)
{
	FuncUpGetPointElevation(inGoalPoint, outGoalData);
}

void ExpertAction::UpGetPointTerrain(int inGoalPoint, int outGoalTerrain)
{
	FuncUpGetPointTerrain(inGoalPoint, outGoalTerrain);
}

void ExpertAction::UpGetPointZone(int inGoalPoint, int outGoalData)
{
	FuncUpGetPointZone(inGoalPoint, outGoalData);
}

void ExpertAction::UpGetPreciseTime(int inGoalStart, int outGoalTime)
{
	FuncUpGetPreciseTime(inGoalStart, outGoalTime);
}

void ExpertAction::UpGetProjectilePlayer(int inConstProjectileType, int outGoalPlayerId)
{
	FuncUpGetProjectilePlayer(inConstProjectileType, outGoalPlayerId);
}

void ExpertAction::UpGetRuleId(int outGoalRuleId)
{
	FuncUpGetRuleId(outGoalRuleId);
}

void ExpertAction::UpGetSearchState(int outGoalState)
{
	FuncUpGetSearchState(outGoalState);
}

void ExpertAction::UpGetSharedGoal(int typeOp, int inOpSharedGoalId, int outGoalValue)
{
	FuncUpGetSharedGoal(typeOp, inOpSharedGoalId, outGoalValue);
}

void ExpertAction::UpGetSignal(int typeOp, int inOpSignalId, int outGoalValue)
{
	FuncUpGetSignal(typeOp, inOpSignalId, outGoalValue);
}

void ExpertAction::UpGetTargetFact(int inConstFactId, int inConstParam, int outGoalData)
{
	FuncUpGetTargetFact(inConstFactId, inConstParam, outGoalData);
}

void ExpertAction::UpGetThreatData(int outGoalElapsedTime, int outGoalPlayerId, int outGoalSourceClass, int outGoalTargetClass)
{
	FuncUpGetThreatData(outGoalElapsedTime, outGoalPlayerId, outGoalSourceClass, outGoalTargetClass);
}

void ExpertAction::UpGetTimer(int typeOp, int inOpTimerId, int outGoalValue)
{
	FuncUpGetTimer(typeOp, inOpTimerId, outGoalValue);
}

void ExpertAction::UpGetVictoryData(int outGoalPlayerId, int outGoalType, int outGoalTime)
{
	FuncUpGetVictoryData(outGoalPlayerId, outGoalType, outGoalTime);
}

void ExpertAction::UpGetVictoryLimit(int outGoalLimit)
{
	FuncUpGetVictoryLimit(outGoalLimit);
}

void ExpertAction::UpGuardUnit(int inConstObjectId, int typeOp, int inOpUnitId)
{
	FuncUpGuardUnit(inConstObjectId, typeOp, inOpUnitId);
}

void ExpertAction::UpJumpDirect(int typeOp, int inOpRuleId)
{
	// crashes with invalid paramters, currently unneeded
	//FuncUpJumpDirect(typeOp, inOpRuleId);
}

void ExpertAction::UpJumpDynamic(int typeOp, int inOpRuleDelta)
{
	// crashes with invalid paramters, currently unneeded
	//FuncUpJumpDynamic(typeOp, inOpRuleDelta);
}

void ExpertAction::UpJumpRule(int inConstRuleDelta)
{
	// crashes with invalid paramters, currently unneeded
	//FuncUpJumpRule(inConstRuleDelta);
}

void ExpertAction::UpLerpPercent(int ioGoalPoint, int inGoalPoint, int typeOp, int inOpPercent)
{
	FuncUpLerpPercent(ioGoalPoint, inGoalPoint, typeOp, inOpPercent);
}

void ExpertAction::UpLerpTiles(int ioGoalPoint, int inGoalPoint, int typeOp, int inOpTiles)
{
	FuncUpLerpTiles(ioGoalPoint, inGoalPoint, typeOp, inOpTiles);
}

void ExpertAction::UpLogData(int inConstPlain, const std::string& inTextFormattedString, int typeOp, int inOpValue)
{
	SetCustomString(inTextFormattedString);
	FuncUpLogData(inConstPlain, expert_conf::CONST_CUSTOM_STRING_ID, typeOp, inOpValue);
}

void ExpertAction::UpModifyEscrow(int inConstResource, int mathOp, int inOpValue)
{
	FuncUpModifyEscrow(inConstResource, mathOp, inOpValue);
}

void ExpertAction::UpModifyFlag(int ioGoalId, int mathOp, int inOpFlag)
{
	FuncUpModifyFlag(ioGoalId, mathOp, inOpFlag);
}

void ExpertAction::UpModifyGoal(int ioGoalId, int mathOp, int inOpValue)
{
	FuncUpModifyGoal(ioGoalId, mathOp, inOpValue);
}

void ExpertAction::UpModifyGroupFlag(int inConstOn, int typeOp, int inOpGroupId)
{
	FuncUpModifyGroupFlag(inConstOn, typeOp, inOpGroupId);
}

void ExpertAction::UpModifySn(int ioSnId, int mathOp, int inOpValue)
{
	FuncUpModifySn(ioSnId, mathOp, inOpValue);
}

void ExpertAction::UpReleaseEscrow()
{
	FuncUpReleaseEscrow();
}

void ExpertAction::UpRemoveObjects(int inConstSearchSource, int inConstObjectData, int typeOp, int inOpValue)
{
	FuncUpRemoveObjects(inConstSearchSource, inConstObjectData, typeOp, inOpValue);
}

void ExpertAction::UpRequestHunters(int typeOp, int inOpValue)
{
	FuncUpRequestHunters(typeOp, inOpValue);
}

void ExpertAction::UpResearch(int inGoalEscrowState, int typeOp, int inOpTechId)
{
	if (ExpertFact::UpCanResearch(inGoalEscrowState, typeOp, inOpTechId))
	{
		FuncUpResearch(inGoalEscrowState, typeOp, inOpTechId);
	}
}

void ExpertAction::UpResetAttackNow()
{
	FuncUpResetAttackNow();
}

void ExpertAction::UpResetBuilding(int inConstPreserveResearch, int typeOp, int inOpBuildingId)
{
	FuncUpResetBuilding(inConstPreserveResearch, typeOp, inOpBuildingId);
}

void ExpertAction::UpResetCostData(int outGoalId)
{
	FuncUpResetCostData(outGoalId);
}

void ExpertAction::UpResetFilters()
{
	FuncUpResetFilters();
}

void ExpertAction::UpResetGroup(int typeOp, int inOpGroupId)
{
	FuncUpResetGroup(typeOp, inOpGroupId);
}

void ExpertAction::UpResetPlacement(int typeOp, int inOpBuildingId)
{
	FuncUpResetPlacement(typeOp, inOpBuildingId);
}

void ExpertAction::UpResetScouts()
{
	FuncUpResetScouts();
}

void ExpertAction::UpResetSearch(int inConstLocalIndex, int inConstLocalList, int inConstRemoteIndex, int inConstRemoteList)
{
	FuncUpResetSearch(inConstLocalIndex, inConstLocalList, inConstRemoteIndex, inConstRemoteList);
}

void ExpertAction::UpResetTargetPriorities(int inConstPriorityType, int inConstMode)
{
	FuncUpResetTargetPriorities(inConstPriorityType, inConstMode);
}

void ExpertAction::UpResetUnit(int typeOp, int inOpUnitId)
{
	FuncUpResetUnit(typeOp, inOpUnitId);
}

void ExpertAction::UpRetaskGatherers(int inConstResource, int typeOp, int inOpValue)
{
	FuncUpRetaskGatherers(inConstResource, typeOp, inOpValue);
}

void ExpertAction::UpRetreatNow()
{
	FuncUpRetreatNow();
}

void ExpertAction::UpRetreatTo(int inConstObjectId, int typeOp, int inOpUnitId)
{
	FuncUpRetreatTo(inConstObjectId, typeOp, inOpUnitId);
}

void ExpertAction::UpSellCommodity(int typeOp1, int inOp1ResourceAmount, int typeOp2, int inOp2Value)
{
	FuncUpSellCommodity(typeOp1, inOp1ResourceAmount, typeOp2, inOp2Value);
}

void ExpertAction::UpSendFlare(int inGoalPoint)
{
	FuncUpSendFlare(inGoalPoint);
}

void ExpertAction::UpSendScout(int inConstGroupType, int inConstScoutMethod)
{
	FuncUpSendScout(inConstGroupType, inConstScoutMethod);
}

void ExpertAction::UpSetAttackStance(int inConstUnitId, int typeOp, int inOpAttackStance)
{
	FuncUpSetAttackStance(inConstUnitId, typeOp, inOpAttackStance);
}

void ExpertAction::UpSetDefensePriority(int typeOp1, int inOp1BuildingId, int typeOp2, int inOp2Value)
{
	FuncUpSetDefensePriority(typeOp1, inOp1BuildingId, typeOp2, inOp2Value);
}

void ExpertAction::UpSetEvent(int typeOp1, int inOp1EventId, int typeOp2, int inOp2Value)
{
	FuncUpSetEvent(typeOp1, inOp1EventId, typeOp2, inOp2Value);
}

void ExpertAction::UpSetGroup(int inConstSearchSource, int typeOp, int inOpGroupId)
{
	FuncUpSetGroup(inConstSearchSource, typeOp, inOpGroupId);
}

void ExpertAction::UpSetIndirectGoal(int typeOp1, int inOp1GoalId, int typeOp2, int inOp2Value)
{
	FuncUpSetIndirectGoal(typeOp1, inOp1GoalId, typeOp2, inOp2Value);
}

void ExpertAction::UpSetOffensePriority(int typeOp1, int inOp1ObjectId, int typeOp2, int inOp2Value)
{
	FuncUpSetOffensePriority(typeOp1, inOp1ObjectId, typeOp2, inOp2Value);
}

void ExpertAction::UpSetPlacementData(int inPlayerAllyPlayer, int inConstObjectId, int typeOp, int inOpValue)
{
	FuncUpSetPlacementData(inPlayerAllyPlayer, inConstObjectId, typeOp, inOpValue);
}

void ExpertAction::UpSetPreciseTargetPoint(int inGoalPoint)
{
	FuncUpSetPreciseTargetPoint(inGoalPoint);
}

void ExpertAction::UpSetSharedGoal(int typeOp1, int inOp1SharedGoalId, int typeOp2, int inOp2Value)
{
	FuncUpSetSharedGoal(typeOp1, inOp1SharedGoalId, typeOp2, inOp2Value);
}

void ExpertAction::UpSetSignal(int typeOp1, int inOp1SignalId, int typeOp2, int inOp2Value)
{
	FuncUpSetSignal(typeOp1, inOp1SignalId, typeOp2, inOp2Value);
}

void ExpertAction::UpSetTargetById(int typeOp, int inOpId)
{
	FuncUpSetTargetById(typeOp, inOpId);
}

void ExpertAction::UpSetTargetObject(int inConstSearchSource, int typeOp, int inOpIndex)
{
#if defined GAME_DE
	if (inConstSearchSource != 0) // crashes otherwise
#endif
	{
		FuncUpSetTargetObject(inConstSearchSource, typeOp, inOpIndex);
	}
}

void ExpertAction::UpSetTargetPoint(int inGoalPoint)
{
	FuncUpSetTargetPoint(inGoalPoint);
}

void ExpertAction::UpSetTimer(int typeOp1, int inOp1TimerId, int typeOp2, int inOp2Value)
{
#if defined GAME_AOC
	if (inOp2Value != 0) // crashes otherwise
#endif
	{
		FuncUpSetTimer(typeOp1, inOp1TimerId, typeOp2, inOp2Value);
	}
}

void ExpertAction::UpSetupCostData(int inConstResetCost, int ioGoalId)
{
	FuncUpSetupCostData(inConstResetCost, ioGoalId);
}

void ExpertAction::UpStoreMapName(int inConstExtension)
{
	FuncUpStoreMapName(inConstExtension);
}

void ExpertAction::UpStoreObjectName()
{
	FuncUpStoreObjectName();
}

void ExpertAction::UpStorePlayerChat(int inPlayerAnyPlayer)
{
	FuncUpStorePlayerChat(inPlayerAnyPlayer);
}

void ExpertAction::UpStorePlayerName(int inPlayerAnyPlayer)
{
	FuncUpStorePlayerName(inPlayerAnyPlayer);
}

void ExpertAction::UpStoreTechName(int typeOp, int inOpTechId)
{
	FuncUpStoreTechName(typeOp, inOpTechId);
}

void ExpertAction::UpStoreText(int typeOp, int inOpLanguageId)
{
	FuncUpStoreText(typeOp, inOpLanguageId);
}

void ExpertAction::UpStoreTypeName(int typeOp, int inOpTypeId)
{
	FuncUpStoreTypeName(typeOp, inOpTypeId);
}

void ExpertAction::UpTargetObjects(int inConstTarget, int inConstTargetAction, int inConstFormation, int inConstAttackStance)
{
	FuncUpTargetObjects(inConstTarget, inConstTargetAction, inConstFormation, inConstAttackStance);
}

void ExpertAction::UpTargetPoint(int inGoalPoint, int inConstTargetAction, int inConstFormation, int inConstAttackStance)
{
	FuncUpTargetPoint(inGoalPoint, inConstTargetAction, inConstFormation, inConstAttackStance);
}

void ExpertAction::UpTrain(int inGoalEscrowState, int typeOp, int inOpUnitId)
{
	if (ExpertFact::UpCanTrain(inGoalEscrowState, typeOp, inOpUnitId))
	{
		FuncUpTrain(inGoalEscrowState, typeOp, inOpUnitId);
	}
}

void ExpertAction::UpTributeToPlayer(int inPlayerAnyPlayer, int inConstResourceAmount, int typeOp, int inOpValue)
{
	FuncUpTributeToPlayer(inPlayerAnyPlayer, inConstResourceAmount, typeOp, inOpValue);
}

void ExpertAction::UpUngarrison(int typeOp, int inOpObjectId)
{
	FuncUpUngarrison(typeOp, inOpObjectId);
}

void ExpertAction::UpUpdateTargets()
{
	FuncUpUpdateTargets();
}

#if defined GAME_DE
void ExpertAction::ChatDebug(const std::string& inTextString)
{
	SetCustomString(inTextString);
	FuncChatDebug(expert_conf::CONST_CUSTOM_STRING_ID);
}

void ExpertAction::FeBreakPoint(int param1, int param2, int param3, int param4)
{
	FuncFeBreakPoint(param1, param2, param3, param4);
}

void ExpertAction::SkyboxClearSignal(int param)
{
	FuncSkyboxClearSignal(param);
}

void ExpertAction::SkyboxSetNameMode(int param)
{
	FuncSkyboxSetNameMode(param);
}

void ExpertAction::UpChatDataToAllUsingId(int param1, int param2, int param3)
{
	FuncUpChatDataToAllUsingId(param1, param2, param3);
}

void ExpertAction::UpChatDataToPlayerUsingId(int param1, int param2, int param3, int param4)
{
	FuncUpChatDataToPlayerUsingId(param1, param2, param3, param4);
}

void ExpertAction::UpGetTreatyData(int param)
{
	FuncUpGetTreatyData(param);
}

void ExpertAction::UpTestharnessReport(int param1, int param2, int param3)
{
	FuncUpTestharnessReport(param1, param2, param3);
}

void ExpertAction::UpTestharnessTest(int param1, int param2, int param3, int param4)
{
	FuncUpTestharnessTest(param1, param2, param3, param4);
}
#elif defined GAME_AOC
void ExpertAction::UpGetAlliedTarget(int param1, int param2)
{
	FuncUpGetAlliedTarget(param1, param2);
}

void ExpertAction::UpGetGuardState(int outGoalState)
{
	FuncUpGetGuardState(outGoalState);
}

void ExpertAction::UpGetUpgradeId(int inPlayerAnyPlayer, int inConstCount, int inGoalTypeId, int outGoalUpgradeId)
{
	FuncUpGetUpgradeId(inPlayerAnyPlayer, inConstCount, inGoalTypeId, outGoalUpgradeId);
}

void ExpertAction::UpOutOfSync()
{
	FuncUpOutOfSync();
}
#endif
