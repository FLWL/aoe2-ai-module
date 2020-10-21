#include "ExpertAction.h"
#include "misc/Configuration.h"
#include "misc/Statics.h"

#include <iostream>

void ExpertAction::UpdateAddresses()
{
	statics::SetFuncAddr(FuncAcknowledgeEvent, statics::TranslateAddr(expert_conf::ADDR_FUNC_ACKNOWLEDGE_EVENT));
	statics::SetFuncAddr(FuncAcknowledgeTaunt, statics::TranslateAddr(expert_conf::ADDR_FUNC_ACKNOWLEDGE_TAUNT));
	statics::SetFuncAddr(FuncAttackNow, statics::TranslateAddr(expert_conf::ADDR_FUNC_ATTACK_NOW));
	statics::SetFuncAddr(FuncBuild, statics::TranslateAddr(expert_conf::ADDR_FUNC_BUILD));
	statics::SetFuncAddr(FuncBuildForward, statics::TranslateAddr(expert_conf::ADDR_FUNC_BUILD_FORWARD));
	statics::SetFuncAddr(FuncBuildGate, statics::TranslateAddr(expert_conf::ADDR_FUNC_BUILD_GATE));
	statics::SetFuncAddr(FuncBuildWall, statics::TranslateAddr(expert_conf::ADDR_FUNC_BUILD_WALL));
	statics::SetFuncAddr(FuncBuyCommodity, statics::TranslateAddr(expert_conf::ADDR_FUNC_BUY_COMMODITY));
	statics::SetFuncAddr(FuncCcAddResource, statics::TranslateAddr(expert_conf::ADDR_FUNC_CC_ADD_RESOURCE));
	statics::SetFuncAddr(FuncChatDebug, statics::TranslateAddr(expert_conf::ADDR_FUNC_CHAT_DEBUG));
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
	statics::SetFuncAddr(FuncDoNothing, statics::TranslateAddr(expert_conf::ADDR_FUNC_DO_NOTHING));
	statics::SetFuncAddr(FuncEnableRule, statics::TranslateAddr(expert_conf::ADDR_FUNC_ENABLE_RULE));
	statics::SetFuncAddr(FuncEnableTimer, statics::TranslateAddr(expert_conf::ADDR_FUNC_ENABLE_TIMER));
	statics::SetFuncAddr(FuncEnableWallPlacement, statics::TranslateAddr(expert_conf::ADDR_FUNC_ENABLE_WALL_PLACEMENT));
	statics::SetFuncAddr(FuncFeBreakPoint, statics::TranslateAddr(expert_conf::ADDR_FUNC_FE_BREAK_POINT));
	statics::SetFuncAddr(FuncGenerateRandomNumber, statics::TranslateAddr(expert_conf::ADDR_FUNC_GENERATE_RANDOM_NUMBER));
	statics::SetFuncAddr(FuncLog, statics::TranslateAddr(expert_conf::ADDR_FUNC_LOG));
	statics::SetFuncAddr(FuncLogTrace, statics::TranslateAddr(expert_conf::ADDR_FUNC_LOG_TRACE));
	statics::SetFuncAddr(FuncReleaseEscrow, statics::TranslateAddr(expert_conf::ADDR_FUNC_RELEASE_ESCROW));
	statics::SetFuncAddr(FuncResearch, statics::TranslateAddr(expert_conf::ADDR_FUNC_RESEARCH));
	statics::SetFuncAddr(FuncResign, statics::TranslateAddr(expert_conf::ADDR_FUNC_RESIGN));
	statics::SetFuncAddr(FuncSellCommodity, statics::TranslateAddr(expert_conf::ADDR_FUNC_SELL_COMMODITY));
	statics::SetFuncAddr(FuncSetAuthorName, statics::TranslateAddr(expert_conf::ADDR_FUNC_SET_AUTHOR_NAME));
	statics::SetFuncAddr(FuncSetAuthorEmail, statics::TranslateAddr(expert_conf::ADDR_FUNC_SET_AUTHOR_EMAIL));
	statics::SetFuncAddr(FuncSetAuthorVersion, statics::TranslateAddr(expert_conf::ADDR_FUNC_SET_AUTHOR_VERSION));
	statics::SetFuncAddr(FuncSetDifficultyParameter, statics::TranslateAddr(expert_conf::ADDR_FUNC_SET_DIFFICULTY_PARAMETER));
	statics::SetFuncAddr(FuncSetDoctrine, statics::TranslateAddr(expert_conf::ADDR_FUNC_SET_DOCTRINE));
	statics::SetFuncAddr(FuncSetEscrowPercentage, statics::TranslateAddr(expert_conf::ADDR_FUNC_SET_ESCROW_PERCENTAGE));
	statics::SetFuncAddr(FuncSetGoal, statics::TranslateAddr(expert_conf::ADDR_FUNC_SET_GOAL));
	statics::SetFuncAddr(FuncSetSharedGoal, statics::TranslateAddr(expert_conf::ADDR_FUNC_SET_SHARED_GOAL));
	statics::SetFuncAddr(FuncSetSignal, statics::TranslateAddr(expert_conf::ADDR_FUNC_SET_SIGNAL));
	statics::SetFuncAddr(FuncSetStance, statics::TranslateAddr(expert_conf::ADDR_FUNC_SET_STANCE));
	statics::SetFuncAddr(FuncSetStrategicNumber, statics::TranslateAddr(expert_conf::ADDR_FUNC_SET_STRATEGIC_NUMBER));
	statics::SetFuncAddr(FuncSkyboxClearSignal, statics::TranslateAddr(expert_conf::ADDR_FUNC_SKYBOX_CLEAR_SIGNAL));
	statics::SetFuncAddr(FuncSkyboxSetNameMode, statics::TranslateAddr(expert_conf::ADDR_FUNC_SKYBOX_SET_NAME_MODE));
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
	statics::SetFuncAddr(FuncUpChatDataToAllUsingId, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_CHAT_DATA_TO_ALL_USING_ID));
	statics::SetFuncAddr(FuncUpChatDataToPlayerUsingId, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_CHAT_DATA_TO_PLAYER_USING_ID));
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
	//statics::SetFuncAddr(FuncUpGetGuardState, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_GUARD_STATE));
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
	statics::SetFuncAddr(FuncUpGetTreatyData, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_TREATY_DATA));
	//statics::SetFuncAddr(FuncUpGetUpgradeId, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GET_UPGRADE_ID));
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
	statics::SetFuncAddr(FuncUpTestharnessReport, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_TESTHARNESS_REPORT));
	statics::SetFuncAddr(FuncUpTestharnessTest, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_TESTHARNESS_TEST));
	statics::SetFuncAddr(FuncUpTrain, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_TRAIN));
	statics::SetFuncAddr(FuncUpTributeToPlayer, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_TRIBUTE_TO_PLAYER));
	statics::SetFuncAddr(FuncUpUngarrison, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_UNGARRISON));
	statics::SetFuncAddr(FuncUpUpdateTargets, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_UPDATE_TARGETS));
}

