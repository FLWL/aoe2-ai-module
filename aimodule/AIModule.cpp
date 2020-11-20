#include "AIModule.h"

#include <iostream>

#include "misc/Statics.h"
#include "misc/Configuration.h"

AIModule::AIModule(HMODULE currentModuleHandle) :
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
#if defined GAME_DE
	static int8_t* bgame = 0;
	if (!bgame) bgame = *(int8_t**)statics::TranslateAddr(expert_conf::ADDR_PTR_BASE_GAME);
	return *(int32_t*)(*(int64_t*)(bgame + 704) + 8) == 1;
#elif defined GAME_AOC
	return *(int32_t*)(*(int8_t**)statics::TranslateAddr(expert_conf::ADDR_PTR_BASE_GAME) + 480) == 4;
#endif
}

AIModule::~AIModule()
{
	expert.PreUnload();
}
