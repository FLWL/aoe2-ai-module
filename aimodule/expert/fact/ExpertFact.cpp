#include "ExpertFact.h"

#include <iostream>

#include <Windows.h>
#include <detours/detours.h>

#include "expert/action/ExpertAction.h"
#include "misc/Statics.h"
#include "misc/MemoryUtils.h"
#include "structs/Game.h"

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

ExpertFact::~ExpertFact()
{
	DisableDetours();
	ClearFactFunctions();
}

void ExpertFact::Initialize(const structs::AIExpert* aiExpert)
{
	LoadFactFunctions(aiExpert);
	UpdateAddresses();
	EnableDetours();
}

void ExpertFact::LoadFactFunctions(const structs::AIExpert* aiExpert)
{
#if defined GAME_DE
	for (int factId = 0; factId < aiExpert->numFacts; factId++)
	{
		FactFunction* factFunction = new FactFunction{ (uintptr_t)aiExpert->fact[factId].factFn, aiExpert->fact[factId].argc };
		factFunctionMap.insert({ std::string(aiExpert->factNames[factId]), factFunction });
	}
#elif defined GAME_AOC
	for (int tableIndex = 0; tableIndex < aiExpert->globalSymbolTableSize; tableIndex++)
	{
		structs::SymbolHashNode* node = aiExpert->bucket[tableIndex];

		while (node)
		{
			if (node->type == 3)
			{
				FactFunction* factFunction = new FactFunction{ (uintptr_t)aiExpert->fact[node->id].factFn, aiExpert->fact[node->id].argc };
				factFunctionMap.insert({ std::string(node->symbolText), factFunction });
			}

			node = node->next;
		}
	}
#endif

	std::cout << "[Expert] Loaded " << factFunctionMap.size() << " fact functions." << std::endl;
}

void ExpertFact::ClearFactFunctions()
{
	for (auto& element : factFunctionMap)
		delete element.second;

	factFunctionMap.clear();
}

void ExpertFact::UpdateAddresses()
{
#if defined GAME_DE
	try
	{
		uintptr_t callInstructionToEvaluateRelOpAddress = factFunctionMap.at("current-score")->address + 45;
		std::vector<uint8_t> callInstructionToEvaluateRelOpData = memory_utils::ReadMemory(callInstructionToEvaluateRelOpAddress, 5);
		statics::SetFuncAddr(FuncEvaluateRelOp, memory_utils::GetInstructionImmMemOperand(callInstructionToEvaluateRelOpAddress, callInstructionToEvaluateRelOpData));
	}
	catch (const std::exception&) {}
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
	LONG transactionResult = DetourTransactionCommit();

	if (transactionResult != NO_ERROR)
	{
		std::cout << "[Expert] Error: failed to detour function 'EvaluateRelOp'."
			<< " Error code " << transactionResult
			<< ", game module base address 0x" << std::hex << statics::GetGameModuleBaseAddr() << std::dec
			<< ", function address 0x" << std::hex << (uintptr_t) FuncEvaluateRelOp << std::dec
			<< ". Some facts will return invalid results and certain actions will not work." << std::endl;
	}
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
	__asm
	{
		mov ExpertFact::lastRelOpValue, esi

		xor eax, eax
		cmp ecx, 6

		jmp[gUpEvaluateRelOpRetAddr]
	}
}

void __declspec(naked) DetouredCcPlayersBuildingCountEvaluateRelOp()
{
	__asm
	{
		mov ExpertFact::lastRelOpValue, ecx

		xor eax, eax
		cmp edx, 5

		jmp[gCcPlayersBuildingCountEvaluateRelOpRetAddr]
	}
}

void __declspec(naked) DetouredCcPlayersBuildingTypeCountEvaluateRelOp()
{
	__asm
	{
		mov ExpertFact::lastRelOpValue, esi

		xor eax, eax
		cmp ecx, 5

		jmp[gCcPlayersBuildingTypeCountEvaluateRelOpRetAddr]
	}
}

void __declspec(naked) DetouredCcPlayersUnitCountEvaluateRelOp()
{
	__asm
	{
		mov ExpertFact::lastRelOpValue, ecx

		xor eax, eax
		cmp edx, 5

		jmp[gCcPlayersUnitCountEvaluateRelOpRetAddr]
	}
}

