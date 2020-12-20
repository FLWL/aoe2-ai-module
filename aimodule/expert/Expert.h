#pragma once
#include <set>
#include <string>
#include <unordered_map>

#include "google/protobuf/any.pb.h"

#include "misc/Configuration.h"
#include "expert/ExpertService.h"
#include "expert/ExpertCommandQueue.h"
#include "expert/action/ExpertAction.h"
#include "expert/fact/ExpertFact.h"

class AIModule;

class Expert
{
public:
	Expert(AIModule* aiModule);
	~Expert();

	ExpertService* GetService() { return &expertService; };
	ExpertCommandQueue* GetCommandQueue() { return &commandQueue; };

private:
	void UpdateAddresses();
	void PopulateCommandMap();
	void EnableDetours();
	void DisableDetours();
	int ProcessCommands();
	int ProcessCommandList(const protos::expert::CommandList* commandList, protos::expert::CommandResultList* commandResultList);

	// submodules initialized in this order
	AIModule* aiModule;
	ExpertService expertService;
	ExpertCommandQueue commandQueue;
	ExpertAction expertAction;
	ExpertFact expertFact;

	static Expert* instance;
	std::unordered_map<std::string, void(*)(const google::protobuf::Any&, google::protobuf::Any*)> commandMap;

#if defined GAME_DE
	static int64_t DetouredRunList(void* aiExpertEngine, int listId, void* statsOutput);
	inline static int64_t(*FuncRunList)(void* aiExpertEngine, int listId, void* statsOutput) = 0;
#elif defined GAME_AOC
	static int32_t __fastcall DetouredRunList(void* aiExpertEngine, void* unused, int listId, void* statsOutput);
	inline static int32_t(__thiscall* FuncRunList)(void* aiExpertEngine, int listId, void* statsOutput) = 0;
#endif
};