void ExpertAction::AcknowledgeEvent(int eventType, int id)
{
	FuncAcknowledgeEvent(eventType, id);
}

void ExpertAction::AcknowledgeTaunt(int playerNumber, int tauntId)
{
	FuncAcknowledgeTaunt(playerNumber, tauntId);
}

void ExpertAction::AttackNow()
{
	FuncAttackNow();
}

void ExpertAction::Build(int buildingType)
{
	FuncBuild(buildingType);
}

void ExpertAction::BuildForward(int buildingType)
{
	FuncBuildForward(buildingType);
}

void ExpertAction::BuildGate(int perimeter)
{
	FuncBuildGate(perimeter);
}

void ExpertAction::BuildWall(int perimeter, int wallType)
{
	FuncBuildWall(perimeter, wallType);
}

void ExpertAction::BuyCommodity(int commodityType)
{
	FuncBuyCommodity(commodityType);
}

void ExpertAction::CcAddResource(int resourceType, int amount)
{
	FuncCcAddResource(resourceType, amount);
}

void ExpertAction::ChatDebug(int text)
{
	FuncChatDebug(text);
}

void ExpertAction::ChatLocal(int text)
{
	FuncChatLocal(text);
}

void ExpertAction::ChatLocalUsingId(int stringId)
{
	FuncChatLocalUsingId(stringId);
}

void ExpertAction::ChatLocalUsingRange(int stringIdStart, int stringIdRange)
{
	FuncChatLocalUsingRange(stringIdStart, stringIdRange);
}

void ExpertAction::ChatLocalToSelf(int text)
{
	FuncChatLocalToSelf(text);
}

void ExpertAction::ChatToAll(int text)
{
	FuncChatToAll(text);
}

void ExpertAction::ChatToAllUsingId(int stringId)
{
	FuncChatToAllUsingId(stringId);
}

void ExpertAction::ChatToAllUsingRange(int stringIdStart, int stringIdRange)
{
	FuncChatToAllUsingRange(stringIdStart, stringIdRange);
}

void ExpertAction::ChatToAllies(int text)
{
	FuncChatToAllies(text);
}

void ExpertAction::ChatToAlliesUsingId(int stringId)
{
	FuncChatToAlliesUsingId(stringId);
}

void ExpertAction::ChatToAlliesUsingRange(int stringIdStart, int stringIdRange)
{
	FuncChatToAlliesUsingRange(stringIdStart, stringIdRange);
}