void __declspec(naked) DetouredCcPlayersUnitTypeCountEvaluateRelOp1()
{
	__asm
	{
		movsx ecx, [edi+0x11CC]
		
		mov ExpertFact::lastRelOpValue, ecx

		jmp[gCcPlayersUnitTypeCountEvaluateRelOp1RetAddr]
	}
}

void __declspec(naked) DetouredCcPlayersUnitTypeCountEvaluateRelOp2()
{
	__asm
	{
		mov ExpertFact::lastRelOpValue, esi

		xor eax, eax
		cmp ecx, 5

		jmp[gCcPlayersUnitTypeCountEvaluateRelOp2RetAddr]
	}
}
#endif

int ExpertFact::ExecuteFactFunction(const FactFunction& factFunction, const int arg1, const int arg2, const int arg3, const int arg4)
{
	switch (factFunction.argc)
	{
		case 0: return ((int(*)(void))factFunction.address)();
		case 1: return ((int(*)(int))factFunction.address)(arg1);
		case 2: return ((int(*)(int, int))factFunction.address)(arg1, arg2);
		case 3: return ((int(*)(int, int, int))factFunction.address)(arg1, arg2, arg3);
		case 4: return ((int(*)(int, int, int, int))factFunction.address)(arg1, arg2, arg3, arg4);
	}

	return 0;
}

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
	static const FactFunction factFunction = *factFunctionMap.at("building-available");
	return ExecuteFactFunction(factFunction, inConstBuildingId);
}

int ExpertFact::BuildingCount()
{
	return ExpertFact::UpGetFact(27, 0);
}

int ExpertFact::BuildingCountTotal()
{
#if defined GAME_DE
	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("building-count-total");
	ExecuteFactFunction(factFunction, 0, 0);
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
	static const FactFunction factFunction = *factFunctionMap.at("can-afford-building");
	return ExecuteFactFunction(factFunction, inConstBuildingId);
}

bool ExpertFact::CanAffordCompleteWall(int inConstPerimeter, int inConstWallId)
{
	static const FactFunction factFunction = *factFunctionMap.at("can-afford-complete-wall");
	return ExecuteFactFunction(factFunction, inConstPerimeter, inConstWallId);
}

bool ExpertFact::CanAffordResearch(int inConstTechId)
{
	static const FactFunction factFunction = *factFunctionMap.at("can-afford-research");
	return ExecuteFactFunction(factFunction, inConstTechId);
}

bool ExpertFact::CanAffordUnit(int inConstUnitId)
{
	static const FactFunction factFunction = *factFunctionMap.at("can-afford-unit");
	return ExecuteFactFunction(factFunction, inConstUnitId);
}

bool ExpertFact::CanBuild(int inConstBuildingId)
{
	static const FactFunction factFunction = *factFunctionMap.at("can-build");
	return ExecuteFactFunction(factFunction, inConstBuildingId);
}

bool ExpertFact::CanBuildGate(int inConstPerimeter)
{
	static const FactFunction factFunction = *factFunctionMap.at("can-build-gate");
	return ExecuteFactFunction(factFunction, inConstPerimeter);
}

bool ExpertFact::CanBuildGateWithEscrow(int inConstPerimeter)
{
	static const FactFunction factFunction = *factFunctionMap.at("can-build-gate-with-escrow");
	return ExecuteFactFunction(factFunction, inConstPerimeter);
}

bool ExpertFact::CanBuildWall(int inConstPerimeter, int inConstWallId)
{
	static const FactFunction factFunction = *factFunctionMap.at("can-build-wall");
	return ExecuteFactFunction(factFunction, inConstPerimeter, inConstWallId);
}

bool ExpertFact::CanBuildWallWithEscrow(int inConstPerimeter, int inConstWallId)
{
	static const FactFunction factFunction = *factFunctionMap.at("can-build-wall-with-escrow");
	return ExecuteFactFunction(factFunction, inConstPerimeter, inConstWallId);
}

bool ExpertFact::CanBuildWithEscrow(int inConstBuildingId)
{
	static const FactFunction factFunction = *factFunctionMap.at("can-build-with-escrow");
	return ExecuteFactFunction(factFunction, inConstBuildingId);
}

bool ExpertFact::CanBuyCommodity(int inConstCommodity)
{
	static const FactFunction factFunction = *factFunctionMap.at("can-buy-commodity");
	return ExecuteFactFunction(factFunction, inConstCommodity);
}

bool ExpertFact::CanResearch(int inConstTechId)
{
	static const FactFunction factFunction = *factFunctionMap.at("can-research");
	return ExecuteFactFunction(factFunction, inConstTechId);
}

