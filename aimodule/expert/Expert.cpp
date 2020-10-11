#include "Expert.h"

#include <iostream>
#include <chrono>

#include <Windows.h>
#include <detours/detours.h>

#include "AIModule.h"
#include "misc/Statics.h"
#include "expert/action/ExpertAction.h"
#include "expert/action/ExpertActionHandler.h"
#include "expert/fact/ExpertFact.h"
#include "expert/fact/ExpertFactHandler.h"

Expert* Expert::instance;

Expert::Expert(AIModule* aiModule) :
	aiModule(aiModule),
	expertService(this)
{
	instance = this;
	UpdateAddresses();
	PopulateCommandMap();
	EnableDetours();
}

void Expert::UpdateAddresses()
{
	statics::SetFuncAddr(FuncRunList, statics::TranslateAddr(expert_conf::ADDR_FUNC_RUN_LIST));

	ExpertAction::UpdateAddresses();
	ExpertFact::UpdateAddresses();
}

void Expert::PopulateCommandMap()
{
	commandMap.insert({ "type.googleapis.com/protos.expert.action.Train", &ExpertActionHandler::Train });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.Build", &ExpertActionHandler::Build });
	commandMap.insert({ "type.googleapis.com/protos.expert.action.UpGetFact", &ExpertActionHandler::UpGetFact });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.Goal", &ExpertFactHandler::Goal });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.Goals", &ExpertFactHandler::Goals });
	commandMap.insert({ "type.googleapis.com/protos.expert.fact.UpGetFact", &ExpertFactHandler::UpGetFact });
}

void Expert::EnableDetours()
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)FuncRunList, DetouredRunList);
	DetourTransactionCommit();
}

void Expert::DisableDetours()
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourDetach(&(PVOID&)FuncRunList, DetouredRunList);
	DetourTransactionCommit();
}

int64_t __fastcall Expert::DetouredRunList(void* aiExpertEngine, int listId, void* statsOutput)
{
	int64_t result = FuncRunList(aiExpertEngine, listId, statsOutput);

	auto t1 = std::chrono::high_resolution_clock::now();
	int numCommandsProcessed = Expert::instance->ProcessCommands();
	auto t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

	if (numCommandsProcessed)
	{
		std::cout << "Processed " << numCommandsProcessed  << " command(s) in " << duration << " us"<< std::endl;
	}

	return result;
}

int Expert::ProcessCommands()
{
	int numCommandsProcessed = 0;
	std::lock_guard<std::mutex> lguard(*commandQueue.GetMutex());
	while (!commandQueue.IsEmpty())
	{
		// work to do
		ExpertCommandQueue::Item* item = commandQueue.Pop();

		// process
		numCommandsProcessed += ProcessCommandList(item->commandList, item->commandResultList);

		// mark as processed and wake up the corresponding rpc thread
		*item->isProcessed = true;
		item->conditionVar->notify_one();
	}

	return numCommandsProcessed;
}

int Expert::ProcessCommandList(const protos::expert::CommandList* commandList, protos::expert::CommandResultList* commandResultList)
{
	int numCommandsProcessed = 0;

	for (int requestIndex = 0; requestIndex < commandList->commands_size(); requestIndex++)
	{
		google::protobuf::Any anyCommand = commandList->commands(requestIndex);
		google::protobuf::Any* anyResult = commandResultList->add_results();
		
		auto commandHandler = commandMap[anyCommand.type_url()];
		if (commandHandler)
		{
			commandHandler(anyCommand, anyResult);
			numCommandsProcessed++;
		}
	}

	return numCommandsProcessed;
}

void Expert::PreUnload()
{
	commandQueue.Clear();
}

Expert::~Expert()
{
	DisableDetours();
}
