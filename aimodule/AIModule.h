#pragma once
#include <string>
#include <mutex>
#include <condition_variable>

#include "misc/Configuration.h"
#include "misc/DebugConsole.h"
#include "misc/RPCServer.h"
#include "AIModuleService.h"
#include "expert/Expert.h"

class AIModule
{
public:
	AIModule();
	~AIModule();

	void RequestUnload();
	bool IsUnloadRequested();
	bool IsMatchInProgress();
	std::string GetGameDataFilePath();

	AIModuleService* GetService() { return &aiModuleService; };
	Expert* GetExpert() { return &expert; };

private:
	void WaitUntilUnload();

	// submodules initialized in this order
#ifdef DEBUG_MODE
	DebugConsole debugConsole;
#endif
	Expert expert;
	AIModuleService aiModuleService;
	RPCServer rpcServer;

	// flag set to unload this dll
	std::mutex unloadRequestedMutex;
	std::condition_variable unloadRequestedCondVar;
	bool unloadRequested;
};
