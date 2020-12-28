#include "ExpertFact.h"

#include <iostream>

#include <Windows.h>
#include <detours/detours.h>

#include "misc/Statics.h"
#include "misc/MemoryUtils.h"
#include "expert/action/ExpertAction.h"

#if defined GAME_AOC
intptr_t gUpEvaluateRelOpAddr;
intptr_t gUpEvaluateRelOpRetAddr;
void DetouredUpEvaluateRelOp();

intptr_t gCcPlayersBuildingCountEvaluateRelOpAddr;
intptr_t gCcPlayersBuildingCountEvaluateRelOpRetAddr;
void DetouredCcPlayersBuildingCountEvaluateRelOp();

intptr_t gCcPlayersBuildingTypeCountEvaluateRelOpAddr;
intptr_t gCcPlayersBuildingTypeCountEvaluateRelOpRetAddr;
void DetouredCcPlayersBuildingTypeCountEvaluateRelOp();

intptr_t gCcPlayersUnitCountEvaluateRelOpAddr;
intptr_t gCcPlayersUnitCountEvaluateRelOpRetAddr;
void DetouredCcPlayersUnitCountEvaluateRelOp();

intptr_t gCcPlayersUnitTypeCountEvaluateRelOp1Addr;
intptr_t gCcPlayersUnitTypeCountEvaluateRelOp1RetAddr;
void DetouredCcPlayersUnitTypeCountEvaluateRelOp1();

intptr_t gCcPlayersUnitTypeCountEvaluateRelOp2Addr;
intptr_t gCcPlayersUnitTypeCountEvaluateRelOp2RetAddr;
void DetouredCcPlayersUnitTypeCountEvaluateRelOp2();
#endif

ExpertFact::ExpertFact()
{
	UpdateAddresses();
	EnableDetours();
}

ExpertFact::~ExpertFact()
{
	DisableDetours();
}

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
	statics::SetFuncAddr(FuncDeathMatchGame, statics::TranslateAddr(expert_conf::ADDR_FUNC_DEATH_MATCH_GAME));
	statics::SetFuncAddr(FuncDoctrine, statics::TranslateAddr(expert_conf::ADDR_FUNC_DOCTRINE));
	statics::SetFuncAddr(FuncEnemyBuildingsInTown, statics::TranslateAddr(expert_conf::ADDR_FUNC_ENEMY_BUILDINGS_IN_TOWN));
	statics::SetFuncAddr(FuncEnemyCapturedRelics, statics::TranslateAddr(expert_conf::ADDR_FUNC_ENEMY_CAPTURED_RELICS));
	statics::SetFuncAddr(FuncEventDetected, statics::TranslateAddr(expert_conf::ADDR_FUNC_EVENT_DETECTED));
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
	statics::SetFuncAddr(FuncUpGaiaTypeCount, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GAIA_TYPE_COUNT));
	statics::SetFuncAddr(FuncUpGaiaTypeCountTotal, statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_GAIA_TYPE_COUNT_TOTAL));

	statics::SetFuncAddr(FuncEvaluateRelOp, statics::TranslateAddr(expert_conf::ADDR_FUNC_EVALUATE_REL_OP));