bool ExpertFact::CanResearchWithEscrow(int inConstTechId)
{
	static const FactFunction factFunction = *factFunctionMap.at("can-research-with-escrow");
	return ExecuteFactFunction(factFunction, inConstTechId);
}

bool ExpertFact::CanSellCommodity(int inConstCommodity)
{
	static const FactFunction factFunction = *factFunctionMap.at("can-sell-commodity");
	return ExecuteFactFunction(factFunction, inConstCommodity);
}

bool ExpertFact::CanSpy()
{
	static const FactFunction factFunction = *factFunctionMap.at("can-spy");
	return ExecuteFactFunction(factFunction);
}

bool ExpertFact::CanSpyWithEscrow()
{
	static const FactFunction factFunction = *factFunctionMap.at("can-spy-with-escrow");
	return ExecuteFactFunction(factFunction);
}

bool ExpertFact::CanTrain(int inConstUnitId)
{
	static const FactFunction factFunction = *factFunctionMap.at("can-train");
	return ExecuteFactFunction(factFunction, inConstUnitId);
}

bool ExpertFact::CanTrainWithEscrow(int inConstUnitId)
{
	static const FactFunction factFunction = *factFunctionMap.at("can-train-with-escrow");
	return ExecuteFactFunction(factFunction, inConstUnitId);
}

