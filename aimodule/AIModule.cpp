#include "AIModule.h"

#include <iostream>
#include <filesystem>

#include "misc/Configuration.h"
#include "misc/MemoryUtils.h"
#include "misc/Statics.h"

AIModule::AIModule() :
	debugConsole(this),
	expert(this),
	unloadRequested(false),
	aiModuleService(this),
	rpcServer(this)
{
	SetGamePointer();
	WaitUntilUnload();
}

void AIModule::SetGamePointer()
{
#if defined GAME_DE
	uintptr_t gameTypeAddress = memory_utils::FindPatternInGameModule(expert_conf::SIG_FUNC_GAME_TYPE);
	if (gameTypeAddress)
	{
		uintptr_t movInstructionAddress = gameTypeAddress + 29;
		std::vector<uint8_t> movInstructionData = memory_utils::ReadMemory(movInstructionAddress, 7);
		game = *(structs::Game**)memory_utils::GetInstructionImmMemOperand(movInstructionAddress, movInstructionData);
	}

	if (!game)
	{
		std::cout << "[AI Module] Error: failed to locate class 'Game'."
			<< " AI Module general calls will not work."
			<< std::endl;
	}
#elif defined GAME_AOC
	game = *(structs::Game**)statics::TranslateAddr(expert_conf::ADDR_PTR_BASE_GAME);
#endif
}

void AIModule::WaitUntilUnload()
{
	std::unique_lock<std::mutex> ulock(unloadRequestedMutex);
	unloadRequestedCondVar.wait(ulock, [&unloadRequested = unloadRequested] { return unloadRequested; });
}

void AIModule::RequestUnload()
{
	if (!IsUnloadRequested())
	{
		std::lock_guard<std::mutex> lguard(unloadRequestedMutex);
		unloadRequested = true;
		unloadRequestedCondVar.notify_one();
	}
}

bool AIModule::IsUnloadRequested()
{
	std::lock_guard<std::mutex> lguard(unloadRequestedMutex);
	return unloadRequested;
}

int AIModule::GetMatchStatus()
{
	if (!game || !game->world)
		return 2; // NO_MATCH

	return game->world->gameState;
}

std::string AIModule::GetGameDataFilePath()
{
	if (!game)
		return std::string("");

#if defined GAME_DE
	return std::string("");
#elif defined GAME_AOC
	std::filesystem::path gamePath(game->workingDirectory);
	std::filesystem::path gameDataFilePath(game->programInformation->gameDataFilePath);

	return (gamePath / gameDataFilePath).string();
#endif
}

AIModule::~AIModule()
{
	// send back error messages before the RPC server gets closed
	expert.GetCommandQueue()->Clear();
}