#elif defined GAME_AOC
	statics::SetFuncAddr(FuncInternalGameType, statics::TranslateAddr(expert_conf::ADDR_FUNC_INTERNAL_GAME_TYPE));
	statics::SetFuncAddr(FuncInternalGetGateCount, statics::TranslateAddr(expert_conf::ADDR_FUNC_INTERNAL_GET_GATE_COUNT));
	statics::SetFuncAddr(FuncInternalStrategicNumber, statics::TranslateAddr(expert_conf::ADDR_FUNC_INTERNAL_STRATEGIC_NUMBER));
	statics::SetFuncAddr(FuncInternalWallCompletedPercentage, statics::TranslateAddr(expert_conf::ADDR_FUNC_INTERNAL_WALL_COMPLETED_PERCENTAGE));
	statics::SetFuncAddr(FuncInternalWallInvisiblePercentage, statics::TranslateAddr(expert_conf::ADDR_FUNC_INTERNAL_WALL_INVISIBLE_PERCENTAGE));

	gUpEvaluateRelOpAddr = statics::TranslateAddr(expert_conf::ADDR_FUNC_UP_EVALUATE_REL_OP);
	gUpEvaluateRelOpRetAddr = gUpEvaluateRelOpAddr + 5;

	gCcPlayersBuildingCountEvaluateRelOpAddr = statics::TranslateAddr(expert_conf::ADDR_FUNC_CC_PLAYERS_BUILDING_COUNT_EVALUATE_REL_OP);
	gCcPlayersBuildingCountEvaluateRelOpRetAddr = gCcPlayersBuildingCountEvaluateRelOpAddr + 5;

	gCcPlayersBuildingTypeCountEvaluateRelOpAddr = statics::TranslateAddr(expert_conf::ADDR_FUNC_CC_PLAYERS_BUILDING_TYPE_COUNT_EVALUATE_REL_OP);
	gCcPlayersBuildingTypeCountEvaluateRelOpRetAddr = gCcPlayersBuildingTypeCountEvaluateRelOpAddr + 5;

	gCcPlayersUnitCountEvaluateRelOpAddr = statics::TranslateAddr(expert_conf::ADDR_FUNC_CC_PLAYERS_UNIT_COUNT_EVALUATE_REL_OP);
	gCcPlayersUnitCountEvaluateRelOpRetAddr = gCcPlayersUnitCountEvaluateRelOpAddr + 5;

	gCcPlayersUnitTypeCountEvaluateRelOp1Addr = statics::TranslateAddr(expert_conf::ADDR_FUNC_CC_PLAYERS_UNIT_TYPE_COUNT_EVALUATE_REL_OP_1);
	gCcPlayersUnitTypeCountEvaluateRelOp1RetAddr = gCcPlayersUnitTypeCountEvaluateRelOp1Addr + 7;

	gCcPlayersUnitTypeCountEvaluateRelOp2Addr = statics::TranslateAddr(expert_conf::ADDR_FUNC_CC_PLAYERS_UNIT_TYPE_COUNT_EVALUATE_REL_OP_2);
	gCcPlayersUnitTypeCountEvaluateRelOp2RetAddr = gCcPlayersUnitTypeCountEvaluateRelOp2Addr + 5;
#endif
}

void ExpertFact::EnableDetours()
{
#if defined GAME_DE
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)FuncEvaluateRelOp, DetouredEvaluateRelOp);
	DetourTransactionCommit();
#elif defined GAME_AOC
	memory_utils::RegisterJump(gUpEvaluateRelOpAddr, &DetouredUpEvaluateRelOp);
	memory_utils::RegisterJump(gCcPlayersBuildingCountEvaluateRelOpAddr, &DetouredCcPlayersBuildingCountEvaluateRelOp);
	memory_utils::RegisterJump(gCcPlayersBuildingTypeCountEvaluateRelOpAddr, &DetouredCcPlayersBuildingTypeCountEvaluateRelOp);
	memory_utils::RegisterJump(gCcPlayersUnitCountEvaluateRelOpAddr, &DetouredCcPlayersUnitCountEvaluateRelOp);
	memory_utils::RegisterJump(gCcPlayersUnitTypeCountEvaluateRelOp1Addr, &DetouredCcPlayersUnitTypeCountEvaluateRelOp1, 7);
	memory_utils::RegisterJump(gCcPlayersUnitTypeCountEvaluateRelOp2Addr, &DetouredCcPlayersUnitTypeCountEvaluateRelOp2);
#endif
}

void ExpertFact::DisableDetours()
{
#if defined GAME_DE
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourDetach(&(PVOID&)FuncEvaluateRelOp, DetouredEvaluateRelOp);
	DetourTransactionCommit();
#elif defined GAME_AOC
	memory_utils::RemoveJump(gUpEvaluateRelOpAddr);
	memory_utils::RemoveJump(gCcPlayersBuildingCountEvaluateRelOpAddr);
	memory_utils::RemoveJump(gCcPlayersBuildingTypeCountEvaluateRelOpAddr);
	memory_utils::RemoveJump(gCcPlayersUnitCountEvaluateRelOpAddr);
	memory_utils::RemoveJump(gCcPlayersUnitTypeCountEvaluateRelOp1Addr);
	memory_utils::RemoveJump(gCcPlayersUnitTypeCountEvaluateRelOp2Addr);
#endif
}

#if defined GAME_DE
int64_t ExpertFact::DetouredEvaluateRelOp(int relOp, int arg1, int arg2, char a4, char a5)
{
	lastRelOpValue = arg1;

	return FuncEvaluateRelOp(relOp, arg1, arg2, a4, a5);
}
#elif defined GAME_AOC
void __declspec(naked) DetouredUpEvaluateRelOp()
{
	__asm {
		mov ExpertFact::lastRelOpValue, esi

		xor eax, eax
		cmp ecx, 6

		jmp[gUpEvaluateRelOpRetAddr]
	}
}

void __declspec(naked) DetouredCcPlayersBuildingCountEvaluateRelOp()
{
	__asm {
		mov ExpertFact::lastRelOpValue, ecx

		xor eax, eax
		cmp edx, 5

		jmp[gCcPlayersBuildingCountEvaluateRelOpRetAddr]
	}
}

