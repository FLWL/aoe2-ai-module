#include "ExpertAction.h"

#include <iostream>
#include <chrono>

#include <Windows.h>
#include <detours/detours.h>

#include "misc/Statics.h"
#include "misc/MemoryUtils.h"
#include "expert/fact/ExpertFact.h"

ExpertAction::~ExpertAction()
{
	DisableDetours();
	ClearActionFunctions();
}

void ExpertAction::Initialize(const structs::AIExpert* aiExpert)
{
	LoadActionFunctions(aiExpert);
	UpdateAddresses();
	EnableDetours();
}

void ExpertAction::LoadActionFunctions(const structs::AIExpert* aiExpert)
{
#if defined GAME_DE
	for (int actionId = 0; actionId < aiExpert->numActions; actionId++)
	{
		ActionFunction* actionFunction = new ActionFunction{ (uintptr_t)aiExpert->action[actionId].actionFn, aiExpert->action[actionId].argc };
		actionFunctionMap.insert({ std::string(aiExpert->actionNames[actionId]), actionFunction });
	}
#elif defined GAME_AOC
	for (int tableIndex = 0; tableIndex < aiExpert->globalSymbolTableSize; tableIndex++)
	{
		structs::SymbolHashNode* node = aiExpert->bucket[tableIndex];

		while (node)
		{
			if (node->type == 0)
			{
				ActionFunction* actionFunction = new ActionFunction{ (uintptr_t) aiExpert->action[node->id].actionFn, aiExpert->action[node->id].argc };
				actionFunctionMap.insert({ std::string(node->symbolText), actionFunction });
			}

			node = node->next;
		}
	}
#endif

	std::cout << "[Expert] Loaded " << actionFunctionMap.size() << " action functions." << std::endl;
}

void ExpertAction::ClearActionFunctions()
{
	for (auto& element : actionFunctionMap)
		delete element.second;

	actionFunctionMap.clear();
}

void ExpertAction::UpdateAddresses()
{
#if defined GAME_DE
	try
	{
		uintptr_t callInstructionToGetStringAddress = actionFunctionMap.at("up-change-name")->address + 29;
		std::vector<uint8_t> callInstructionToGetStringData = memory_utils::ReadMemory(callInstructionToGetStringAddress, 5);
		statics::SetFuncAddr(FuncGetString, memory_utils::GetInstructionImmMemOperand(callInstructionToGetStringAddress, callInstructionToGetStringData));
	}
	catch (const std::exception&) { }
#elif defined GAME_AOC
	statics::SetFuncAddr(FuncGetString, statics::TranslateAddr(expert_conf::ADDR_FUNC_GET_STRING));
#endif
}

void ExpertAction::EnableDetours()
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)FuncGetString, DetouredGetString);
	LONG transactionResult = DetourTransactionCommit();

	if (transactionResult != NO_ERROR)
	{
		std::cout << "[Expert] Error: failed to detour function 'GetString'."
			<< " Error code " << transactionResult
			<< ", game module base address 0x" << std::hex << statics::GetGameModuleBaseAddr() << std::dec
			<< ", function address 0x" << std::hex << (uintptr_t) FuncGetString << std::dec
			<< ". Actions with string type parameters will not work." << std::endl;
	}
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

void ExpertAction::ExecuteActionFunction(const ActionFunction& actionFunction, const int arg1, const int arg2, const int arg3, const int arg4)
{
	switch (actionFunction.argc)
	{
		case 0:
		{
			((void(*)(void))actionFunction.address)();
			break;
		}
		case 1:
		{
			((void(*)(int))actionFunction.address)(arg1);
			break;
		}
		case 2:
		{
			((void(*)(int, int))actionFunction.address)(arg1, arg2);
			break;
		}
		case 3:
		{
			((void(*)(int, int, int))actionFunction.address)(arg1, arg2, arg3);
			break;
		}
		case 4:
		{
			((void(*)(int, int, int, int))actionFunction.address)(arg1, arg2, arg3, arg4);
			break;
		}
	}
}

void ExpertAction::AcknowledgeEvent(int inConstEventType, int inConstEventId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("acknowledge-event");
	ExecuteActionFunction(actionFunction, inConstEventType, inConstEventId);
}

void ExpertAction::AcknowledgeTaunt(int inPlayerAnyPlayer, int inConstTauntId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("acknowledge-taunt");
	ExecuteActionFunction(actionFunction, inPlayerAnyPlayer, inConstTauntId);
}

void ExpertAction::AttackNow()
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("attack-now");
	ExecuteActionFunction(actionFunction);
}

void ExpertAction::Build(int inConstBuildingId)
{
	if (ExpertFact::CanBuildWithEscrow(inConstBuildingId))
	{
		static const ActionFunction actionFunction = *actionFunctionMap.at("build");
		ExecuteActionFunction(actionFunction, inConstBuildingId);
	}
}

void ExpertAction::BuildForward(int inConstBuildingId)
{
	if (ExpertFact::CanBuildWithEscrow(inConstBuildingId))
	{
		static const ActionFunction actionFunction = *actionFunctionMap.at("build-forward");
		ExecuteActionFunction(actionFunction, inConstBuildingId);
	}
}

void ExpertAction::BuildGate(int inConstPerimeter)
{
	if (ExpertFact::CanBuildGateWithEscrow(inConstPerimeter))
	{
		static const ActionFunction actionFunction = *actionFunctionMap.at("build-gate");
		ExecuteActionFunction(actionFunction, inConstPerimeter);
	}
}

void ExpertAction::BuildWall(int inConstPerimeter, int inConstWallId)
{
	if (ExpertFact::CanBuildWallWithEscrow(inConstPerimeter, inConstWallId))
	{
		static const ActionFunction actionFunction = *actionFunctionMap.at("build-wall");
		ExecuteActionFunction(actionFunction, inConstPerimeter, inConstWallId);
	}
}

void ExpertAction::BuyCommodity(int inConstCommodity)
{
	if (ExpertFact::CanBuyCommodity(inConstCommodity))
	{
		static const ActionFunction actionFunction = *actionFunctionMap.at("buy-commodity");
		ExecuteActionFunction(actionFunction, inConstCommodity);
	}
}

void ExpertAction::CcAddResource(int inConstResource, int inConstValue)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("cc-add-resource");
	ExecuteActionFunction(actionFunction, inConstResource, inConstValue);
}

void ExpertAction::ChatLocal(const std::string& inTextString)
{
	SetCustomString(inTextString);
	static const ActionFunction actionFunction = *actionFunctionMap.at("chat-local");
	ExecuteActionFunction(actionFunction, expert_conf::CONST_CUSTOM_STRING_ID);
}

void ExpertAction::ChatLocalUsingId(int inConstLanguageId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("chat-local-using-id");
	ExecuteActionFunction(actionFunction, inConstLanguageId);
}