void ExpertAction::ChatToEnemies(int text)
{
	FuncChatToEnemies(text);
}

void ExpertAction::ChatToEnemiesUsingId(int stringId)
{
	FuncChatToEnemiesUsingId(stringId);
}

void ExpertAction::ChatToEnemiesUsingRange(int stringIdStart, int stringIdRange)
{
	FuncChatToEnemiesUsingRange(stringIdStart, stringIdRange);
}

void ExpertAction::ChatToPlayer(int playerNumber, int text)
{
	FuncChatToPlayer(playerNumber, text);
}

void ExpertAction::ChatToPlayerUsingId(int playerNumber, int stringId)
{
	FuncChatToPlayerUsingId(playerNumber, stringId);
}

void ExpertAction::ChatToPlayerUsingRange(int playerNumber, int stringIdStart, int stringIdRange)
{
	FuncChatToPlayerUsingRange(playerNumber, stringIdStart, stringIdRange);
}

void ExpertAction::ChatTrace(int traceNumber)
{
	FuncChatTrace(traceNumber);
}

void ExpertAction::ClearTributeMemory(int playerNumber, int resourceType)
{
	FuncClearTributeMemory(playerNumber, resourceType);
}

void ExpertAction::DeleteBuilding(int buildingType)
{
	FuncDeleteBuilding(buildingType);
}

void ExpertAction::DeleteUnit(int unitType)
{
	FuncDeleteUnit(unitType);
}

void ExpertAction::DisableRule(int groupId)
{
	FuncDisableRule(groupId);
}

void ExpertAction::DisableSelf()
{
	FuncDisableSelf();
}

void ExpertAction::DisableTimer(int timerId)
{
	FuncDisableTimer(timerId);
}

void ExpertAction::DoNothing()
{
	FuncDoNothing();
}

void ExpertAction::EnableRule(int groupId)
{
	FuncEnableRule(groupId);
}

void ExpertAction::EnableTimer(int timerId, int timeInterval)
{
	FuncEnableTimer(timerId, timeInterval);
}

void ExpertAction::EnableWallPlacement(int perimeter)
{
	FuncEnableWallPlacement(perimeter);
}

void ExpertAction::FeBreakPoint(int param1, int param2, int param3, int param4)
{
	FuncFeBreakPoint(param1, param2, param3, param4);
}

void ExpertAction::GenerateRandomNumber(int range)
{
	FuncGenerateRandomNumber(range);
}

void ExpertAction::Log(int text)
{
	FuncLog(text);
}

void ExpertAction::LogTrace(int traceNumber)
{
	FuncLogTrace(traceNumber);
}

void ExpertAction::ReleaseEscrow(int resourceType)
{
	FuncReleaseEscrow(resourceType);
}

void ExpertAction::Research(int researchType)
{
	FuncResearch(researchType);
}

void ExpertAction::Resign()
{
	FuncResign();
}

void ExpertAction::SellCommodity(int commodityType)
{
	FuncSellCommodity(commodityType);
}

void ExpertAction::SetAuthorName(int name)
{
	FuncSetAuthorName(name);
}

void ExpertAction::SetAuthorEmail(int email)
{
	FuncSetAuthorEmail(email);
}

void ExpertAction::SetAuthorVersion(int version)
{
	FuncSetAuthorVersion(version);
}

void ExpertAction::SetDifficultyParameter(int difficultyParameter, int value)
{
	FuncSetDifficultyParameter(difficultyParameter, value);
}

void ExpertAction::SetDoctrine(int doctrine)
{
	FuncSetDoctrine(doctrine);
}

void ExpertAction::SetEscrowPercentage(int resourceType, int percentage)
{
	FuncSetEscrowPercentage(resourceType, percentage);
}

void ExpertAction::SetGoal(int goalId, int goalValue)
{
	FuncSetGoal(goalId, goalValue);
}

void ExpertAction::SetSharedGoal(int goalId, int goal)
{
	FuncSetSharedGoal(goalId, goal);
}

void ExpertAction::SetSignal(int signalId)
{
	FuncSetSignal(signalId);
}

void ExpertAction::SetStance(int playerNumber, int stance)
{
	FuncSetStance(playerNumber, stance);
}

void ExpertAction::SetStrategicNumber(int strategicNumber, int value)
{
	FuncSetStrategicNumber(strategicNumber, value);
}

void ExpertAction::SkyboxClearSignal(int param)
{
	FuncSkyboxClearSignal(param);
}

void ExpertAction::SkyboxSetNameMode(int param)
{
	FuncSkyboxSetNameMode(param);
}

void ExpertAction::Spy()
{
	FuncSpy();
}

void ExpertAction::Taunt(int tauntNumber)
{
	FuncTaunt(tauntNumber);
}