void __declspec(naked) DetouredCcPlayersBuildingTypeCountEvaluateRelOp()
{
	__asm {
		mov ExpertFact::lastRelOpValue, esi

		xor eax, eax
		cmp ecx, 5

		jmp[gCcPlayersBuildingTypeCountEvaluateRelOpRetAddr]
	}
}

void __declspec(naked) DetouredCcPlayersUnitCountEvaluateRelOp()
{
	__asm {
		mov ExpertFact::lastRelOpValue, ecx

		xor eax, eax
		cmp edx, 5

		jmp[gCcPlayersUnitCountEvaluateRelOpRetAddr]
	}
}

void __declspec(naked) DetouredCcPlayersUnitTypeCountEvaluateRelOp1()
{
	__asm {
		movsx ecx, [edi+0x11CC]
		
		mov ExpertFact::lastRelOpValue, ecx

		jmp[gCcPlayersUnitTypeCountEvaluateRelOp1RetAddr]
	}
}

void __declspec(naked) DetouredCcPlayersUnitTypeCountEvaluateRelOp2()
{
	__asm {
		mov ExpertFact::lastRelOpValue, esi

		xor eax, eax
		cmp ecx, 5

		jmp[gCcPlayersUnitTypeCountEvaluateRelOp2RetAddr]
	}
}
#endif

int ExpertFact::AttackSoldierCount()
{
	return ExpertFact::UpGetFact(14, 0);
}

int ExpertFact::AttackWarboatCount()
{
	return ExpertFact::UpGetFact(17, 0);
}