int ExpertFact::CcPlayersBuildingCount(int inPlayerAnyPlayer)
{
	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("cc-players-building-count");
	ExecuteFactFunction(factFunction, inPlayerAnyPlayer, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::CcPlayersBuildingTypeCount(int inPlayerAnyPlayer, int inConstBuildingId)
{
	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("cc-players-building-type-count");
	ExecuteFactFunction(factFunction, inPlayerAnyPlayer, inConstBuildingId, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::CcPlayersUnitCount(int inPlayerAnyPlayer)
{
	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("cc-players-unit-count");
	ExecuteFactFunction(factFunction, inPlayerAnyPlayer, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::CcPlayersUnitTypeCount(int inPlayerAnyPlayer, int inConstUnitId)
{
	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("cc-players-unit-type-count");
	ExecuteFactFunction(factFunction, inPlayerAnyPlayer, inConstUnitId, 0, 0);
	return lastRelOpValue;
}

bool ExpertFact::CheatsEnabled()
{
	static const FactFunction factFunction = *factFunctionMap.at("cheats-enabled");
	return ExecuteFactFunction(factFunction);
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
	static const FactFunction factFunction = *factFunctionMap.at("death-match-game");
	return ExecuteFactFunction(factFunction);
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
	static const FactFunction factFunction = *factFunctionMap.at("difficulty");
	ExecuteFactFunction(factFunction, 0, 0);
	return lastRelOpValue;
#elif defined GAME_AOC
	return *(int32_t*)expert_conf::ADDR_VAR_DIFFICULTY;
#endif
}

bool ExpertFact::Doctrine(int inConstValue)
{
	static const FactFunction factFunction = *factFunctionMap.at("doctrine");
	return ExecuteFactFunction(factFunction, inConstValue);
}

int ExpertFact::DropsiteMinDistance(int inConstResource)
{
	return ExpertFact::UpGetFact(12, inConstResource);
}

bool ExpertFact::EnemyBuildingsInTown()
{
	static const FactFunction factFunction = *factFunctionMap.at("enemy-buildings-in-town");
	return ExecuteFactFunction(factFunction);
}

bool ExpertFact::EnemyCapturedRelics()
{
	static const FactFunction factFunction = *factFunctionMap.at("enemy-captured-relics");
	return ExecuteFactFunction(factFunction);
}

int ExpertFact::EscrowAmount(int inConstResource)
{
	return ExpertFact::UpGetFact(9, inConstResource);
}

bool ExpertFact::EventDetected(int inConstEventType, int inConstEventId)
{
	static const FactFunction factFunction = *factFunctionMap.at("event-detected");
	return ExecuteFactFunction(factFunction, inConstEventType, inConstEventId);
}

bool ExpertFact::False()
{
	static const FactFunction factFunction = *factFunctionMap.at("false");
	return ExecuteFactFunction(factFunction);
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
	static const FactFunction factFunction = *factFunctionMap.at("game-type");
	ExecuteFactFunction(factFunction, 0, 0);
	return lastRelOpValue;
#elif defined GAME_AOC
	return FuncInternalGameType(*(void**)expert_conf::ADDR_PTR_BASE_GAME) & 0xFF;
#endif
}

int ExpertFact::GateCount(int inConstPerimeter)
{
#if defined GAME_DE
	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("gate-count");
	ExecuteFactFunction(factFunction, inConstPerimeter, 0, 0);
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
	static const FactFunction factFunction = *factFunctionMap.at("up-compare-goal");
	ExecuteFactFunction(factFunction, inConstGoalId, 0, 0);
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
	static const FactFunction factFunction = *factFunctionMap.at("hold-koh-ruin");
	return ExecuteFactFunction(factFunction);
}

bool ExpertFact::HoldRelics()
{
	static const FactFunction factFunction = *factFunctionMap.at("hold-relics");
	return ExecuteFactFunction(factFunction);
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
	static const FactFunction factFunction = *factFunctionMap.at("map-size");

	for (int i = 0; i <= 6; i++)
		if (ExecuteFactFunction(factFunction, i))
			return i;

	return -1;
}

int ExpertFact::MapType()
{
	static const FactFunction factFunction = *factFunctionMap.at("map-type");

	for (int i = -1; i <= 200; i++)
		if (ExecuteFactFunction(factFunction, i))
			return i;

	return 0;
}

int ExpertFact::MilitaryPopulation()
{
	return ExpertFact::UpGetFact(31, 0);
}

bool ExpertFact::PlayerComputer(int inPlayerAnyPlayer)
{
	static const FactFunction factFunction = *factFunctionMap.at("player-computer");
	return ExecuteFactFunction(factFunction, inPlayerAnyPlayer);
}

bool ExpertFact::PlayerHuman(int inPlayerAnyPlayer)
{
	static const FactFunction factFunction = *factFunctionMap.at("player-human");
	return ExecuteFactFunction(factFunction, inPlayerAnyPlayer);
}

bool ExpertFact::PlayerInGame(int inPlayerAnyPlayer)
{
	static const FactFunction factFunction = *factFunctionMap.at("player-in-game");
	return ExecuteFactFunction(factFunction, inPlayerAnyPlayer);
}

bool ExpertFact::PlayerNumber(int inPlayerAnyPlayer)
{
	static const FactFunction factFunction = *factFunctionMap.at("player-number");
	return ExecuteFactFunction(factFunction, inPlayerAnyPlayer);
}

bool ExpertFact::PlayerResigned(int inPlayerAnyPlayer)
{
	static const FactFunction factFunction = *factFunctionMap.at("player-resigned");
	return ExecuteFactFunction(factFunction, inPlayerAnyPlayer);
}

bool ExpertFact::PlayerValid(int inPlayerAnyPlayer)
{
	static const FactFunction factFunction = *factFunctionMap.at("player-valid");
	return ExecuteFactFunction(factFunction, inPlayerAnyPlayer);
}

bool ExpertFact::PlayersAchievements(int param1, int param2, int param3, int param4)
{
	static const FactFunction factFunction = *factFunctionMap.at("players-achievements");
	return ExecuteFactFunction(factFunction, param1, param2, param3, param4);
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
	static const FactFunction factFunction = *factFunctionMap.at("players-civ");
	return ExecuteFactFunction(factFunction, inPlayerAnyPlayer);
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
	static const FactFunction factFunction = *factFunctionMap.at("players-stance");
	return ExecuteFactFunction(factFunction, inPlayerAnyPlayer, inConstESPlayerStance);
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
	static const FactFunction factFunction = *factFunctionMap.at("regicide-game");
	return ExecuteFactFunction(factFunction);
}

bool ExpertFact::ResearchAvailable(int inConstTechId)
{
	static const FactFunction factFunction = *factFunctionMap.at("research-available");
	return ExecuteFactFunction(factFunction, inConstTechId);
}

bool ExpertFact::ResearchCompleted(int inConstTechId)
{
	static const FactFunction factFunction = *factFunctionMap.at("research-completed");
	return ExecuteFactFunction(factFunction, inConstTechId);
}

bool ExpertFact::ResourceFound(int inConstResource)
{
	static const FactFunction factFunction = *factFunctionMap.at("resource-found");
	return ExecuteFactFunction(factFunction, inConstResource);
}

bool ExpertFact::SharedGoal(int inConstSharedGoalId, int inConstValue)
{
	static const FactFunction factFunction = *factFunctionMap.at("shared-goal");
	return ExecuteFactFunction(factFunction, inConstSharedGoalId, inConstValue);
}

bool ExpertFact::SheepAndForageTooFar()
{
	static const FactFunction factFunction = *factFunctionMap.at("sheep-and-forage-too-far");
	return ExecuteFactFunction(factFunction);
}

int ExpertFact::SoldierCount()
{
	return ExpertFact::UpGetFact(13, 0);
}

bool ExpertFact::StanceToward(int inPlayerAnyPlayer, int inConstESPlayerStance)
{
	static const FactFunction factFunction = *factFunctionMap.at("stance-toward");
	return ExecuteFactFunction(factFunction, inPlayerAnyPlayer, inConstESPlayerStance);
}

int ExpertFact::StartingAge()
{
#if defined GAME_DE
	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("starting-age");
	ExecuteFactFunction(factFunction, 0, 0);
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
	static const FactFunction factFunction = *factFunctionMap.at("starting-resources");
	ExecuteFactFunction(factFunction, 0, 0);
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
	static const FactFunction factFunction = *factFunctionMap.at("strategic-number");
	ExecuteFactFunction(factFunction, inConstSnId, 0, 0);
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
	static const FactFunction factFunction = *factFunctionMap.at("taunt-detected");
	return ExecuteFactFunction(factFunction, inPlayerAnyPlayer, inConstTauntId);
}

bool ExpertFact::TimerTriggered(int inConstTimerId)
{
	static const FactFunction factFunction = *factFunctionMap.at("timer-triggered");
	return ExecuteFactFunction(factFunction, inConstTimerId);
}

bool ExpertFact::TownUnderAttack()
{
	static const FactFunction factFunction = *factFunctionMap.at("town-under-attack");
	return ExecuteFactFunction(factFunction);
}

bool ExpertFact::TraceFact(int param)
{
	static const FactFunction factFunction = *factFunctionMap.at("trace-fact");
	return ExecuteFactFunction(factFunction, param);
}

bool ExpertFact::True()
{
	static const FactFunction factFunction = *factFunctionMap.at("true");
	return ExecuteFactFunction(factFunction);
}

bool ExpertFact::UnitAvailable(int inConstUnitId)
{
	static const FactFunction factFunction = *factFunctionMap.at("unit-available");
	return ExecuteFactFunction(factFunction, inConstUnitId);
}

int ExpertFact::UnitCount()
{
	return ExpertFact::UpGetFact(23, 0);
}

int ExpertFact::UnitCountTotal()
{
#if defined GAME_DE
	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("unit-count-total");
	ExecuteFactFunction(factFunction, 0, 0);
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
	static const FactFunction factFunction = *factFunctionMap.at("up-allied-goal");
	ExecuteFactFunction(factFunction, inPlayerComputerAllyPlayer, inGoalId, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpAlliedResourceAmount(int inPlayerAllyPlayer, int inConstResourceAmount)
{
	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("up-allied-resource-amount");
	ExecuteFactFunction(factFunction, inPlayerAllyPlayer, inConstResourceAmount, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpAlliedResourcePercent(int inPlayerAllyPlayer, int inConstResourceAmount)
{
	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("up-allied-resource-percent");
	ExecuteFactFunction(factFunction, inPlayerAllyPlayer, inConstResourceAmount, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpAlliedSn(int inPlayerComputerAllyPlayer, int inSnId)
{
	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("up-allied-sn");
	ExecuteFactFunction(factFunction, inPlayerComputerAllyPlayer, inSnId, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpAttackerClass()
{
	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("up-attacker-class");
	ExecuteFactFunction(factFunction, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpBuildingTypeInTown(int typeOp, int inOpBuildingId)
{
#if defined GAME_AOC
	ChangeTypeOpToConst(typeOp, inOpBuildingId);
#endif

	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("up-building-type-in-town");
	ExecuteFactFunction(factFunction, typeOp, inOpBuildingId, 0, 0);
	return lastRelOpValue;
}

bool ExpertFact::UpCanBuild(int inGoalEscrowState, int typeOp, int inOpBuildingId)
{
#if defined GAME_AOC
	ChangeTypeOpToConst(typeOp, inOpBuildingId);
#endif

	static const FactFunction factFunction = *factFunctionMap.at("up-can-build");
	return ExecuteFactFunction(factFunction, inGoalEscrowState, typeOp, inOpBuildingId);
}

bool ExpertFact::UpCanBuildLine(int inGoalEscrowState, int inGoalPoint, int typeOp, int inOpBuildingId)
{
#if defined GAME_AOC
	ChangeTypeOpToConst(typeOp, inOpBuildingId);
#endif

	static const FactFunction factFunction = *factFunctionMap.at("up-can-build-line");
	return ExecuteFactFunction(factFunction, inGoalEscrowState, inGoalPoint, typeOp, inOpBuildingId);
}

bool ExpertFact::UpCanResearch(int inGoalEscrowState, int typeOp, int inOpTechId)
{
#if defined GAME_AOC
	ChangeTypeOpToConst(typeOp, inOpTechId);
#endif

	static const FactFunction factFunction = *factFunctionMap.at("up-can-research");
	return ExecuteFactFunction(factFunction, inGoalEscrowState, typeOp, inOpTechId);
}

bool ExpertFact::UpCanSearch(int inConstSearchSource)
{
	static const FactFunction factFunction = *factFunctionMap.at("up-can-search");
	return ExecuteFactFunction(factFunction, inConstSearchSource);
}

bool ExpertFact::UpCanTrain(int inGoalEscrowState, int typeOp, int inOpUnitId)
{
#if defined GAME_AOC
	ChangeTypeOpToConst(typeOp, inOpUnitId);
#endif

	static const FactFunction factFunction = *factFunctionMap.at("up-can-train");
	return ExecuteFactFunction(factFunction, inGoalEscrowState, typeOp, inOpUnitId);
}

int ExpertFact::UpDefenderCount()
{
	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("up-defender-count");
	ExecuteFactFunction(factFunction, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpEnemyBuildingsInTown()
{
	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("up-enemy-buildings-in-town");
	ExecuteFactFunction(factFunction, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpEnemyUnitsInTown()
{
	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("up-enemy-units-in-town");
	ExecuteFactFunction(factFunction, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpEnemyVillagersInTown()
{
	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("up-enemy-villagers-in-town");
	ExecuteFactFunction(factFunction, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpGaiaTypeCount(int inConstResource)
{
	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("up-gaia-type-count");
	ExecuteFactFunction(factFunction, 0, inConstResource, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpGaiaTypeCountTotal(int inConstResource)
{
	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("up-gaia-type-count-total");
	ExecuteFactFunction(factFunction, 0, inConstResource, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpGetFact(int inConstFactId, int inConstParam)
{
	// Cache goal, read new fact into goal
	int cachedGoal = ExpertFact::Goal(expert_conf::CONST_TEMP_GOAL_ID);
	ExpertAction::UpGetFact(inConstFactId, inConstParam, expert_conf::CONST_TEMP_GOAL_ID);
	int result = ExpertFact::Goal(expert_conf::CONST_TEMP_GOAL_ID);

	// Restore goal and return result
	ExpertAction::SetGoal(expert_conf::CONST_TEMP_GOAL_ID, cachedGoal);
	return result;
}

int ExpertFact::UpGetPlayerFact(int inPlayerAnyPlayer, int inConstFactId, int inConstParam)
{
	// Cache goal, read new fact into goal
	int cachedGoal = ExpertFact::Goal(expert_conf::CONST_TEMP_GOAL_ID);
	ExpertAction::UpGetPlayerFact(inPlayerAnyPlayer, inConstFactId, inConstParam, expert_conf::CONST_TEMP_GOAL_ID);
	int result = ExpertFact::Goal(expert_conf::CONST_TEMP_GOAL_ID);

	// Restore goal and return result
	ExpertAction::SetGoal(expert_conf::CONST_TEMP_GOAL_ID, cachedGoal);
	return result;
}

std::array<int, 4> ExpertFact::UpGetSearchState()
{
	std::array<int, 4> result;

	// cache 4 goals that will be overwritten
	int cachedGoals[4];
	for (int i = 0; i < 4; i++) cachedGoals[i] = ExpertFact::Goal(expert_conf::CONST_TEMP_GOAL_ID + i);

	// get search state into these 4 goals and populate the result
	ExpertAction::UpGetSearchState(expert_conf::CONST_TEMP_GOAL_ID);
	for (int i = 0; i < 4; i++) result[i] = ExpertFact::Goal(expert_conf::CONST_TEMP_GOAL_ID + i);

	// restore cached goals and return the result
	for (int i = 0; i < 4; i++) ExpertAction::SetGoal(expert_conf::CONST_TEMP_GOAL_ID + i, cachedGoals[i]);
	return result;
}

int ExpertFact::UpGroupSize(int typeOp, int inOpGroupId)
{
#if defined GAME_AOC
	ChangeTypeOpToConst(typeOp, inOpGroupId);
#endif

	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("up-group-size");
	ExecuteFactFunction(factFunction, typeOp, inOpGroupId, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpIdleUnitCount(int inConstIdleType)
{
	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("up-idle-unit-count");
	ExecuteFactFunction(factFunction, inConstIdleType, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpObjectData(int inConstObjectData)
{
	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("up-object-data");
	ExecuteFactFunction(factFunction, inConstObjectData, 0, 0);
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
	static const FactFunction factFunction = *factFunctionMap.at("up-object-target-data");
	ExecuteFactFunction(factFunction, inConstObjectData, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpObjectTypeCount(int typeOp, int inOpObjectId)
{
#if defined GAME_AOC
	ChangeTypeOpToConst(typeOp, inOpObjectId);
#endif

	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("up-object-type-count");
	ExecuteFactFunction(factFunction, typeOp, inOpObjectId, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpObjectTypeCountTotal(int typeOp, int inOpObjectId)
{
#if defined GAME_AOC
	ChangeTypeOpToConst(typeOp, inOpObjectId);
#endif

	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("up-object-type-count-total");
	ExecuteFactFunction(factFunction, typeOp, inOpObjectId, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpPathDistance(int inGoalPoint, int inConstStrict)
{
	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("up-path-distance");
	ExecuteFactFunction(factFunction, inGoalPoint, inConstStrict, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpPendingObjects(int typeOp, int inOpObjectId)
{
#if defined GAME_AOC
	ChangeTypeOpToConst(typeOp, inOpObjectId);
#endif

	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("up-pending-objects");
	ExecuteFactFunction(factFunction, typeOp, inOpObjectId, 0, 0);
	return lastRelOpValue;
}

bool ExpertFact::UpPendingPlacement(int typeOp, int inOpBuildingId)
{
#if defined GAME_AOC
	ChangeTypeOpToConst(typeOp, inOpBuildingId);
#endif

	static const FactFunction factFunction = *factFunctionMap.at("up-pending-placement");
	return ExecuteFactFunction(factFunction, typeOp, inOpBuildingId);
}

int ExpertFact::UpPlayerDistance(int inPlayerAnyPlayer)
{
	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("up-player-distance");
	ExecuteFactFunction(factFunction, inPlayerAnyPlayer, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpPlayersInGame(int inConstPlayerStance)
{
	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("up-players-in-game");
	ExecuteFactFunction(factFunction, inConstPlayerStance, 0, 0);
	return lastRelOpValue;
}

bool ExpertFact::UpPointContains(int inGoalPoint, int typeOp, int inOpObjectId)
{
#if defined GAME_AOC
	ChangeTypeOpToConst(typeOp, inOpObjectId);
#endif

	static const FactFunction factFunction = *factFunctionMap.at("up-point-contains");
	return ExecuteFactFunction(factFunction, inGoalPoint, typeOp, inOpObjectId);
}

int ExpertFact::UpPointDistance(int inGoalPoint1, int inGoalPoint2)
{
	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("up-point-distance");
	ExecuteFactFunction(factFunction, inGoalPoint1, inGoalPoint2, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpPointElevation(int inGoalPoint)
{
	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("up-point-elevation");
	ExecuteFactFunction(factFunction, inGoalPoint, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpPointExplored(int inGoalPoint)
{
	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("up-point-explored");
	ExecuteFactFunction(factFunction, inGoalPoint, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpPointTerrain(int inGoalPoint)
{
	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("up-point-terrain");
	ExecuteFactFunction(factFunction, inGoalPoint, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpPointZone(int inGoalPoint)
{
	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("up-point-zone");
	ExecuteFactFunction(factFunction, inGoalPoint, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpProjectileDetected(int inConstProjectileType)
{
	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("up-projectile-detected");
	ExecuteFactFunction(factFunction, inConstProjectileType, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpProjectileTarget(int inConstProjectileType)
{
	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("up-projectile-target");
	ExecuteFactFunction(factFunction, inConstProjectileType, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpRemainingBoarAmount()
{
	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("up-remaining-boar-amount");
	ExecuteFactFunction(factFunction, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpResearchStatus(int typeOp, int inOpTechId)
{
#if defined GAME_AOC
	ChangeTypeOpToConst(typeOp, inOpTechId);
#endif

	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("up-research-status");
	ExecuteFactFunction(factFunction, typeOp, inOpTechId, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpResourceAmount(int inConstResourceAmount)
{
	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("up-resource-amount");
	ExecuteFactFunction(factFunction, inConstResourceAmount, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpResourcePercent(int inConstResourceAmount)
{
	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("up-resource-percent");
	ExecuteFactFunction(factFunction, inConstResourceAmount, 0, 0);
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
	static const FactFunction factFunction = *factFunctionMap.at("up-timer-status");
	ExecuteFactFunction(factFunction, inConstTimerId, 0, 0);
	return lastRelOpValue;
}

bool ExpertFact::UpTrainSiteReady(int typeOp, int inOpUnitId)
{
#if defined GAME_AOC
	ChangeTypeOpToConst(typeOp, inOpUnitId);
#endif

	static const FactFunction factFunction = *factFunctionMap.at("up-train-site-ready");
	return ExecuteFactFunction(factFunction, typeOp, inOpUnitId);
}

int ExpertFact::UpUnitTypeInTown(int typeOp, int inOpUnitId)
{
#if defined GAME_AOC
	ChangeTypeOpToConst(typeOp, inOpUnitId);
#endif

	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("up-unit-type-in-town");
	ExecuteFactFunction(factFunction, typeOp, inOpUnitId, 0, 0);
	return lastRelOpValue;
}

int ExpertFact::UpVillagerTypeInTown(int typeOp, int inOpUnitId)
{
#if defined GAME_AOC
	ChangeTypeOpToConst(typeOp, inOpUnitId);
#endif

	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("up-villager-type-in-town");
	ExecuteFactFunction(factFunction, typeOp, inOpUnitId, 0, 0);
	return lastRelOpValue;
}

bool ExpertFact::VictoryCondition(int inConstVictory)
{
	static const FactFunction factFunction = *factFunctionMap.at("victory-condition");
	return ExecuteFactFunction(factFunction, inConstVictory);
}

int ExpertFact::WallCompletedPercentage(int inConstPerimeter)
{
#if defined GAME_DE
	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("wall-completed-percentage");
	ExecuteFactFunction(factFunction, inConstPerimeter, 0, 0);
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
	static const FactFunction factFunction = *factFunctionMap.at("wall-invisible-percentage");
	ExecuteFactFunction(factFunction, inConstPerimeter, 0, 0);
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

int ExpertFact::EndingAge()
{
	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("ending-age");
	ExecuteFactFunction(factFunction, 0, 0);
	return lastRelOpValue;
}

bool ExpertFact::FeCanBuildAtPoint(int param1, int param2, int param3, int param4)
{
	static const FactFunction factFunction = *factFunctionMap.at("fe-can-build-at-point");
	return ExecuteFactFunction(factFunction, param1, param2, param3, param4);
}

int ExpertFact::FeSubGameType()
{
	lastRelOpValue = -1;
	static const FactFunction factFunction = *factFunctionMap.at("fe-sub-game-type");
	ExecuteFactFunction(factFunction, 0, 0);
	return lastRelOpValue;
}

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

std::array<int, 2> ExpertFact::ModMapDimensions()
{
	std::array<int, 2> result;
	
	// cache goals
	int cachedGoals[2];
	for (int i = 0; i < 2; i++) cachedGoals[i] = ExpertFact::Goal(expert_conf::CONST_TEMP_GOAL_ID + i);

	// set a goal pair to a coordinate out of map, bound it, add 1 to max x and y to get map dimensions
	ExpertAction::SetGoal(expert_conf::CONST_TEMP_GOAL_ID, 999);
	ExpertAction::SetGoal(expert_conf::CONST_TEMP_GOAL_ID + 1, 999);
	ExpertAction::UpBoundPoint(expert_conf::CONST_TEMP_GOAL_ID, expert_conf::CONST_TEMP_GOAL_ID);
	for (int i = 0; i < 2; i++) result[i] = ExpertFact::Goal(expert_conf::CONST_TEMP_GOAL_ID + i) + 1;

	// restore goals
	for (int i = 0; i < 2; i++) ExpertAction::SetGoal(expert_conf::CONST_TEMP_GOAL_ID + i, cachedGoals[i]);
	return result;
}
