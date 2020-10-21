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

#ifdef DEBUG_MODE
	void PrintFuncs();
#endif

private:
	struct SymbolData
	{
		char type;
		int16_t id;
	};

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
#ifdef GAME_DE
	static int64_t __fastcall DetouredEvaluateRelOp(int relOp, int arg1, int arg2, char a4, char a5);
#endif
#ifdef DEBUG_MODE
	inline static std::set<std::string> actionFuncs;
	inline static std::set<std::string> factFuncs;
	static intptr_t __fastcall DetouredDefAction(void* aiExpert, char *name, char argCount, void* function);
	static intptr_t __fastcall DetouredDefFact(void* aiExpert, char *name, int factType, char argCount, void* function);
#endif
	inline static intptr_t(__fastcall* FuncRunList)(void* aiExpertEngine, int listId, void* statsOutput) = 0;
	inline static intptr_t(__fastcall* FuncEvaluateRelOp)(int relOp, int arg1, int arg2, char a4, char a5) = 0;
	inline static SymbolData*(__fastcall* FuncFindSymbol)(void* symbolTable, char* symbol, char dataType) = 0;
#ifdef DEBUG_MODE
	inline static intptr_t(__fastcall* FuncDefAction)(void* aiExpert, char *name, char argCount, void* function) = 0;
	inline static intptr_t(__fastcall* FuncDefFact)(void* aiExpert, char *name, int factType, char argCount, void* function) = 0;
#endif
};