void ExpertAction::ChatLocalUsingRange(int inConstLanguageId, int inConstValue)
{
	if (inConstValue != 0) // crashes otherwise
	{
		static const ActionFunction actionFunction = *actionFunctionMap.at("chat-local-using-range");
		ExecuteActionFunction(actionFunction, inConstLanguageId, inConstValue);
	}
}

void ExpertAction::ChatLocalToSelf(const std::string& inTextString)
{
	SetCustomString(inTextString);
	static const ActionFunction actionFunction = *actionFunctionMap.at("chat-local-to-self");
	ExecuteActionFunction(actionFunction, expert_conf::CONST_CUSTOM_STRING_ID);
}

void ExpertAction::ChatToAll(const std::string& inTextString)
{
	SetCustomString(inTextString);
	static const ActionFunction actionFunction = *actionFunctionMap.at("chat-to-all");
	ExecuteActionFunction(actionFunction, expert_conf::CONST_CUSTOM_STRING_ID);
}

void ExpertAction::ChatToAllUsingId(int inConstLanguageId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("chat-to-all-using-id");
	ExecuteActionFunction(actionFunction, inConstLanguageId);
}

void ExpertAction::ChatToAllUsingRange(int inConstLanguageId, int inConstValue)
{
	if (inConstValue != 0) // crashes otherwise
	{
		static const ActionFunction actionFunction = *actionFunctionMap.at("chat-to-all-using-range");
		ExecuteActionFunction(actionFunction, inConstLanguageId, inConstValue);
	}
}

void ExpertAction::ChatToAllies(const std::string& inTextString)
{
	SetCustomString(inTextString);
	static const ActionFunction actionFunction = *actionFunctionMap.at("chat-to-allies");
	ExecuteActionFunction(actionFunction, expert_conf::CONST_CUSTOM_STRING_ID);
}

void ExpertAction::ChatToAlliesUsingId(int inConstLanguageId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("chat-to-allies-using-id");
	ExecuteActionFunction(actionFunction, inConstLanguageId);
}

void ExpertAction::ChatToAlliesUsingRange(int inConstLanguageId, int inConstValue)
{
	if (inConstValue != 0) // crashes otherwise
	{
		static const ActionFunction actionFunction = *actionFunctionMap.at("chat-to-allies-using-range");
		ExecuteActionFunction(actionFunction, inConstLanguageId, inConstValue);
	}
}

void ExpertAction::ChatToEnemies(const std::string& inTextString)
{
	SetCustomString(inTextString);
	static const ActionFunction actionFunction = *actionFunctionMap.at("chat-to-enemies");
	ExecuteActionFunction(actionFunction, expert_conf::CONST_CUSTOM_STRING_ID);
}

void ExpertAction::ChatToEnemiesUsingId(int inConstLanguageId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("chat-to-enemies-using-id");
	ExecuteActionFunction(actionFunction, inConstLanguageId);
}

void ExpertAction::ChatToEnemiesUsingRange(int inConstLanguageId, int inConstValue)
{
	if (inConstValue != 0) // crashes otherwise
	{
		static const ActionFunction actionFunction = *actionFunctionMap.at("chat-to-enemies-using-range");
		ExecuteActionFunction(actionFunction, inConstLanguageId, inConstValue);
	}
}

void ExpertAction::ChatToPlayer(int inPlayerAnyPlayer, const std::string& inTextString)
{
	SetCustomString(inTextString);
	static const ActionFunction actionFunction = *actionFunctionMap.at("chat-to-player");
	ExecuteActionFunction(actionFunction, inPlayerAnyPlayer, expert_conf::CONST_CUSTOM_STRING_ID);
}

void ExpertAction::ChatToPlayerUsingId(int inPlayerAnyPlayer, int inConstLanguageId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("chat-to-player-using-id");
	ExecuteActionFunction(actionFunction, inPlayerAnyPlayer, inConstLanguageId);
}

void ExpertAction::ChatToPlayerUsingRange(int inPlayerAnyPlayer, int inConstLanguageId, int inConstValue)
{
	if (inConstValue != 0) // crashes otherwise
	{
		static const ActionFunction actionFunction = *actionFunctionMap.at("chat-to-player-using-range");
		ExecuteActionFunction(actionFunction, inPlayerAnyPlayer, inConstLanguageId, inConstValue);
	}
}

void ExpertAction::ChatTrace(int inConstValue)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("chat-trace");
	ExecuteActionFunction(actionFunction, inConstValue);
}

void ExpertAction::ClearTributeMemory(int inPlayerAnyPlayer, int inConstResource)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("clear-tribute-memory");
	ExecuteActionFunction(actionFunction, inPlayerAnyPlayer, inConstResource);
}

void ExpertAction::DeleteBuilding(int inConstBuildingId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("delete-building");
	ExecuteActionFunction(actionFunction, inConstBuildingId);
}

void ExpertAction::DeleteUnit(int inConstUnitId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("delete-unit");
	ExecuteActionFunction(actionFunction, inConstUnitId);
}

void ExpertAction::DisableRule(int inConstRuleGroupId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("disable-rule");
	ExecuteActionFunction(actionFunction, inConstRuleGroupId);
}

void ExpertAction::DisableSelf()
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("disable-self");
	ExecuteActionFunction(actionFunction);
}

void ExpertAction::DisableTimer(int inConstTimerId)
{
	if (inConstTimerId != 0) // can crash otherwise
	{
		static const ActionFunction actionFunction = *actionFunctionMap.at("disable-timer");
		ExecuteActionFunction(actionFunction, inConstTimerId);
	}
}

void ExpertAction::DoNothing()
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("do-nothing");
	ExecuteActionFunction(actionFunction);
}

void ExpertAction::EnableRule(int inConstRuleGroupId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("enable-rule");
	ExecuteActionFunction(actionFunction, inConstRuleGroupId);
}

void ExpertAction::EnableTimer(int inConstTimerId, int inConstValue)
{
#if defined GAME_AOC
	if (inConstValue != 0) // crashes otherwise
#endif
	{
		static const ActionFunction actionFunction = *actionFunctionMap.at("enable-timer");
		ExecuteActionFunction(actionFunction, inConstTimerId, inConstValue);
	}
}

void ExpertAction::EnableWallPlacement(int inConstPerimeter)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("enable-wall-placement");
	ExecuteActionFunction(actionFunction, inConstPerimeter);
}

void ExpertAction::GenerateRandomNumber(int inConstValue)
{
	if (inConstValue != 0) // crashes otherwise
	{
		static const ActionFunction actionFunction = *actionFunctionMap.at("generate-random-number");
		ExecuteActionFunction(actionFunction, inConstValue);
	}
}

void ExpertAction::Log(const std::string& inTextString)
{
	SetCustomString(inTextString);
	static const ActionFunction actionFunction = *actionFunctionMap.at("log");
	ExecuteActionFunction(actionFunction, expert_conf::CONST_CUSTOM_STRING_ID);
}

