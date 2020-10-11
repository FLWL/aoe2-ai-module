#pragma once
#include <string>
#include <unordered_map>

#include "google/protobuf/any.pb.h"

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
	static int64_t __fastcall DetouredRunList(void* aiExpertEngine, int listId, void* statsOutput);
	inline static int64_t(__fastcall* FuncRunList)(void* aiExpertEngine, int listId, void* statsOutput) = 0;
};