void ExpertAction::TauntUsingRange(int tauntIdStart, int tauntIdRange)
{
	FuncTauntUsingRange(tauntIdStart, tauntIdRange);
}

void ExpertAction::Train(int unitType)
{
	FuncTrain(unitType);
}

void ExpertAction::TributeToPlayer(int playerNumber, int resourceType, int tributeAmount)
{
	FuncTributeToPlayer(playerNumber, resourceType, tributeAmount);
}

void ExpertAction::UpAddCostData(int goalId, int typeOp, int opValue)
{
	FuncUpAddCostData(goalId, typeOp, opValue);
}

void ExpertAction::UpAddObjectById(int searchSource, int typeOp, int opId)
{
	FuncUpAddObjectById(searchSource, typeOp, opId);
}

void ExpertAction::UpAddObjectCost(int typeOp1, int objectId, int typeOp2, int value)
{
	FuncUpAddObjectCost(typeOp1, objectId, typeOp2, value);
}

void ExpertAction::UpAddPoint(int goalPoint1, int goalPoint2, int typeOp, int count)
{
	FuncUpAddPoint(goalPoint1, goalPoint2, typeOp, count);
}

void ExpertAction::UpAddResearchCost(int typeOp1, int techId, int typeOp2, int value)
{
	FuncUpAddResearchCost(typeOp1, techId, typeOp2, value);
}

void ExpertAction::UpAssignBuilders(int typeOp1, int buildingId, int typeOp2, int value)
{
	FuncUpAssignBuilders(typeOp1, buildingId, typeOp2, value);
}

void ExpertAction::UpBoundPoint(int goalPoint1, int goalPoint2)
{
	FuncUpBoundPoint(goalPoint1, goalPoint2);
}

void ExpertAction::UpBoundPrecisePoint(int goalPoint, int precise, int typeOp, int border)
{
	FuncUpBoundPrecisePoint(goalPoint, precise, typeOp, border);
}

void ExpertAction::UpBuild(int placementType, int escrowState, int typeOp, int buildingId)
{
	FuncUpBuild(placementType, escrowState, typeOp, buildingId);
}

void ExpertAction::UpBuildLine(int goalPoint1, int goalPoint2, int typeOp, int buildingId)
{
	FuncUpBuildLine(goalPoint1, goalPoint2, typeOp, buildingId);
}

void ExpertAction::UpBuyCommodity(int typeOp1, int resourceAmount, int typeOp2, int value)
{
	FuncUpBuyCommodity(typeOp1, resourceAmount, typeOp2, value);
}

void ExpertAction::UpCcAddResource(int typeOp1, int resourceAmount, int typeOp2, int value)
{
	FuncUpCcAddResource(typeOp1, resourceAmount, typeOp2, value);
}

void ExpertAction::UpCcSendCheat(int code)
{
	FuncUpCcSendCheat(code);
}

void ExpertAction::UpChangeName(int newName)
{
	FuncUpChangeName(newName);
}

void ExpertAction::UpChatDataToAll(int format, int typeOp, int value)
{
	FuncUpChatDataToAll(format, typeOp, value);
}

void ExpertAction::UpChatDataToAllUsingId(int param1, int stringId, int param3)
{
	FuncUpChatDataToAllUsingId(param1, stringId, param3);
}

void ExpertAction::UpChatDataToPlayerUsingId(int stringId, int playerId, int param3, int param4)
{
	FuncUpChatDataToPlayerUsingId(stringId, playerId, param3, param4);
}

void ExpertAction::UpChatDataToPlayer(int player, int format, int typeOp, int value)
{
	FuncUpChatDataToPlayer(player, format, typeOp, value);
}

void ExpertAction::UpChatDataToSelf(int format, int typeOp, int value)
{
	FuncUpChatDataToSelf(format, typeOp, value);
}

void ExpertAction::UpCleanSearch(int searchSource, int objectData, int searchOrder)
{
	FuncUpCleanSearch(searchSource, objectData, searchOrder);
}

void ExpertAction::UpCopyPoint(int goalPoint1, int goalPoint2)
{
	FuncUpCopyPoint(goalPoint1, goalPoint2);
}

void ExpertAction::UpCreateGroup(int goalIndex, int goalCount, int typeOp, int groupId)
{
	FuncUpCreateGroup(goalIndex, goalCount, typeOp, groupId);
}

void ExpertAction::UpCrossTiles(int goalPoint1, int goalPoint2, int typeOp, int tiles)
{
	FuncUpCrossTiles(goalPoint1, goalPoint2, typeOp, tiles);
}

void ExpertAction::UpDeleteDistantFarms(int typeOp, int value)
{
	FuncUpDeleteDistantFarms(typeOp, value);
}

void ExpertAction::UpDeleteIdleUnits(int idleType)
{
	FuncUpDeleteIdleUnits(idleType);
}