void ExpertAction::LogTrace(int inConstValue)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("log-trace");
	ExecuteActionFunction(actionFunction, inConstValue);
}

void ExpertAction::ReleaseEscrow(int inConstResource)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("release-escrow");
	ExecuteActionFunction(actionFunction, inConstResource);
}

void ExpertAction::Research(int inConstTechId)
{
	if (ExpertFact::CanResearchWithEscrow(inConstTechId)) // fixes a potential crash, at least in aoc
	{
		static const ActionFunction actionFunction = *actionFunctionMap.at("research");
		ExecuteActionFunction(actionFunction, inConstTechId);
	}
}

void ExpertAction::Resign()
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("resign");
	ExecuteActionFunction(actionFunction);
}

void ExpertAction::SellCommodity(int inConstCommodity)
{
	if (ExpertFact::CanSellCommodity(inConstCommodity))
	{
		static const ActionFunction actionFunction = *actionFunctionMap.at("sell-commodity");
		ExecuteActionFunction(actionFunction, inConstCommodity);
	}
}

void ExpertAction::SetAuthorName(const std::string& inTextString)
{
	// not actually implemented by the game
	SetCustomString(inTextString);
	static const ActionFunction actionFunction = *actionFunctionMap.at("set-author-name");
	ExecuteActionFunction(actionFunction, expert_conf::CONST_CUSTOM_STRING_ID);
}

void ExpertAction::SetAuthorEmail(const std::string& inTextString)
{
	// not actually implemented by the game
	SetCustomString(inTextString);
	static const ActionFunction actionFunction = *actionFunctionMap.at("set-author-email");
	ExecuteActionFunction(actionFunction, expert_conf::CONST_CUSTOM_STRING_ID);
}

void ExpertAction::SetAuthorVersion(const std::string& inTextString)
{
	// not actually implemented by the game
	SetCustomString(inTextString);
	static const ActionFunction actionFunction = *actionFunctionMap.at("set-author-version");
	ExecuteActionFunction(actionFunction, expert_conf::CONST_CUSTOM_STRING_ID);
}

void ExpertAction::SetDifficultyParameter(int inConstDiffParameterId, int inConstValue)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("set-difficulty-parameter");
	ExecuteActionFunction(actionFunction, inConstDiffParameterId, inConstValue);
}

void ExpertAction::SetDoctrine(int inConstValue)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("set-doctrine");
	ExecuteActionFunction(actionFunction, inConstValue);
}

void ExpertAction::SetEscrowPercentage(int inConstResource, int inConstValue)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("set-escrow-percentage");
	ExecuteActionFunction(actionFunction, inConstResource, inConstValue);
}

void ExpertAction::SetGoal(int inConstGoalId, int inConstValue)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("set-goal");
	ExecuteActionFunction(actionFunction, inConstGoalId, inConstValue);
}

void ExpertAction::SetSharedGoal(int inConstGoalId, int inConstValue)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("set-shared-goal");
	ExecuteActionFunction(actionFunction, inConstGoalId, inConstValue);
}

void ExpertAction::SetSignal(int inConstSignalId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("set-signal");
	ExecuteActionFunction(actionFunction, inConstSignalId);
}

void ExpertAction::SetStance(int inPlayerAnyPlayer, int inConstESPlayerStance)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("set-stance");
	ExecuteActionFunction(actionFunction, inPlayerAnyPlayer, inConstESPlayerStance);
}

void ExpertAction::SetStrategicNumber(int inConstSnId, int inConstValue)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("set-strategic-number");
	ExecuteActionFunction(actionFunction, inConstSnId, inConstValue);
}

void ExpertAction::Spy()
{
	if (ExpertFact::CanSpyWithEscrow())
	{
		static const ActionFunction actionFunction = *actionFunctionMap.at("spy");
		ExecuteActionFunction(actionFunction);
	}
}

void ExpertAction::Taunt(int inConstTauntId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("taunt");
	ExecuteActionFunction(actionFunction, inConstTauntId);
}

void ExpertAction::TauntUsingRange(int inConstTauntId, int inConstValue)
{
	if (inConstValue != 0) // crashes otherwise
	{
		static const ActionFunction actionFunction = *actionFunctionMap.at("taunt-using-range");
		ExecuteActionFunction(actionFunction, inConstTauntId, inConstValue);
	}
}

void ExpertAction::Train(int inConstUnitId)
{
	if (ExpertFact::CanTrainWithEscrow(inConstUnitId))
	{
		static const ActionFunction actionFunction = *actionFunctionMap.at("train");
		ExecuteActionFunction(actionFunction, inConstUnitId);
	}
}

void ExpertAction::TributeToPlayer(int inPlayerAnyPlayer, int inConstResource, int inConstValue)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("tribute-to-player");
	ExecuteActionFunction(actionFunction, inPlayerAnyPlayer, inConstResource, inConstValue);
}

void ExpertAction::UpAddCostData(int inGoalId, int typeOp, int inOpValue)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-add-cost-data");
	ExecuteActionFunction(actionFunction, inGoalId, typeOp, inOpValue);
}

void ExpertAction::UpAddObjectById(int inConstSearchSource, int typeOp, int inOpId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-add-object-by-id");
	ExecuteActionFunction(actionFunction, inConstSearchSource, typeOp, inOpId);
}

void ExpertAction::UpAddObjectCost(int typeOp1, int inOp1ObjectId, int typeOp2, int inOp2Value)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-add-object-cost");
	ExecuteActionFunction(actionFunction, typeOp1, inOp1ObjectId, typeOp2, inOp2Value);
}

void ExpertAction::UpAddPoint(int inGoalPoint1, int inGoalPoint2, int typeOp, int inOpCount)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-add-point");
	ExecuteActionFunction(actionFunction, inGoalPoint1, inGoalPoint2, typeOp, inOpCount);
}

void ExpertAction::UpAddResearchCost(int typeOp1, int inOp1TechId, int typeOp2, int inOp2Value)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-add-research-cost");
	ExecuteActionFunction(actionFunction, typeOp1, inOp1TechId, typeOp2, inOp2Value);
}

void ExpertAction::UpAssignBuilders(int typeOp1, int inOp1BuildingId, int typeOp2, int inOp2Value)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-assign-builders");
	ExecuteActionFunction(actionFunction, typeOp1, inOp1BuildingId, typeOp2, inOp2Value);
}

void ExpertAction::UpBoundPoint(int outGoalPoint, int inGoalPoint)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-bound-point");
	ExecuteActionFunction(actionFunction, outGoalPoint, inGoalPoint);
}

void ExpertAction::UpBoundPrecisePoint(int inGoalPoint, int inConstPrecise, int typeOp, int inOpBorder)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-bound-precise-point");
	ExecuteActionFunction(actionFunction, inGoalPoint, inConstPrecise, typeOp, inOpBorder);
}

