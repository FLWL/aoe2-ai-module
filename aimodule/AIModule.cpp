#include "AIModule.h"

#include <iostream>

AIModule::AIModule(HMODULE currentModuleHandle) :
	debugConsole(this),
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

AIModule::~AIModule()
{
	expert.PreUnload();
}
