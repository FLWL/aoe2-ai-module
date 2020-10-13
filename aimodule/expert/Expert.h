#pragma once
#include <string>
#include <unordered_map>

#include "google/protobuf/any.pb.h"

#include "misc/Configuration.h"
#include "expert/ExpertCommandQueue.h"
#include "expert/ExpertService.h"

class AIModule;

class Expert
{
public:
	Expert(AIModule* aiModule);
	~Expert();

	int ProcessCommands();
	ExpertService* GetService() { return &expertService; };
	ExpertCommandQueue* GetCommandQueue() { return &commandQueue; };
	void PreUnload();

private:
	void UpdateAddresses();
	void PopulateCommandMap();
	void EnableDetours();
	void DisableDetours();
	int ProcessCommandList(const protos::expert::CommandList* commandList, protos::expert::CommandResultList* commandResultList);

	AIModule* aiModule;
	ExpertService expertService;
	ExpertCommandQueue commandQueue;
	std::unordered_map<std::string, void(*)(const google::protobuf::Any&, google::protobuf::Any*)> commandMap;

	static Expert* instance;
	static intptr_t __fastcall DetouredRunList(void* aiExpertEngine, int listId, void* statsOutput);
#ifdef DEBUG_MODE
	static intptr_t __fastcall DetouredDefAction(void* aiExpert, char *name, char argCount, void* function);
#endif
	inline static intptr_t(__fastcall* FuncRunList)(void* aiExpertEngine, int listId, void* statsOutput) = 0;
#ifdef DEBUG_MODE
	inline static intptr_t(__fastcall* FuncDefAction)(void* aiExpert, char *name, char argCount, void* function) = 0;
#endif
};