void ExpertAction::UpDeleteObjects(int typeOp1, int unitId, int typeOp2, int hitpoints)
{
	FuncUpDeleteObjects(typeOp1, unitId, typeOp2, hitpoints);
}

void ExpertAction::UpDisbandGroupType(int groupType)
{
	FuncUpDisbandGroupType(groupType);
}

void ExpertAction::UpDropResources(int resource, int typeOp, int value)
{
	FuncUpDropResources(resource, typeOp, value);
}

void ExpertAction::UpFilterDistance(int typeOp1, int minDistance, int typeOp2, int maxDistance)
{
	FuncUpFilterDistance(typeOp1, minDistance, typeOp2, maxDistance);
}

void ExpertAction::UpFilterExclude(int cmdId, int actionId, int orderId, int classId)
{
	FuncUpFilterExclude(cmdId, actionId, orderId, classId);
}

void ExpertAction::UpFilterGarrison(int typeOp1, int minGarrison, int typeOp2, int maxGarrison)
{
	FuncUpFilterGarrison(typeOp1, minGarrison, typeOp2, maxGarrison);
}

void ExpertAction::UpFilterInclude(int cmdId, int actionId, int orderId, int onMainland)
{
	FuncUpFilterInclude(cmdId, actionId, orderId, onMainland);
}

void ExpertAction::UpFilterRange(int minGarrison, int maxGarrison, int minDistance, int maxDistance)
{
	FuncUpFilterRange(minGarrison, maxGarrison, minDistance, maxDistance);
}

void ExpertAction::UpFilterStatus(int typeOp1, int objectStatus, int typeOp2, int objectList)
{
	FuncUpFilterStatus(typeOp1, objectStatus, typeOp2, objectList);
}

void ExpertAction::UpFindFlare(int goalPoint)
{
	FuncUpFindFlare(goalPoint);
}

void ExpertAction::UpFindLocal(int typeOp1, int unitId, int typeOp2, int count)
{
	FuncUpFindLocal(typeOp1, unitId, typeOp2, count);
}

void ExpertAction::UpFindNextPlayer(int playerStance, int findPlayerMethod, int goalPlayerId)
{
	FuncUpFindNextPlayer(playerStance, findPlayerMethod, goalPlayerId);
}

void ExpertAction::UpFindPlayer(int playerStance, int findPlayerMethod, int goalPlayerId)
{
	FuncUpFindPlayer(playerStance, findPlayerMethod, goalPlayerId);
}

void ExpertAction::UpFindPlayerFlare(int player, int goalPoint)
{
	FuncUpFindPlayerFlare(player, goalPoint);
}

void ExpertAction::UpFindRemote(int typeOp1, int unitId, int typeOp2, int count)
{
	FuncUpFindRemote(typeOp1, unitId, typeOp2, count);
}

void ExpertAction::UpFindResource(int typeOp1, int resource, int typeOp2, int count)
{
	FuncUpFindResource(typeOp1, resource, typeOp2, count);
}

void ExpertAction::UpFindStatusLocal(int typeOp1, int unitId, int typeOp2, int count)
{
	FuncUpFindStatusLocal(typeOp1, unitId, typeOp2, count);
}

void ExpertAction::UpFindStatusRemote(int typeOp1, int unitId, int typeOp2, int count)
{
	FuncUpFindStatusRemote(typeOp1, unitId, typeOp2, count);
}

void ExpertAction::UpFullResetSearch()
{
	FuncUpFullResetSearch();
}

void ExpertAction::UpGarrison(int objectId, int typeOp, int unitId)
{
	FuncUpGarrison(objectId, typeOp, unitId);
}

void ExpertAction::UpGatherInside(int typeOp1, int buildingId, int typeOp2, int state)
{
	FuncUpGatherInside(typeOp1, buildingId, typeOp2, state);
}

void ExpertAction::UpGetAttackerClass(int goalSourceClass)
{
	FuncUpGetAttackerClass(goalSourceClass);
}

void ExpertAction::UpGetCostDelta(int goalId)
{
	FuncUpGetCostDelta(goalId);
}

void ExpertAction::UpGetEvent(int typeOp, int eventId, int goalValue)
{
	FuncUpGetEvent(typeOp, eventId, goalValue);
}

void ExpertAction::UpGetFact(int factId, int factParam, int goalId)
{
	FuncUpGetFact(factId, factParam, goalId);
}

void ExpertAction::UpGetFactMax(int player, int factId, int param, int goalData)
{
	FuncUpGetFactMax(player, factId, param, goalData);
}

void ExpertAction::UpGetFactMin(int player, int factId, int param, int goalData)
{
	FuncUpGetFactMin(player, factId, param, goalData);
}

