#include "AIModule.h"

#include <iostream>
#include <filesystem>

#include "misc/Statics.h"
#include "misc/Configuration.h"
#include "structs/Game.h"

AIModule::AIModule() :
#ifdef DEBUG_MODE
	debugConsole(this),
#endif
	expert(this),
	unloadRequested(false),
	aiModuleService(this),
	rpcServer(this)
{
	WaitUntilUnload();
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

bool AIModule::IsMatchInProgress()
{
	structs::Game* game = *(structs::Game**)statics::TranslateAddr(expert_conf::ADDR_PTR_BASE_GAME);

#if defined GAME_DE
	return game->programMode->programMode == 1;
#elif defined GAME_AOC
	return game->programMode == 4;
#endif
}

std::string AIModule::GetGameDataFilePath()
{
	structs::Game* game = *(structs::Game**)statics::TranslateAddr(expert_conf::ADDR_PTR_BASE_GAME);

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