void ExpertAction::UpBuild(int inConstPlacementType, int inGoalEscrowState, int typeOp, int inOpBuildingId)
{
	if (ExpertFact::UpCanBuild(inGoalEscrowState, typeOp, inOpBuildingId))
	{
		static const ActionFunction actionFunction = *actionFunctionMap.at("up-build");
		ExecuteActionFunction(actionFunction, inConstPlacementType, inGoalEscrowState, typeOp, inOpBuildingId);
	}
}

void ExpertAction::UpBuildLine(int inGoalPoint1, int inGoalPoint2, int typeOp, int inOpBuildingId)
{
	int cachedGoal = ExpertFact::Goal(expert_conf::CONST_TEMP_GOAL_ID);
	ExpertAction::SetGoal(expert_conf::CONST_TEMP_GOAL_ID, 0); // with-escrow

	if (ExpertFact::UpCanBuildLine(expert_conf::CONST_TEMP_GOAL_ID, inGoalPoint1, typeOp, inOpBuildingId))
	{
		ExpertAction::SetGoal(expert_conf::CONST_TEMP_GOAL_ID, cachedGoal);
		static const ActionFunction actionFunction = *actionFunctionMap.at("up-build-line");
		ExecuteActionFunction(actionFunction, inGoalPoint1, inGoalPoint2, typeOp, inOpBuildingId);
		return;
	}

	ExpertAction::SetGoal(expert_conf::CONST_TEMP_GOAL_ID, cachedGoal);
}

void ExpertAction::UpBuyCommodity(int typeOp1, int inOp1ResourceAmount, int typeOp2, int inOp2Value)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-buy-commodity");
	ExecuteActionFunction(actionFunction, typeOp1, inOp1ResourceAmount, typeOp2, inOp2Value);
}

void ExpertAction::UpCcAddResource(int typeOp1, int inOp1ResourceAmount, int typeOp2, int inOp2Value)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-cc-add-resource");
	ExecuteActionFunction(actionFunction, typeOp1, inOp1ResourceAmount, typeOp2, inOp2Value);
}

void ExpertAction::UpCcSendCheat(const std::string& inTextCode)
{
	SetCustomString(inTextCode);
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-cc-send-cheat");
	ExecuteActionFunction(actionFunction, expert_conf::CONST_CUSTOM_STRING_ID);
}

void ExpertAction::UpChangeName(const std::string& inTextNewName)
{
	SetCustomString(inTextNewName);
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-change-name");
	ExecuteActionFunction(actionFunction, expert_conf::CONST_CUSTOM_STRING_ID);
}

void ExpertAction::UpChatDataToAll(const std::string& inTextFormattedString, int typeOp, int inOpValue)
{
	SetCustomString(inTextFormattedString);
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-chat-data-to-all");
	ExecuteActionFunction(actionFunction, expert_conf::CONST_CUSTOM_STRING_ID, typeOp, inOpValue);
}

void ExpertAction::UpChatDataToPlayer(int inPlayerAnyPlayer, const std::string& inTextFormattedString, int typeOp, int inOpValue)
{
	SetCustomString(inTextFormattedString);
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-chat-data-to-player");
	ExecuteActionFunction(actionFunction, inPlayerAnyPlayer, expert_conf::CONST_CUSTOM_STRING_ID, typeOp, inOpValue);
}

void ExpertAction::UpChatDataToSelf(const std::string& inTextFormattedString, int typeOp, int inOpValue)
{
	SetCustomString(inTextFormattedString);
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-chat-data-to-self");
	ExecuteActionFunction(actionFunction, expert_conf::CONST_CUSTOM_STRING_ID, typeOp, inOpValue);
}

void ExpertAction::UpCleanSearch(int inConstSearchSource, int inConstObjectData, int inConstSearchOrder)
{
#if defined GAME_DE
	if (inConstSearchSource != 0) // crashes otherwise
#endif
	{
		static const ActionFunction actionFunction = *actionFunctionMap.at("up-clean-search");
		ExecuteActionFunction(actionFunction, inConstSearchSource, inConstObjectData, inConstSearchOrder);
	}
}

void ExpertAction::UpCopyPoint(int outGoalPoint, int inGoalPoint)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-copy-point");
	ExecuteActionFunction(actionFunction, outGoalPoint, inGoalPoint);
}

void ExpertAction::UpCreateGroup(int inGoalIndex, int inGoalCount, int typeOp, int inOpGroupId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-create-group");
	ExecuteActionFunction(actionFunction, inGoalIndex, inGoalCount, typeOp, inOpGroupId);
}

void ExpertAction::UpCrossTiles(int ioGoalPoint, int inGoalPoint, int typeOp, int inOpTiles)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-cross-tiles");
	ExecuteActionFunction(actionFunction, ioGoalPoint, inGoalPoint, typeOp, inOpTiles);
}

void ExpertAction::UpDeleteDistantFarms(int typeOp, int inOpValue)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-delete-distant-farms");
	ExecuteActionFunction(actionFunction, typeOp, inOpValue);
}

void ExpertAction::UpDeleteIdleUnits(int inConstIdleType)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-delete-idle-units");
	ExecuteActionFunction(actionFunction, inConstIdleType);
}

void ExpertAction::UpDeleteObjects(int typeOp1, int inOpUnitId, int typeOp2, int inOpHitPoints)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-delete-objects");
	ExecuteActionFunction(actionFunction, typeOp1, inOpUnitId, typeOp2, inOpHitPoints);
}

void ExpertAction::UpDisbandGroupType(int inConstGroupType)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-disband-group-type");
	ExecuteActionFunction(actionFunction, inConstGroupType);
}

void ExpertAction::UpDropResources(int inConstResource, int typeOp, int inOpValue)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-drop-resources");
	ExecuteActionFunction(actionFunction, inConstResource, typeOp, inOpValue);
}

void ExpertAction::UpFilterDistance(int typeOp1, int inOp1MinDistance, int typeOp2, int inOp2MaxDistance)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-filter-distance");
	ExecuteActionFunction(actionFunction, typeOp1, inOp1MinDistance, typeOp2, inOp2MaxDistance);
}

void ExpertAction::UpFilterExclude(int inConstCmdId, int inConstActionId, int inConstOrderId, int inConstClassId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-filter-exclude");
	ExecuteActionFunction(actionFunction, inConstCmdId, inConstActionId, inConstOrderId, inConstClassId);
}

void ExpertAction::UpFilterGarrison(int typeOp1, int inOp1MinGarrison, int typeOp2, int inOp2MaxGarrison)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-filter-garrison");
	ExecuteActionFunction(actionFunction, typeOp1, inOp1MinGarrison, typeOp2, inOp2MaxGarrison);
}