void ExpertAction::UpGetFactSum(int player, int factId, int param, int goalData)
{
	FuncUpGetFactSum(player, factId, param, goalData);
}

void ExpertAction::UpGetFocusFact(int factId, int param, int goalData)
{
	FuncUpGetFocusFact(factId, param, goalData);
}

void ExpertAction::UpGetGroupSize(int typeOp, int groupId, int goalSize)
{
	FuncUpGetGroupSize(typeOp, groupId, goalSize);
}

/*void ExpertAction::UpGetGuardState(int goalState)
{
	FuncUpGetGuardState(goalState);
}*/

void ExpertAction::UpGetIndirectGoal(int typeOp1, int goalId, int goalValue)
{
	FuncUpGetIndirectGoal(typeOp1, goalId, goalValue);
}

void ExpertAction::UpGetObjectData(int objectData, int goalData)
{
	FuncUpGetObjectData(objectData, goalData);
}

void ExpertAction::UpGetObjectTargetData(int objectData, int goalData)
{
	FuncUpGetObjectTargetData(objectData, goalData);
}

void ExpertAction::UpGetObjectTypeData(int typeOp, int objectTypeId, int objectData, int goalData)
{
	FuncUpGetObjectTypeData(typeOp, objectTypeId, objectData, goalData);
}

void ExpertAction::UpGetPathDistance(int goalPoint, int strict, int goalData)
{
	FuncUpGetPathDistance(goalPoint, strict, goalData);
}

void ExpertAction::UpGetPlayerColor(int player, int goalColorId)
{
	FuncUpGetPlayerColor(player, goalColorId);
}

void ExpertAction::UpGetPlayerFact(int player, int factId, int param, int goalData)
{
	FuncUpGetPlayerFact(player, factId, param, goalData);
}

void ExpertAction::UpGetPoint(int positionType, int goalPoint)
{
	FuncUpGetPoint(positionType, goalPoint);
}

void ExpertAction::UpGetPointContains(int goalPoint, int goalId, int typeOp, int objectId)
{
	FuncUpGetPointContains(goalPoint, goalId, typeOp, objectId);
}

void ExpertAction::UpGetPointDistance(int goalPoint1, int goalPoint2, int goalDistance)
{
	FuncUpGetPointDistance(goalPoint1, goalPoint2, goalDistance);
}

void ExpertAction::UpGetPointElevation(int goalPoint, int goalData)
{
	FuncUpGetPointElevation(goalPoint, goalData);
}

void ExpertAction::UpGetPointTerrain(int goalPoint, int goalTerrain)
{
	FuncUpGetPointTerrain(goalPoint, goalTerrain);
}

void ExpertAction::UpGetPointZone(int goalPoint, int goalData)
{
	FuncUpGetPointZone(goalPoint, goalData);
}

void ExpertAction::UpGetPreciseTime(int goalStart, int goalTime)
{
	FuncUpGetPreciseTime(goalStart, goalTime);
}

void ExpertAction::UpGetProjectilePlayer(int projectileType, int goalPlayerId)
{
	FuncUpGetProjectilePlayer(projectileType, goalPlayerId);
}

void ExpertAction::UpGetRuleId(int goalRuleId)
{
	FuncUpGetRuleId(goalRuleId);
}

void ExpertAction::UpGetSearchState(int goalState)
{
	FuncUpGetSearchState(goalState);
}

void ExpertAction::UpGetSharedGoal(int typeOp, int sharedGoalId, int goalValue)
{
	FuncUpGetSharedGoal(typeOp, sharedGoalId, goalValue);
}

void ExpertAction::UpGetSignal(int typeOp, int signalId, int goalValue)
{
	FuncUpGetSignal(typeOp, signalId, goalValue);
}

void ExpertAction::UpGetTargetFact(int factId, int param, int goalData)
{
	FuncUpGetTargetFact(factId, param, goalData);
}

void ExpertAction::UpGetThreatData(int goalElapsedTime, int goalPlayerId, int goalSourceClass, int goalTargetClass)
{
	FuncUpGetThreatData(goalElapsedTime, goalPlayerId, goalSourceClass, goalTargetClass);
}

void ExpertAction::UpGetTimer(int typeOp, int timerId, int goalValue)
{
	FuncUpGetTimer(typeOp, timerId, goalValue);
}

void ExpertAction::UpGetTreatyData(int param)
{
	FuncUpGetTreatyData(param);
}

/*void ExpertAction::UpGetUpgradeId(int player, int count, int goalTypeId, int goalUpgradeId)
{
	FuncUpGetUpgradeId(player, count, goalTypeId, goalUpgradeId);
}*/

void ExpertAction::UpGetVictoryData(int goalPlayerId, int goalType, int goalTime)
{
	FuncUpGetVictoryData(goalPlayerId, goalType, goalTime);
}

