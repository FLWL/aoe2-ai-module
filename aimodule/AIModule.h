#pragma once
#include <condition_variable>
#include <mutex>
#include <string>

#include "AIModuleService.h"
#include "expert/Expert.h"
#include "misc/DebugConsole.h"
#include "misc/RPCServer.h"
#include "structs/Game.h"

class AIModule
{
public:
	AIModule();
	~AIModule();

	void RequestUnload();
	bool IsUnloadRequested();
	int GetMatchStatus();
	std::string GetGameDataFilePath();

	AIModuleService* GetService() { return &aiModuleService; };
	Expert* GetExpert() { return &expert; };

	inline static structs::Game* game;

private:
	void SetGamePointer();
	void WaitUntilUnload();

	// submodules initialized in this order
	DebugConsole debugConsole;
	Expert expert;
	AIModuleService aiModuleService;
	RPCServer rpcServer;

	// flag set to unload this dll
	std::mutex unloadRequestedMutex;
	std::condition_variable unloadRequestedCondVar;
	bool unloadRequested;
};