void ExpertAction::UpFilterInclude(int inConstCmdId, int inConstActionId, int inConstOrderId, int inConstOnMainland)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-filter-include");
	ExecuteActionFunction(actionFunction, inConstCmdId, inConstActionId, inConstOrderId, inConstOnMainland);
}

void ExpertAction::UpFilterRange(int inConstMinGarrison, int inConstMaxGarrison, int inConstMinDistance, int inConstMaxDistance)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-filter-range");
	ExecuteActionFunction(actionFunction, inConstMinGarrison, inConstMaxGarrison, inConstMinDistance, inConstMaxDistance);
}

void ExpertAction::UpFilterStatus(int typeOp1, int inOp1ObjectStatus, int typeOp2, int inOp2ObjectList)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-filter-status");
	ExecuteActionFunction(actionFunction, typeOp1, inOp1ObjectStatus, typeOp2, inOp2ObjectList);
}

void ExpertAction::UpFindFlare(int outGoalPoint)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-find-flare");
	ExecuteActionFunction(actionFunction, outGoalPoint);
}

void ExpertAction::UpFindLocal(int typeOp1, int inOp1UnitId, int typeOp2, int inOp2Count)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-find-local");
	ExecuteActionFunction(actionFunction, typeOp1, inOp1UnitId, typeOp2, inOp2Count);
}

void ExpertAction::UpFindNextPlayer(int inConstPlayerStance, int inConstFindPlayerMethod, int ioGoalPlayerId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-find-next-player");
	ExecuteActionFunction(actionFunction, inConstPlayerStance, inConstFindPlayerMethod, ioGoalPlayerId);
}

void ExpertAction::UpFindPlayer(int inConstPlayerStance, int inConstFindPlayerMethod, int outGoalPlayerId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-find-player");
	ExecuteActionFunction(actionFunction, inConstPlayerStance, inConstFindPlayerMethod, outGoalPlayerId);
}

void ExpertAction::UpFindPlayerFlare(int inPlayerAnyPlayer, int outGoalPoint)
{
#if defined GAME_AOC
	if (outGoalPoint >= 40 && outGoalPoint <= 510) // crashes otherwise
#endif
	{
		static const ActionFunction actionFunction = *actionFunctionMap.at("up-find-player-flare");
		ExecuteActionFunction(actionFunction, inPlayerAnyPlayer, outGoalPoint);
	}
}

void ExpertAction::UpFindRemote(int typeOp1, int inOp1UnitId, int typeOp2, int inOp2Count)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-find-remote");
	ExecuteActionFunction(actionFunction, typeOp1, inOp1UnitId, typeOp2, inOp2Count);
}

void ExpertAction::UpFindResource(int typeOp1, int inOp1Resource, int typeOp2, int inOp2Count)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-find-resource");
	ExecuteActionFunction(actionFunction, typeOp1, inOp1Resource, typeOp2, inOp2Count);
}

void ExpertAction::UpFindStatusLocal(int typeOp1, int inOp1UnitId, int typeOp2, int inOp2Count)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-find-status-local");
	ExecuteActionFunction(actionFunction, typeOp1, inOp1UnitId, typeOp2, inOp2Count);
}

void ExpertAction::UpFindStatusRemote(int typeOp1, int inOp1UnitId, int typeOp2, int inOp2Count)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-find-status-remote");
	ExecuteActionFunction(actionFunction, typeOp1, inOp1UnitId, typeOp2, inOp2Count);
}

void ExpertAction::UpFullResetSearch()
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-full-reset-search");
	ExecuteActionFunction(actionFunction);
}

void ExpertAction::UpGarrison(int inConstObjectId, int typeOp, int inOpUnitId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-garrison");
	ExecuteActionFunction(actionFunction, inConstObjectId, typeOp, inOpUnitId);
}

void ExpertAction::UpGatherInside(int typeOp1, int inOp1BuildingId, int typeOp2, int inOp2State)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-gather-inside");
	ExecuteActionFunction(actionFunction, typeOp1, inOp1BuildingId, typeOp2, inOp2State);
}

void ExpertAction::UpGetAttackerClass(int outGoalSourceClass)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-get-attacker-class");
	ExecuteActionFunction(actionFunction, outGoalSourceClass);
}

void ExpertAction::UpGetCostDelta(int outGoalId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-get-cost-delta");
	ExecuteActionFunction(actionFunction, outGoalId);
}

void ExpertAction::UpGetEvent(int typeOp, int inOpEventId, int outGoalValue)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-get-event");
	ExecuteActionFunction(actionFunction, typeOp, inOpEventId, outGoalValue);
}

void ExpertAction::UpGetFact(int inConstFactId, int inConstParam, int outGoalData)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-get-fact");
	ExecuteActionFunction(actionFunction, inConstFactId, inConstParam, outGoalData);
}

void ExpertAction::UpGetFactMax(int inPlayerAnyPlayer, int inConstFactId, int inConstParam, int outGoalData)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-get-fact-max");
	ExecuteActionFunction(actionFunction, inPlayerAnyPlayer, inConstFactId, inConstParam, outGoalData);
}

void ExpertAction::UpGetFactMin(int inPlayerAnyPlayer, int inConstFactId, int inConstParam, int outGoalData)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-get-fact-min");
	ExecuteActionFunction(actionFunction, inPlayerAnyPlayer, inConstFactId, inConstParam, outGoalData);
}

void ExpertAction::UpGetFactSum(int inPlayerAnyPlayer, int inConstFactId, int inConstParam, int outGoalData)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-get-fact-sum");
	ExecuteActionFunction(actionFunction, inPlayerAnyPlayer, inConstFactId, inConstParam, outGoalData);
}

void ExpertAction::UpGetFocusFact(int inConstFactId, int inConstParam, int outGoalData)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-get-focus-fact");
	ExecuteActionFunction(actionFunction, inConstFactId, inConstParam, outGoalData);
}

void ExpertAction::UpGetGroupSize(int typeOp, int inOpGroupId, int outGoalSize)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-get-group-size");
	ExecuteActionFunction(actionFunction, typeOp, inOpGroupId, outGoalSize);
}

void ExpertAction::UpGetIndirectGoal(int typeOp, int inOpGoalId, int outGoalValue)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-get-indirect-goal");
	ExecuteActionFunction(actionFunction, typeOp, inOpGoalId, outGoalValue);
}

void ExpertAction::UpGetObjectData(int inConstObjectData, int outGoalData)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-get-object-data");
	ExecuteActionFunction(actionFunction, inConstObjectData, outGoalData);
}

void ExpertAction::UpGetObjectTargetData(int inConstObjectData, int outGoalData)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-get-object-target-data");
	ExecuteActionFunction(actionFunction, inConstObjectData, outGoalData);
}

void ExpertAction::UpGetObjectTypeData(int typeOp, int inOpTypeId, int inConstObjectData, int outGoalData)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-get-object-type-data");
	ExecuteActionFunction(actionFunction, typeOp, inOpTypeId, inConstObjectData, outGoalData);
}

