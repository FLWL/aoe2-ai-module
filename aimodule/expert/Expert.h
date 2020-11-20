#pragma once
#include <set>
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
	int ResolveConst(const std::string& constToResolve);
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

#if defined GAME_DE
	static int64_t DetouredRunList(void* aiExpertEngine, int listId, void* statsOutput);
	inline static int64_t(*FuncRunList)(void* aiExpertEngine, int listId, void* statsOutput) = 0;
	static int64_t DetouredEvaluateRelOp(int relOp, int arg1, int arg2, char a4, char a5);
	inline static int64_t(*FuncEvaluateRelOp)(int relOp, int arg1, int arg2, char a4, char a5) = 0;
#elif defined GAME_AOC
	static int32_t __fastcall DetouredRunList(void* aiExpertEngine, void* unused, int listId, void* statsOutput);
	inline static int32_t(__thiscall* FuncRunList)(void* aiExpertEngine, int listId, void* statsOutput) = 0;
#endif
};
