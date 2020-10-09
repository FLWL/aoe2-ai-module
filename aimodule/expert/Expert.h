#pragma once
#include "expert/ExpertCommandQueue.h"
#include "expert/ExpertService.h"

class AIModule;

class Expert
{
public:
	Expert(AIModule* aiModule);
	~Expert();

	void ProcessCommands();
	ExpertService* GetService() { return &expertService; };
	ExpertCommandQueue* GetCommandQueue() { return &commandQueue; };
	void PreUnload();

private:
	void UpdateAddresses();
	void EnableDetours();
	void DisableDetours();
	void ProcessCommand(const protos::expert::RequestList* request, protos::expert::ReplyList* reply);

	AIModule* aiModule;
	ExpertService expertService;
	ExpertCommandQueue commandQueue;

	static Expert* instance;
	static int64_t __fastcall DetouredRunList(void* aiExpertEngine, int listId, void* statsOutput);
	inline static int64_t(__fastcall* FuncRunList)(void* aiExpertEngine, int listId, void* statsOutput) = 0;
};