void ExpertAction::UpGetPathDistance(int inGoalPoint, int inConstStrict, int outGoalData)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-get-path-distance");
	ExecuteActionFunction(actionFunction, inGoalPoint, inConstStrict, outGoalData);
}

void ExpertAction::UpGetPlayerColor(int inPlayerAnyPlayer, int outGoalColorId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-get-player-color");
	ExecuteActionFunction(actionFunction, inPlayerAnyPlayer, outGoalColorId);
}

void ExpertAction::UpGetPlayerFact(int inPlayerAnyPlayer, int inConstFactId, int inConstParam, int outGoalData)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-get-player-fact");
	ExecuteActionFunction(actionFunction, inPlayerAnyPlayer, inConstFactId, inConstParam, outGoalData);
}

void ExpertAction::UpGetPoint(int inConstPositionType, int outGoalPoint)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-get-point");
	ExecuteActionFunction(actionFunction, inConstPositionType, outGoalPoint);
}

void ExpertAction::UpGetPointContains(int inGoalPoint, int outGoalGoalId, int typeOp, int inOpObjectId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-get-point-contains");
	ExecuteActionFunction(actionFunction, inGoalPoint, outGoalGoalId, typeOp, inOpObjectId);
}

void ExpertAction::UpGetPointDistance(int inGoalPoint1, int inGoalPoint2, int outGoalDistance)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-get-point-distance");
	ExecuteActionFunction(actionFunction, inGoalPoint1, inGoalPoint2, outGoalDistance);
}

void ExpertAction::UpGetPointElevation(int inGoalPoint, int outGoalData)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-get-point-elevation");
	ExecuteActionFunction(actionFunction, inGoalPoint, outGoalData);
}

void ExpertAction::UpGetPointTerrain(int inGoalPoint, int outGoalTerrain)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-get-point-terrain");
	ExecuteActionFunction(actionFunction, inGoalPoint, outGoalTerrain);
}

void ExpertAction::UpGetPointZone(int inGoalPoint, int outGoalData)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-get-point-zone");
	ExecuteActionFunction(actionFunction, inGoalPoint, outGoalData);
}

void ExpertAction::UpGetPreciseTime(int inGoalStart, int outGoalTime)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-get-precise-time");
	ExecuteActionFunction(actionFunction, inGoalStart, outGoalTime);
}

void ExpertAction::UpGetProjectilePlayer(int inConstProjectileType, int outGoalPlayerId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-get-projectile-player");
	ExecuteActionFunction(actionFunction, inConstProjectileType, outGoalPlayerId);
}

void ExpertAction::UpGetRuleId(int outGoalRuleId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-get-rule-id");
	ExecuteActionFunction(actionFunction, outGoalRuleId);
}

void ExpertAction::UpGetSearchState(int outGoalState)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-get-search-state");
	ExecuteActionFunction(actionFunction, outGoalState);
}

void ExpertAction::UpGetSharedGoal(int typeOp, int inOpSharedGoalId, int outGoalValue)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-get-shared-goal");
	ExecuteActionFunction(actionFunction, typeOp, inOpSharedGoalId, outGoalValue);
}

void ExpertAction::UpGetSignal(int typeOp, int inOpSignalId, int outGoalValue)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-get-signal");
	ExecuteActionFunction(actionFunction, typeOp, inOpSignalId, outGoalValue);
}

void ExpertAction::UpGetTargetFact(int inConstFactId, int inConstParam, int outGoalData)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-get-target-fact");
	ExecuteActionFunction(actionFunction, inConstFactId, inConstParam, outGoalData);
}

void ExpertAction::UpGetThreatData(int outGoalElapsedTime, int outGoalPlayerId, int outGoalSourceClass, int outGoalTargetClass)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-get-threat-data");
	ExecuteActionFunction(actionFunction, outGoalElapsedTime, outGoalPlayerId, outGoalSourceClass, outGoalTargetClass);
}

void ExpertAction::UpGetTimer(int typeOp, int inOpTimerId, int outGoalValue)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-get-timer");
	ExecuteActionFunction(actionFunction, typeOp, inOpTimerId, outGoalValue);
}

void ExpertAction::UpGetVictoryData(int outGoalPlayerId, int outGoalType, int outGoalTime)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-get-victory-data");
	ExecuteActionFunction(actionFunction, outGoalPlayerId, outGoalType, outGoalTime);
}

void ExpertAction::UpGetVictoryLimit(int outGoalLimit)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-get-victory-limit");
	ExecuteActionFunction(actionFunction, outGoalLimit);
}

void ExpertAction::UpGuardUnit(int inConstObjectId, int typeOp, int inOpUnitId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-guard-unit");
	ExecuteActionFunction(actionFunction, inConstObjectId, typeOp, inOpUnitId);
}

void ExpertAction::UpJumpDirect(int typeOp, int inOpRuleId)
{
	// crashes with invalid parameters, currently unneeded
}

void ExpertAction::UpJumpDynamic(int typeOp, int inOpRuleDelta)
{
	// crashes with invalid parameters, currently unneeded
}

void ExpertAction::UpJumpRule(int inConstRuleDelta)
{
	// crashes with invalid parameters, currently unneeded
}

void ExpertAction::UpLerpPercent(int ioGoalPoint, int inGoalPoint, int typeOp, int inOpPercent)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-lerp-percent");
	ExecuteActionFunction(actionFunction, ioGoalPoint, inGoalPoint, typeOp, inOpPercent);
}

void ExpertAction::UpLerpTiles(int ioGoalPoint, int inGoalPoint, int typeOp, int inOpTiles)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-lerp-tiles");
	ExecuteActionFunction(actionFunction, ioGoalPoint, inGoalPoint, typeOp, inOpTiles);
}

void ExpertAction::UpLogData(int inConstPlain, const std::string& inTextFormattedString, int typeOp, int inOpValue)
{
	SetCustomString(inTextFormattedString);
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-log-data");
	ExecuteActionFunction(actionFunction, inConstPlain, expert_conf::CONST_CUSTOM_STRING_ID, typeOp, inOpValue);
}

void ExpertAction::UpModifyEscrow(int inConstResource, int mathOp, int inOpValue)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-modify-escrow");
	ExecuteActionFunction(actionFunction, inConstResource, mathOp, inOpValue);
}

void ExpertAction::UpModifyFlag(int ioGoalId, int mathOp, int inOpFlag)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-modify-flag");
	ExecuteActionFunction(actionFunction, ioGoalId, mathOp, inOpFlag);
}

void ExpertAction::UpModifyGoal(int ioGoalId, int mathOp, int inOpValue)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-modify-goal");
	ExecuteActionFunction(actionFunction, ioGoalId, mathOp, inOpValue);
}