bool ExpertFact::BuildingAvailable(int inConstBuildingId)
{
	return FuncBuildingAvailable(inConstBuildingId);
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

int ExpertFact::BuildingTypeCount(int inConstBuildingId)
{
	return ExpertFact::UpGetFact(28, inConstBuildingId);
}

int ExpertFact::BuildingTypeCountTotal(int inConstBuildingId)
{
	return ExpertFact::UpGetFact(29, inConstBuildingId);
}

bool ExpertFact::CanAffordBuilding(int inConstBuildingId)
{
	return FuncCanAffordBuilding(inConstBuildingId);
}

bool ExpertFact::CanAffordCompleteWall(int inConstPerimeter, int inConstWallId)
{
	return FuncCanAffordCompleteWall(inConstPerimeter, inConstWallId);
}

bool ExpertFact::CanAffordResearch(int inConstTechId)
{
	return FuncCanAffordResearch(inConstTechId);
}

bool ExpertFact::CanAffordUnit(int inConstUnitId)
{
	return FuncCanAffordUnit(inConstUnitId);
}

bool ExpertFact::CanBuild(int inConstBuildingId)
{
	return FuncCanBuild(inConstBuildingId);
}

bool ExpertFact::CanBuildGate(int inConstPerimeter)
{
	return FuncCanBuildGate(inConstPerimeter);
}

bool ExpertFact::CanBuildGateWithEscrow(int inConstPerimeter)
{
	return FuncCanBuildGateWithEscrow(inConstPerimeter);
}

bool ExpertFact::CanBuildWall(int inConstPerimeter, int inConstWallId)
{
	return FuncCanBuildWall(inConstPerimeter, inConstWallId);
}

bool ExpertFact::CanBuildWallWithEscrow(int inConstPerimeter, int inConstWallId)
{
	return FuncCanBuildWallWithEscrow(inConstPerimeter, inConstWallId);
}

bool ExpertFact::CanBuildWithEscrow(int inConstBuildingId)
{
	return FuncCanBuildWithEscrow(inConstBuildingId);
}

bool ExpertFact::CanBuyCommodity(int inConstCommodity)
{
	return FuncCanBuyCommodity(inConstCommodity);
}

bool ExpertFact::CanResearch(int inConstTechId)
{
	return FuncCanResearch(inConstTechId);
}

bool ExpertFact::CanResearchWithEscrow(int inConstTechId)
{
	return FuncCanResearchWithEscrow(inConstTechId);
}

bool ExpertFact::CanSellCommodity(int inConstCommodity)
{
	return FuncCanSellCommodity(inConstCommodity);
}

bool ExpertFact::CanSpy()
{
	return FuncCanSpy();
}

bool ExpertFact::CanSpyWithEscrow()
{
	return FuncCanSpyWithEscrow();
}

bool ExpertFact::CanTrain(int inConstUnitId)
{
	return FuncCanTrain(inConstUnitId);
}

bool ExpertFact::CanTrainWithEscrow(int inConstUnitId)
{
	return FuncCanTrainWithEscrow(inConstUnitId);
}

int ExpertFact::CcPlayersBuildingCount(int inPlayerAnyPlayer)
{
	lastRelOpValue = -1;
	FuncCcPlayersBuildingCount(inPlayerAnyPlayer, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::CcPlayersBuildingTypeCount(int inPlayerAnyPlayer, int inConstBuildingId)
{
	lastRelOpValue = -1;
	FuncCcPlayersBuildingTypeCount(inPlayerAnyPlayer, inConstBuildingId, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::CcPlayersUnitCount(int inPlayerAnyPlayer)
{
	lastRelOpValue = -1;
	FuncCcPlayersUnitCount(inPlayerAnyPlayer, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::CcPlayersUnitTypeCount(int inPlayerAnyPlayer, int inConstUnitId)
{
	lastRelOpValue = -1;
	FuncCcPlayersUnitTypeCount(inPlayerAnyPlayer, inConstUnitId, 0, 0);
	return lastRelOpValue;
}

bool ExpertFact::CheatsEnabled()
{
	return FuncCheatsEnabled();
}

int ExpertFact::CivSelected()
{
	return ExpertFact::UpGetFact(21, 0);
}

int ExpertFact::CivilianPopulation()
{
	return ExpertFact::UpGetFact(32, 0);
}

int ExpertFact::CommodityBuyingPrice(int inConstCommodity)
{
	return ExpertFact::UpGetFact(10, inConstCommodity);
}

int ExpertFact::CommoditySellingPrice(int inConstCommodity)
{
	return ExpertFact::UpGetFact(11, inConstCommodity);
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

bool ExpertFact::Doctrine(int inConstValue)
{
	return FuncDoctrine(inConstValue);
}

int ExpertFact::DropsiteMinDistance(int inConstResource)
{
	return ExpertFact::UpGetFact(12, inConstResource);
}

bool ExpertFact::EnemyBuildingsInTown()
{
	return FuncEnemyBuildingsInTown();
}

bool ExpertFact::EnemyCapturedRelics()
{
	return FuncEnemyCapturedRelics();
}

int ExpertFact::EscrowAmount(int inConstResource)
{
	return ExpertFact::UpGetFact(9, inConstResource);
}

bool ExpertFact::EventDetected(int inConstEventType, int inConstEventId)
{
	return FuncEventDetected(inConstEventType, inConstEventId);
}

bool ExpertFact::False()
{
	return false;
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

int ExpertFact::GateCount(int inConstPerimeter)
{
#if defined GAME_DE
	lastRelOpValue = -1;
	FuncGateCount(inConstPerimeter, 0, 0);
	return lastRelOpValue;
#elif defined GAME_AOC
	if (inConstPerimeter != 1 && inConstPerimeter != 2)
		return 0;

	return FuncInternalGetGateCount(*(void**)expert_conf::ADDR_PTR_THIS_INFORMATION_AI, inConstPerimeter - 1);
#endif
}

int ExpertFact::Goal(int inConstGoalId)
{
	// call up-compare-goal instead as the usual goal fact doesn't call EvaluateRelOp
	lastRelOpValue = -1;
	FuncUpCompareGoal(inConstGoalId, 0, 0);
	return lastRelOpValue;
}

std::vector<int> ExpertFact::GoalList()
{
	std::vector<int> result;
	for (int i = 1; i <= 512; i++)
		result.push_back(Goal(i));

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

int ExpertFact::MapSize()
{
	for (int i = 0; i <= 6; i++)
		if (FuncMapSize(i))
			return i;

	return -1;
}

int ExpertFact::MapType()
{
	for (int i = -1; i <= 200; i++)
		if (FuncMapType(i))
			return i;

	return 0;
}

int ExpertFact::MilitaryPopulation()
{
	return ExpertFact::UpGetFact(31, 0);
}

bool ExpertFact::PlayerComputer(int inPlayerAnyPlayer)
{
	return FuncPlayerComputer(inPlayerAnyPlayer);
}

bool ExpertFact::PlayerHuman(int inPlayerAnyPlayer)
{
	return FuncPlayerHuman(inPlayerAnyPlayer);
}

bool ExpertFact::PlayerInGame(int inPlayerAnyPlayer)
{
	return FuncPlayerInGame(inPlayerAnyPlayer);
}

bool ExpertFact::PlayerNumber(int inPlayerAnyPlayer)
{
	return FuncPlayerNumber(inPlayerAnyPlayer);
}

bool ExpertFact::PlayerResigned(int inPlayerAnyPlayer)
{
	return FuncPlayerResigned(inPlayerAnyPlayer);
}

bool ExpertFact::PlayerValid(int inPlayerAnyPlayer)
{
	return FuncPlayerValid(inPlayerAnyPlayer);
}

bool ExpertFact::PlayersAchievements(int param1, int param2, int param3, int param4)
{
	return FuncPlayersAchievements(param1, param2, param3, param4);
}

int ExpertFact::PlayersBuildingCount(int inPlayerAnyPlayer)
{
	return ExpertFact::UpGetPlayerFact(inPlayerAnyPlayer, 27, 0);
}

int ExpertFact::PlayersBuildingTypeCount(int inPlayerAnyPlayer, int inConstBuildingId)
{
	return ExpertFact::UpGetPlayerFact(inPlayerAnyPlayer, 28, inConstBuildingId);
}

bool ExpertFact::PlayersCiv(int inPlayerAnyPlayer)
{
	return FuncPlayersCiv(inPlayerAnyPlayer);
}

int ExpertFact::PlayersCivilianPopulation(int inPlayerAnyPlayer)
{
	return ExpertFact::UpGetPlayerFact(inPlayerAnyPlayer, 32, 0);
}

int ExpertFact::PlayersCurrentAge(int inPlayerAnyPlayer)
{
	return ExpertFact::UpGetPlayerFact(inPlayerAnyPlayer, 19, 0);
}

int ExpertFact::PlayersCurrentAgeTime(int inPlayerAnyPlayer)
{
	return ExpertFact::UpGetPlayerFact(inPlayerAnyPlayer, 50, 0);
}

int ExpertFact::PlayersMilitaryPopulation(int inPlayerAnyPlayer)
{
	return ExpertFact::UpGetPlayerFact(inPlayerAnyPlayer, 31, 0);
}

int ExpertFact::PlayersPopulation(int playerNumber)
{
	return ExpertFact::UpGetPlayerFact(playerNumber, 30, 0);
}

int ExpertFact::PlayersScore(int inPlayerAnyPlayer)
{
	return ExpertFact::UpGetPlayerFact(inPlayerAnyPlayer, 20, 0);
}

bool ExpertFact::PlayersStance(int inPlayerAnyPlayer, int inConstESPlayerStance)
{
	return FuncPlayersStance(inPlayerAnyPlayer, inConstESPlayerStance);
}

int ExpertFact::PlayersTribute(int inPlayerAnyPlayer, int inConstResource)
{
	return ExpertFact::UpGetPlayerFact(inPlayerAnyPlayer, 52, inConstResource);
}

int ExpertFact::PlayersTributeMemory(int inPlayerAnyPlayer, int inConstResource)
{
	return ExpertFact::UpGetPlayerFact(inPlayerAnyPlayer, 53, inConstResource);
}

int ExpertFact::PlayersUnitCount(int inPlayerAnyPlayer)
{
	return ExpertFact::UpGetPlayerFact(inPlayerAnyPlayer, 24, 0);
}

int ExpertFact::PlayersUnitTypeCount(int inPlayerAnyPlayer, int inConstUnitId)
{
	return ExpertFact::UpGetPlayerFact(inPlayerAnyPlayer, 25, inConstUnitId);
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

bool ExpertFact::ResearchAvailable(int inConstTechId)
{
	return FuncResearchAvailable(inConstTechId);
}

bool ExpertFact::ResearchCompleted(int inConstTechId)
{
	return FuncResearchCompleted(inConstTechId);
}

bool ExpertFact::ResourceFound(int inConstResource)
{
	return FuncResourceFound(inConstResource);
}

bool ExpertFact::SharedGoal(int inConstSharedGoalId, int inConstValue)
{
	return FuncSharedGoal(inConstSharedGoalId, inConstValue);
}

bool ExpertFact::SheepAndForageTooFar()
{
	return FuncSheepAndForageTooFar();
}

int ExpertFact::SoldierCount()
{
	return ExpertFact::UpGetFact(13, 0);
}

bool ExpertFact::StanceToward(int inPlayerAnyPlayer, int inConstESPlayerStance)
{
	return FuncStanceToward(inPlayerAnyPlayer, inConstESPlayerStance);
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

int ExpertFact::StrategicNumber(int inConstSnId)
{
#if defined GAME_DE
	lastRelOpValue = -1;
	FuncStrategicNumber(inConstSnId, 0, 0);
	return lastRelOpValue;
#elif defined GAME_AOC
	return FuncInternalStrategicNumber(*(void**)expert_conf::ADDR_PTR_THIS_TACTICAL_AI, inConstSnId);
#endif
}

std::vector<int> ExpertFact::StrategicNumberList()
{
	std::vector<int> result;
	for (int i = 0; i < 512; i++)
		result.push_back(StrategicNumber(i));

	return result;
}

bool ExpertFact::TauntDetected(int inPlayerAnyPlayer, int inConstTauntId)
{
	return FuncTauntDetected(inPlayerAnyPlayer, inConstTauntId);
}

bool ExpertFact::TimerTriggered(int inConstTimerId)
{
	return FuncTimerTriggered(inConstTimerId);
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
	return true;
}

bool ExpertFact::UnitAvailable(int inConstUnitId)
{
	return FuncUnitAvailable(inConstUnitId);
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

int ExpertFact::UnitTypeCount(int inConstUnitId)
{
	return ExpertFact::UpGetFact(25, inConstUnitId);
}

int ExpertFact::UnitTypeCountTotal(int inConstUnitId)
{
	return ExpertFact::UpGetFact(26, inConstUnitId);
}

int ExpertFact::UpAlliedGoal(int inPlayerComputerAllyPlayer, int inGoalId)
{
	lastRelOpValue = -1;
	FuncUpAlliedGoal(inPlayerComputerAllyPlayer, inGoalId, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpAlliedResourceAmount(int inPlayerAllyPlayer, int inConstResourceAmount)
{
	lastRelOpValue = -1;
	FuncUpAlliedResourceAmount(inPlayerAllyPlayer, inConstResourceAmount, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpAlliedResourcePercent(int inPlayerAllyPlayer, int inConstResourceAmount)
{
	lastRelOpValue = -1;
	FuncUpAlliedResourcePercent(inPlayerAllyPlayer, inConstResourceAmount, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpAlliedSn(int inPlayerComputerAllyPlayer, int inSnId)
{
	lastRelOpValue = -1;
	FuncUpAlliedSn(inPlayerComputerAllyPlayer, inSnId, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpAttackerClass()
{
	lastRelOpValue = -1;
	FuncUpAttackerClass(0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpBuildingTypeInTown(int typeOp, int inOpBuildingId)
{
#if defined GAME_AOC
	ChangeTypeOpToConst(typeOp, inOpBuildingId);
#endif

	lastRelOpValue = -1;
	FuncUpBuildingTypeInTown(typeOp, inOpBuildingId, 0, 0);
	return lastRelOpValue;
}

bool ExpertFact::UpCanBuild(int inGoalEscrowState, int typeOp, int inOpBuildingId)
{
#if defined GAME_AOC
	ChangeTypeOpToConst(typeOp, inOpBuildingId);
#endif

	return FuncUpCanBuild(inGoalEscrowState, typeOp, inOpBuildingId);
}

bool ExpertFact::UpCanBuildLine(int inGoalEscrowState, int inGoalPoint, int typeOp, int inOpBuildingId)
{
#if defined GAME_AOC
	ChangeTypeOpToConst(typeOp, inOpBuildingId);
#endif

	return FuncUpCanBuildLine(inGoalEscrowState, inGoalPoint, typeOp, inOpBuildingId);
}

bool ExpertFact::UpCanResearch(int inGoalEscrowState, int typeOp, int inOpTechId)
{
#if defined GAME_AOC
	ChangeTypeOpToConst(typeOp, inOpTechId);
#endif

	return FuncUpCanResearch(inGoalEscrowState, typeOp, inOpTechId);
}

bool ExpertFact::UpCanSearch(int inConstSearchSource)
{
	return FuncUpCanSearch(inConstSearchSource);
}

bool ExpertFact::UpCanTrain(int inGoalEscrowState, int typeOp, int inOpUnitId)
{
#if defined GAME_AOC
	ChangeTypeOpToConst(typeOp, inOpUnitId);
#endif

	return FuncUpCanTrain(inGoalEscrowState, typeOp, inOpUnitId);
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

int ExpertFact::UpGaiaTypeCount(int inConstResource)
{
	lastRelOpValue = -1;
	FuncUpGaiaTypeCount(0, inConstResource, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpGaiaTypeCountTotal(int inConstResource)
{
	lastRelOpValue = -1;
	FuncUpGaiaTypeCountTotal(0, inConstResource, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpGetFact(int inConstFactId, int inConstParam)
{
	// Cache goal, read new fact into goal
	int cachedGoal = ExpertFact::Goal(512);
	ExpertAction::UpGetFact(inConstFactId, inConstParam, 512);
	int result = ExpertFact::Goal(512);

	// Restore goal and return result
	ExpertAction::SetGoal(512, cachedGoal);
	return result;
}

int ExpertFact::UpGetPlayerFact(int inPlayerAnyPlayer, int inConstFactId, int inConstParam)
{
	// Cache goal, read new fact into goal
	int cachedGoal = ExpertFact::Goal(512);
	ExpertAction::UpGetPlayerFact(inPlayerAnyPlayer, inConstFactId, inConstParam, 512);
	int result = ExpertFact::Goal(512);

	// Restore goal and return result
	ExpertAction::SetGoal(512, cachedGoal);
	return result;
}

std::array<int, 4> ExpertFact::UpGetSearchState()
{
	std::array<int, 4> result;

	// cache 4 goals that will be overwritten
	int cachedGoals[4];
	for (int i = 0; i < 4; i++) cachedGoals[i] = ExpertFact::Goal(400 + i);

	// get search state into these 4 goals and populate the result
	ExpertAction::UpGetSearchState(400);
	for (int i = 0; i < 4; i++) result[i] = ExpertFact::Goal(400 + i);

	// restore cached goals and return the result
	for (int i = 0; i < 4; i++) ExpertAction::SetGoal(400 + i, cachedGoals[i]);
	return result;
}

int ExpertFact::UpGroupSize(int typeOp, int inOpGroupId)
{
#if defined GAME_AOC
	ChangeTypeOpToConst(typeOp, inOpGroupId);
#endif

	lastRelOpValue = -1;
	FuncUpGroupSize(typeOp, inOpGroupId, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpIdleUnitCount(int inConstIdleType)
{
	lastRelOpValue = -1;
	FuncUpIdleUnitCount(inConstIdleType, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpObjectData(int inConstObjectData)
{
	lastRelOpValue = -1;
	FuncUpObjectData(inConstObjectData, 0, 0);
	return lastRelOpValue;
}

std::vector<int> ExpertFact::UpObjectDataList()
{
	std::vector<int> result;
	for (int dataIndex = 0; dataIndex <= 84; dataIndex++)
	{
#if defined GAME_DE
		// object-data-locked crashes in DE if used on a non-lockable object, thus check:
		// dataIndex == object-data-locked && object-data-class != gate-class
		if (dataIndex == 29 && UpObjectData(2) != 939)
		{
			result.push_back(-1);
			continue;
		}
#endif

		result.push_back(UpObjectData(dataIndex));
	}

	return result;
}

int ExpertFact::UpObjectTargetData(int inConstObjectData)
{
	lastRelOpValue = -1;
	FuncUpObjectTargetData(inConstObjectData, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpObjectTypeCount(int typeOp, int inOpObjectId)
{
#if defined GAME_AOC
	ChangeTypeOpToConst(typeOp, inOpObjectId);
#endif

	lastRelOpValue = -1;
	FuncUpObjectTypeCount(typeOp, inOpObjectId, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpObjectTypeCountTotal(int typeOp, int inOpObjectId)
{
#if defined GAME_AOC
	ChangeTypeOpToConst(typeOp, inOpObjectId);
#endif

	lastRelOpValue = -1;
	FuncUpObjectTypeCountTotal(typeOp, inOpObjectId, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpPathDistance(int inGoalPoint, int inConstStrict)
{
	lastRelOpValue = -1;
	FuncUpPathDistance(inGoalPoint, inConstStrict, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpPendingObjects(int typeOp, int inOpObjectId)
{
#if defined GAME_AOC
	ChangeTypeOpToConst(typeOp, inOpObjectId);
#endif

	lastRelOpValue = -1;
	FuncUpPendingObjects(typeOp, inOpObjectId, 0, 0);
	return lastRelOpValue;
}

bool ExpertFact::UpPendingPlacement(int typeOp, int inOpBuildingId)
{
#if defined GAME_AOC
	ChangeTypeOpToConst(typeOp, inOpBuildingId);
#endif

	return FuncUpPendingPlacement(typeOp, inOpBuildingId);
}

int ExpertFact::UpPlayerDistance(int inPlayerAnyPlayer)
{
	lastRelOpValue = -1;
	FuncUpPlayerDistance(inPlayerAnyPlayer, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpPlayersInGame(int inConstPlayerStance)
{
	lastRelOpValue = -1;
	FuncUpPlayersInGame(inConstPlayerStance, 0, 0);
	return lastRelOpValue;
}

bool ExpertFact::UpPointContains(int inGoalPoint, int typeOp, int inOpObjectId)
{
#if defined GAME_AOC
	ChangeTypeOpToConst(typeOp, inOpObjectId);
#endif

	return FuncUpPointContains(inGoalPoint, typeOp, inOpObjectId);
}

int ExpertFact::UpPointDistance(int inGoalPoint1, int inGoalPoint2)
{
	lastRelOpValue = -1;
	FuncUpPointDistance(inGoalPoint1, inGoalPoint2, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpPointElevation(int inGoalPoint)
{
	lastRelOpValue = -1;
	FuncUpPointElevation(inGoalPoint, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpPointExplored(int inGoalPoint)
{
	lastRelOpValue = -1;
	FuncUpPointExplored(inGoalPoint, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpPointTerrain(int inGoalPoint)
{
	lastRelOpValue = -1;
	FuncUpPointTerrain(inGoalPoint, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpPointZone(int inGoalPoint)
{
	lastRelOpValue = -1;
	FuncUpPointZone(inGoalPoint, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpProjectileDetected(int inConstProjectileType)
{
	lastRelOpValue = -1;
	FuncUpProjectileDetected(inConstProjectileType, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpProjectileTarget(int inConstProjectileType)
{
	lastRelOpValue = -1;
	FuncUpProjectileTarget(inConstProjectileType, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpRemainingBoarAmount()
{
	lastRelOpValue = -1;
	FuncUpRemainingBoarAmount(0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpResearchStatus(int typeOp, int inOpTechId)
{
#if defined GAME_AOC
	ChangeTypeOpToConst(typeOp, inOpTechId);
#endif

	lastRelOpValue = -1;
	FuncUpResearchStatus(typeOp, inOpTechId, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpResourceAmount(int inConstResourceAmount)
{
	lastRelOpValue = -1;
	FuncUpResourceAmount(inConstResourceAmount, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpResourcePercent(int inConstResourceAmount)
{
	lastRelOpValue = -1;
	FuncUpResourcePercent(inConstResourceAmount, 0, 0);
	return lastRelOpValue;
}

std::vector<int> ExpertFact::UpSearchObjectIdList(int inConstSearchSource)
{
	std::vector<int> result;
	
	if (inConstSearchSource == 1 || inConstSearchSource == 2)
	{
		std::array<int, 4> searchState = ExpertFact::UpGetSearchState();
		int cachedTargetObjectId = ExpertFact::UpObjectData(0);

		// unitCount = (searchSource == search-remote) ? gl-remote-total : gl-local-total
		int unitCount = (inConstSearchSource == 2) ? searchState[2] : searchState[0];
		for (int i = 0; i < unitCount; i++)
		{
			ExpertAction::UpSetTargetObject(inConstSearchSource, expert_conf::CONST_TYPE_OP_CONST, i);
			result.push_back(ExpertFact::UpObjectData(0));
		}

		// restore target object, not sure that this is 100% reliable though,
		// as what happens if the original target object is not valid and this
		// func uses valid ones meanwhile?
		ExpertAction::UpSetTargetById(expert_conf::CONST_TYPE_OP_CONST, cachedTargetObjectId);
	}

	return result;
}

int ExpertFact::UpTimerStatus(int inConstTimerId)
{
	lastRelOpValue = -1;
	FuncUpTimerStatus(inConstTimerId, 0, 0);
	return lastRelOpValue;
}

bool ExpertFact::UpTrainSiteReady(int typeOp, int inOpUnitId)
{
#if defined GAME_AOC
	ChangeTypeOpToConst(typeOp, inOpUnitId);
#endif

	return FuncUpTrainSiteReady(typeOp, inOpUnitId);
}

int ExpertFact::UpUnitTypeInTown(int typeOp, int inOpUnitId)
{
#if defined GAME_AOC
	ChangeTypeOpToConst(typeOp, inOpUnitId);
#endif

	lastRelOpValue = -1;
	FuncUpUnitTypeInTown(typeOp, inOpUnitId, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpVillagerTypeInTown(int typeOp, int inOpUnitId)
{
#if defined GAME_AOC
	ChangeTypeOpToConst(typeOp, inOpUnitId);
#endif

	lastRelOpValue = -1;
	FuncUpVillagerTypeInTown(typeOp, inOpUnitId, 0, 0);
	return lastRelOpValue;
}

bool ExpertFact::VictoryCondition(int inConstVictory)
{
	return FuncVictoryCondition(inConstVictory);
}

int ExpertFact::WallCompletedPercentage(int inConstPerimeter)
{
#if defined GAME_DE
	lastRelOpValue = -1;
	FuncWallCompletedPercentage(inConstPerimeter, 0, 0);
	return lastRelOpValue;
#elif defined GAME_AOC
	if (inConstPerimeter != 1 && inConstPerimeter != 2)
		return 0;

	return FuncInternalWallCompletedPercentage(*(void**)expert_conf::ADDR_PTR_THIS_INFORMATION_AI, inConstPerimeter - 1);
#endif
}

int ExpertFact::WallInvisiblePercentage(int inConstPerimeter)
{
#if defined GAME_DE
	lastRelOpValue = -1;
	FuncWallInvisiblePercentage(inConstPerimeter, 0, 0);
	return lastRelOpValue;
#elif defined GAME_AOC
	if (inConstPerimeter != 1 && inConstPerimeter != 2)
		return 0;
	
	return FuncInternalWallInvisiblePercentage(*(void**)expert_conf::ADDR_PTR_THIS_INFORMATION_AI, inConstPerimeter - 1);
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

void ExpertFact::ChangeTypeOpToConst(int& typeOp, int& opValue)
{
	switch (typeOp)
	{
		case expert_conf::CONST_TYPE_OP_GOAL:
		{
			opValue = ExpertFact::Goal(opValue);
			break;
		}
		case expert_conf::CONST_TYPE_OP_SN:
		{
			opValue = ExpertFact::StrategicNumber(opValue);
			break;
		}
	}

	typeOp = expert_conf::CONST_TYPE_OP_CONST;
}