void ExpertAction::UpGetVictoryLimit(int goalLimit)
{
	FuncUpGetVictoryLimit(goalLimit);
}

void ExpertAction::UpGuardUnit(int objectId, int typeOp, int unitId)
{
	FuncUpGuardUnit(objectId, typeOp, unitId);
}

void ExpertAction::UpJumpDirect(int typeOp, int ruleId)
{
	FuncUpJumpDirect(typeOp, ruleId);
}

void ExpertAction::UpJumpDynamic(int typeOp, int ruleDelta)
{
	FuncUpJumpDynamic(typeOp, ruleDelta);
}

void ExpertAction::UpJumpRule(int ruleDelta)
{
	FuncUpJumpRule(ruleDelta);
}

void ExpertAction::UpLerpPercent(int goalPoint1, int goalPoint2, int typeOp, int percent)
{
	FuncUpLerpPercent(goalPoint1, goalPoint2, typeOp, percent);
}

void ExpertAction::UpLerpTiles(int goalPoint1, int goalPoint2, int typeOp, int tiles)
{
	FuncUpLerpTiles(goalPoint1, goalPoint2, typeOp, tiles);
}

void ExpertAction::UpLogData(int plain, int format, int typeOp, int value)
{
	FuncUpLogData(plain, format, typeOp, value);
}

void ExpertAction::UpModifyEscrow(int resource, int mathOp, int value)
{
	FuncUpModifyEscrow(resource, mathOp, value);
}

void ExpertAction::UpModifyFlag(int goalId, int mathOp, int value)
{
	FuncUpModifyFlag(goalId, mathOp, value);
}

void ExpertAction::UpModifyGoal(int goalId, int mathOp, int value)
{
	FuncUpModifyGoal(goalId, mathOp, value);
}

void ExpertAction::UpModifyGroupFlag(int on, int typeOp, int groupId)
{
	FuncUpModifyGroupFlag(on, typeOp, groupId);
}

void ExpertAction::UpModifySn(int snId, int mathOp, int value)
{
	FuncUpModifySn(snId, mathOp, value);
}

void ExpertAction::UpReleaseEscrow()
{
	FuncUpReleaseEscrow();
}

void ExpertAction::UpRemoveObjects(int searchSource, int objectData, int typeOp, int value)
{
	FuncUpRemoveObjects(searchSource, objectData, typeOp, value);
}

void ExpertAction::UpRequestHunters(int typeOp, int value)
{
	FuncUpRequestHunters(typeOp, value);
}

void ExpertAction::UpResearch(int escrowState, int typeOp, int techId)
{
	FuncUpResearch(escrowState, typeOp, techId);
}

void ExpertAction::UpResetAttackNow()
{
	FuncUpResetAttackNow();
}

void ExpertAction::UpResetBuilding(int preserveResearch, int typeOp, int buildingId)
{
	FuncUpResetBuilding(preserveResearch, typeOp, buildingId);
}

void ExpertAction::UpResetCostData(int goalId)
{
	FuncUpResetCostData(goalId);
}

void ExpertAction::UpResetFilters()
{
	FuncUpResetFilters();
}

void ExpertAction::UpResetGroup(int typeOp, int groupId)
{
	FuncUpResetGroup(typeOp, groupId);
}

void ExpertAction::UpResetPlacement(int typeOp, int buildingId)
{
	FuncUpResetPlacement(typeOp, buildingId);
}

void ExpertAction::UpResetScouts()
{
	FuncUpResetScouts();
}

void ExpertAction::UpResetSearch(int localIndex, int localList, int remoteIndex, int remoteList)
{
	FuncUpResetSearch(localIndex, localList, remoteIndex, remoteList);
}

void ExpertAction::UpResetTargetPriorities(int priorityType, int mode)
{
	FuncUpResetTargetPriorities(priorityType, mode);
}

void ExpertAction::UpResetUnit(int typeOp, int unitId)
{
	FuncUpResetUnit(typeOp, unitId);
}

void ExpertAction::UpRetaskGatherers(int resource, int typeOp, int value)
{
	FuncUpRetaskGatherers(resource, typeOp, value);
}

void ExpertAction::UpRetreatNow()
{
	FuncUpRetreatNow();
}

void ExpertAction::UpRetreatTo(int objectId, int typeOp, int unitId)
{
	FuncUpRetreatTo(objectId, typeOp, unitId);
}

void ExpertAction::UpSellCommodity(int typeOp1, int resourceAmount, int typeOp2, int value)
{
	FuncUpSellCommodity(typeOp1, resourceAmount, typeOp2, value);
}

void ExpertAction::UpSendFlare(int goalPoint)
{
	FuncUpSendFlare(goalPoint);
}

void ExpertAction::UpSendScout(int groupType, int positionType)
{
	FuncUpSendScout(groupType, positionType);
}