void ExpertAction::UpModifyGroupFlag(int inConstOn, int typeOp, int inOpGroupId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-modify-group-flag");
	ExecuteActionFunction(actionFunction, inConstOn, typeOp, inOpGroupId);
}

void ExpertAction::UpModifySn(int ioSnId, int mathOp, int inOpValue)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-modify-sn");
	ExecuteActionFunction(actionFunction, ioSnId, mathOp, inOpValue);
}

void ExpertAction::UpReleaseEscrow()
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-release-escrow");
	ExecuteActionFunction(actionFunction);
}

void ExpertAction::UpRemoveObjects(int inConstSearchSource, int inConstObjectData, int typeOp, int inOpValue)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-remove-objects");
	ExecuteActionFunction(actionFunction, inConstSearchSource, inConstObjectData, typeOp, inOpValue);
}

void ExpertAction::UpRequestHunters(int typeOp, int inOpValue)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-request-hunters");
	ExecuteActionFunction(actionFunction, typeOp, inOpValue);
}

void ExpertAction::UpResearch(int inGoalEscrowState, int typeOp, int inOpTechId)
{
	if (ExpertFact::UpCanResearch(inGoalEscrowState, typeOp, inOpTechId))
	{
		static const ActionFunction actionFunction = *actionFunctionMap.at("up-research");
		ExecuteActionFunction(actionFunction, inGoalEscrowState, typeOp, inOpTechId);
	}
}

void ExpertAction::UpResetAttackNow()
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-reset-attack-now");
	ExecuteActionFunction(actionFunction);
}

void ExpertAction::UpResetBuilding(int inConstPreserveResearch, int typeOp, int inOpBuildingId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-reset-building");
	ExecuteActionFunction(actionFunction, inConstPreserveResearch, typeOp, inOpBuildingId);
}

void ExpertAction::UpResetCostData(int outGoalId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-reset-cost-data");
	ExecuteActionFunction(actionFunction, outGoalId);
}

void ExpertAction::UpResetFilters()
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-reset-filters");
	ExecuteActionFunction(actionFunction);
}

void ExpertAction::UpResetGroup(int typeOp, int inOpGroupId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-reset-group");
	ExecuteActionFunction(actionFunction, typeOp, inOpGroupId);
}

void ExpertAction::UpResetPlacement(int typeOp, int inOpBuildingId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-reset-placement");
	ExecuteActionFunction(actionFunction, typeOp, inOpBuildingId);
}

void ExpertAction::UpResetScouts()
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-reset-scouts");
	ExecuteActionFunction(actionFunction);
}

void ExpertAction::UpResetSearch(int inConstLocalIndex, int inConstLocalList, int inConstRemoteIndex, int inConstRemoteList)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-reset-search");
	ExecuteActionFunction(actionFunction, inConstLocalIndex, inConstLocalList, inConstRemoteIndex, inConstRemoteList);
}

void ExpertAction::UpResetTargetPriorities(int inConstPriorityType, int inConstMode)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-reset-target-priorities");
	ExecuteActionFunction(actionFunction, inConstPriorityType, inConstMode);
}

void ExpertAction::UpResetUnit(int typeOp, int inOpUnitId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-reset-unit");
	ExecuteActionFunction(actionFunction, typeOp, inOpUnitId);
}

void ExpertAction::UpRetaskGatherers(int inConstResource, int typeOp, int inOpValue)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-retask-gatherers");
	ExecuteActionFunction(actionFunction, inConstResource, typeOp, inOpValue);
}

void ExpertAction::UpRetreatNow()
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-retreat-now");
	ExecuteActionFunction(actionFunction);
}

void ExpertAction::UpRetreatTo(int inConstObjectId, int typeOp, int inOpUnitId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-retreat-to");
	ExecuteActionFunction(actionFunction, inConstObjectId, typeOp, inOpUnitId);
}

void ExpertAction::UpSellCommodity(int typeOp1, int inOp1ResourceAmount, int typeOp2, int inOp2Value)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-sell-commodity");
	ExecuteActionFunction(actionFunction, typeOp1, inOp1ResourceAmount, typeOp2, inOp2Value);
}

void ExpertAction::UpSendFlare(int inGoalPoint)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-send-flare");
	ExecuteActionFunction(actionFunction, inGoalPoint);
}

void ExpertAction::UpSendScout(int inConstGroupType, int inConstScoutMethod)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-send-scout");
	ExecuteActionFunction(actionFunction, inConstGroupType, inConstScoutMethod);
}

void ExpertAction::UpSetAttackStance(int inConstUnitId, int typeOp, int inOpAttackStance)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-set-attack-stance");
	ExecuteActionFunction(actionFunction, inConstUnitId, typeOp, inOpAttackStance);
}

void ExpertAction::UpSetDefensePriority(int typeOp1, int inOp1BuildingId, int typeOp2, int inOp2Value)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-set-defense-priority");
	ExecuteActionFunction(actionFunction, typeOp1, inOp1BuildingId, typeOp2, inOp2Value);
}

void ExpertAction::UpSetEvent(int typeOp1, int inOp1EventId, int typeOp2, int inOp2Value)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-set-event");
	ExecuteActionFunction(actionFunction, typeOp1, inOp1EventId, typeOp2, inOp2Value);
}

void ExpertAction::UpSetGroup(int inConstSearchSource, int typeOp, int inOpGroupId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-set-group");
	ExecuteActionFunction(actionFunction, inConstSearchSource, typeOp, inOpGroupId);
}

void ExpertAction::UpSetIndirectGoal(int typeOp1, int inOp1GoalId, int typeOp2, int inOp2Value)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-set-indirect-goal");
	ExecuteActionFunction(actionFunction, typeOp1, inOp1GoalId, typeOp2, inOp2Value);
}

void ExpertAction::UpSetOffensePriority(int typeOp1, int inOp1ObjectId, int typeOp2, int inOp2Value)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-set-offense-priority");
	ExecuteActionFunction(actionFunction, typeOp1, inOp1ObjectId, typeOp2, inOp2Value);
}

void ExpertAction::UpSetPlacementData(int inPlayerAllyPlayer, int inConstObjectId, int typeOp, int inOpValue)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-set-placement-data");
	ExecuteActionFunction(actionFunction, inPlayerAllyPlayer, inConstObjectId, typeOp, inOpValue);
}

void ExpertAction::UpSetPreciseTargetPoint(int inGoalPoint)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-set-precise-target-point");
	ExecuteActionFunction(actionFunction, inGoalPoint);
}

void ExpertAction::UpSetSharedGoal(int typeOp1, int inOp1SharedGoalId, int typeOp2, int inOp2Value)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-set-shared-goal");
	ExecuteActionFunction(actionFunction, typeOp1, inOp1SharedGoalId, typeOp2, inOp2Value);
}

void ExpertAction::UpSetSignal(int typeOp1, int inOp1SignalId, int typeOp2, int inOp2Value)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-set-signal");
	ExecuteActionFunction(actionFunction, typeOp1, inOp1SignalId, typeOp2, inOp2Value);
}