void ExpertAction::UpSetAttackStance(int unitId, int typeOp, int attackStance)
{
	FuncUpSetAttackStance(unitId, typeOp, attackStance);
}

void ExpertAction::UpSetDefensePriority(int typeOp1, int buildingId, int typeOp2, int value)
{
	FuncUpSetDefensePriority(typeOp1, buildingId, typeOp2, value);
}

void ExpertAction::UpSetEvent(int typeOp1, int eventId, int typeOp2, int value)
{
	FuncUpSetEvent(typeOp1, eventId, typeOp2, value);
}

void ExpertAction::UpSetGroup(int searchSource, int typeOp, int groupId)
{
	FuncUpSetGroup(searchSource, typeOp, groupId);
}

void ExpertAction::UpSetIndirectGoal(int typeOp1, int goalId, int typeOp2, int value)
{
	FuncUpSetIndirectGoal(typeOp1, goalId, typeOp2, value);
}

void ExpertAction::UpSetOffensePriority(int typeOp1, int objectId, int typeOp2, int value)
{
	FuncUpSetOffensePriority(typeOp1, objectId, typeOp2, value);
}

void ExpertAction::UpSetPlacementData(int playerAlly, int objectId, int typeOp, int value)
{
	FuncUpSetPlacementData(playerAlly, objectId, typeOp, value);
}

void ExpertAction::UpSetPreciseTargetPoint(int goalPoint)
{
	FuncUpSetPreciseTargetPoint(goalPoint);
}

void ExpertAction::UpSetSharedGoal(int typeOp1, int sharedGoalId, int typeOp2, int value)
{
	FuncUpSetSharedGoal(typeOp1, sharedGoalId, typeOp2, value);
}

void ExpertAction::UpSetSignal(int typeOp1, int signalId, int typeOp2, int value)
{
	FuncUpSetSignal(typeOp1, signalId, typeOp2, value);
}

void ExpertAction::UpSetTargetById(int typeOp, int id)
{
	FuncUpSetTargetById(typeOp, id);
}

void ExpertAction::UpSetTargetObject(int searchSource, int typeOp, int index)
{
	FuncUpSetTargetObject(searchSource, typeOp, index);
}

void ExpertAction::UpSetTargetPoint(int goalPoint)
{
	FuncUpSetTargetPoint(goalPoint);
}

void ExpertAction::UpSetTimer(int typeOp1, int timerId, int typeOp2, int value)
{
	FuncUpSetTimer(typeOp1, timerId, typeOp2, value);
}

void ExpertAction::UpSetupCostData(int resetCost, int goalId)
{
	FuncUpSetupCostData(resetCost, goalId);
}

void ExpertAction::UpStoreMapName(int extension)
{
	FuncUpStoreMapName(extension);
}

void ExpertAction::UpStoreObjectName()
{
	FuncUpStoreObjectName();
}

void ExpertAction::UpStorePlayerChat(int player)
{
	FuncUpStorePlayerChat(player);
}

void ExpertAction::UpStorePlayerName(int player)
{
	FuncUpStorePlayerName(player);
}

void ExpertAction::UpStoreTechName(int typeOp, int techId)
{
	FuncUpStoreTechName(typeOp, techId);
}

void ExpertAction::UpStoreText(int typeOp, int languageId)
{
	FuncUpStoreText(typeOp, languageId);
}

void ExpertAction::UpStoreTypeName(int typeOp, int objectTypeId)
{
	FuncUpStoreTypeName(typeOp, objectTypeId);
}

void ExpertAction::UpTargetObjects(int target, int action, int formation, int attackStance)
{
	FuncUpTargetObjects(target, action, formation, attackStance);
}

void ExpertAction::UpTargetPoint(int goalPoint, int action, int formation, int attackStance)
{
	FuncUpTargetPoint(goalPoint, action, formation, attackStance);
}

void ExpertAction::UpTestharnessReport(int param1, int param2, int param3)
{
	FuncUpTestharnessReport(param1, param2, param3);
}

void ExpertAction::UpTestharnessTest(int param1, int param2, int param3, int param4)
{
	FuncUpTestharnessTest(param1, param2, param3, param4);
}

void ExpertAction::UpTrain(int escrowState, int typeOp, int unitId)
{
	FuncUpTrain(escrowState, typeOp, unitId);
}

void ExpertAction::UpTributeToPlayer(int player, int resourceAmount, int typeOp, int value)
{
	FuncUpTributeToPlayer(player, resourceAmount, typeOp, value);
}

void ExpertAction::UpUngarrison(int typeOp, int objectId)
{
	FuncUpUngarrison(typeOp, objectId);
}

void ExpertAction::UpUpdateTargets()
{
	FuncUpUpdateTargets();
}