void ExpertAction::UpSetTargetById(int typeOp, int inOpId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-set-target-by-id");
	ExecuteActionFunction(actionFunction, typeOp, inOpId);
}

void ExpertAction::UpSetTargetObject(int inConstSearchSource, int typeOp, int inOpIndex)
{
#if defined GAME_DE
	if (inConstSearchSource != 0) // crashes otherwise
#endif
	{
		static const ActionFunction actionFunction = *actionFunctionMap.at("up-set-target-object");
		ExecuteActionFunction(actionFunction, inConstSearchSource, typeOp, inOpIndex);
	}
}

void ExpertAction::UpSetTargetPoint(int inGoalPoint)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-set-target-point");
	ExecuteActionFunction(actionFunction, inGoalPoint);
}

void ExpertAction::UpSetTimer(int typeOp1, int inOp1TimerId, int typeOp2, int inOp2Value)
{
#if defined GAME_AOC
	if (inOp2Value != 0) // crashes otherwise
#endif
	{
		static const ActionFunction actionFunction = *actionFunctionMap.at("up-set-timer");
		ExecuteActionFunction(actionFunction, typeOp1, inOp1TimerId, typeOp2, inOp2Value);
	}
}

void ExpertAction::UpSetupCostData(int inConstResetCost, int ioGoalId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-setup-cost-data");
	ExecuteActionFunction(actionFunction, inConstResetCost, ioGoalId);
}

void ExpertAction::UpStoreMapName(int inConstExtension)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-store-map-name");
	ExecuteActionFunction(actionFunction, inConstExtension);
}

void ExpertAction::UpStoreObjectName()
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-store-object-name");
	ExecuteActionFunction(actionFunction);
}

void ExpertAction::UpStorePlayerChat(int inPlayerAnyPlayer)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-store-player-chat");
	ExecuteActionFunction(actionFunction, inPlayerAnyPlayer);
}

void ExpertAction::UpStorePlayerName(int inPlayerAnyPlayer)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-store-player-name");
	ExecuteActionFunction(actionFunction, inPlayerAnyPlayer);
}

void ExpertAction::UpStoreTechName(int typeOp, int inOpTechId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-store-tech-name");
	ExecuteActionFunction(actionFunction, typeOp, inOpTechId);
}

void ExpertAction::UpStoreText(int typeOp, int inOpLanguageId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-store-text");
	ExecuteActionFunction(actionFunction, typeOp, inOpLanguageId);
}

void ExpertAction::UpStoreTypeName(int typeOp, int inOpTypeId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-store-type-name");
	ExecuteActionFunction(actionFunction, typeOp, inOpTypeId);
}

void ExpertAction::UpTargetObjects(int inConstTarget, int inConstTargetAction, int inConstFormation, int inConstAttackStance)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-target-objects");
	ExecuteActionFunction(actionFunction, inConstTarget, inConstTargetAction, inConstFormation, inConstAttackStance);
}

void ExpertAction::UpTargetPoint(int inGoalPoint, int inConstTargetAction, int inConstFormation, int inConstAttackStance)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-target-point");
	ExecuteActionFunction(actionFunction, inGoalPoint, inConstTargetAction, inConstFormation, inConstAttackStance);
}

void ExpertAction::UpTrain(int inGoalEscrowState, int typeOp, int inOpUnitId)
{
	if (ExpertFact::UpCanTrain(inGoalEscrowState, typeOp, inOpUnitId))
	{
		static const ActionFunction actionFunction = *actionFunctionMap.at("up-train");
		ExecuteActionFunction(actionFunction, inGoalEscrowState, typeOp, inOpUnitId);
	}
}

void ExpertAction::UpTributeToPlayer(int inPlayerAnyPlayer, int inConstResourceAmount, int typeOp, int inOpValue)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-tribute-to-player");
	ExecuteActionFunction(actionFunction, inPlayerAnyPlayer, inConstResourceAmount, typeOp, inOpValue);
}

void ExpertAction::UpUngarrison(int typeOp, int inOpObjectId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-ungarrison");
	ExecuteActionFunction(actionFunction, typeOp, inOpObjectId);
}

void ExpertAction::UpUpdateTargets()
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-update-targets");
	ExecuteActionFunction(actionFunction);
}

void ExpertAction::ChatDebug(const std::string& inTextString)
{
	SetCustomString(inTextString);
	static const ActionFunction actionFunction = *actionFunctionMap.at("chat-debug");
	ExecuteActionFunction(actionFunction, expert_conf::CONST_CUSTOM_STRING_ID);
}

void ExpertAction::FeBreakPoint(int param1, int param2, int param3, int param4)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("fe-break-point");
	ExecuteActionFunction(actionFunction, param1, param2, param3, param4);
}

void ExpertAction::SkyboxClearSignal(int param)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("skybox-clear-signal");
	ExecuteActionFunction(actionFunction, param);
}

void ExpertAction::SkyboxSetNameMode(int param)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("skybox-set-name-mode");
	ExecuteActionFunction(actionFunction, param);
}

void ExpertAction::UpChatDataToAllUsingId(int param1, int param2, int param3)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-chat-data-to-all-using-id");
	ExecuteActionFunction(actionFunction, param1, param2, param3);
}

void ExpertAction::UpChatDataToPlayerUsingId(int param1, int param2, int param3, int param4)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-chat-data-to-player-using-id");
	ExecuteActionFunction(actionFunction, param1, param2, param3, param4);
}

void ExpertAction::UpGetTreatyData(int param)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-get-treaty-data");
	ExecuteActionFunction(actionFunction, param);
}

void ExpertAction::UpTestharnessReport(int param1, int param2, int param3)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-testharness-report");
	ExecuteActionFunction(actionFunction, param1, param2, param3);
}

void ExpertAction::UpTestharnessTest(int param1, int param2, int param3, int param4)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-testharness-test");
	ExecuteActionFunction(actionFunction, param1, param2, param3, param4);
}

void ExpertAction::UpGetAlliedTarget(int param1, int param2)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-get-allied-target");
	ExecuteActionFunction(actionFunction, param1, param2);
}

void ExpertAction::UpGetGuardState(int outGoalState)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-get-guard-state");
	ExecuteActionFunction(actionFunction, outGoalState);
}

void ExpertAction::UpGetUpgradeId(int inPlayerAnyPlayer, int inConstCount, int inGoalTypeId, int outGoalUpgradeId)
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-get-upgrade-id");
	ExecuteActionFunction(actionFunction, inPlayerAnyPlayer, inConstCount, inGoalTypeId, outGoalUpgradeId);
}

void ExpertAction::UpOutOfSync()
{
	static const ActionFunction actionFunction = *actionFunctionMap.at("up-out-of-sync");
	ExecuteActionFunction(actionFunction);
}
