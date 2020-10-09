#include "Expert.h"

#include <iostream>

#include <Windows.h>
#include <detours/detours.h>

#include "AIModule.h"
#include "misc/Statics.h"
#include "expert/action/ExpertAction.h"
#include "expert/fact/ExpertFact.h"

Expert* Expert::instance;

Expert::Expert(AIModule* aiModule) :
	aiModule(aiModule),
	expertService(this)
{
	instance = this;
	UpdateAddresses();
	EnableDetours();
}

void Expert::UpdateAddresses()
{
	statics::SetFuncAddr(&FuncRunList, statics::TranslateAddr(expert_conf::ADDR_FUNC_RUN_LIST));

	ExpertAction::UpdateAddresses();
	ExpertFact::UpdateAddresses();
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
	Expert::instance->ProcessCommands();
	return result;
}

void Expert::ProcessCommands()
{
	std::lock_guard<std::mutex> lguard(*commandQueue.GetMutex());
	while (!commandQueue.IsEmpty())
	{
		// work to do
		ExpertCommandQueue::Item* item = commandQueue.Pop();

		// process
		ProcessCommand(item->request, item->reply);

		// mark as processed and wake up the corresponding rpc thread
		*item->isProcessed = true;
		item->conditionVar->notify_one();
	}
}

void Expert::ProcessCommand(const protos::expert::RequestList* request, protos::expert::ReplyList* reply)
{
	for (int requestIndex = 0; requestIndex < request->request_size(); requestIndex++)
	{
		protos::expert::Request singleRequest = request->request(requestIndex);
		protos::expert::Reply* singleReply = reply->add_reply();

		switch (singleRequest.requestType_case())
		{
			// Actions
			case protos::expert::Request::kTrain:
			{
				singleReply->mutable_trainreply()->set_success(ExpertAction::Train(singleRequest.train().unittype()));
				break;
			}
			case protos::expert::Request::kBuild:
			{
				singleReply->mutable_buildreply()->set_success(ExpertAction::Build(singleRequest.build().buildingtype()));
				break;
			}
			case protos::expert::Request::kUpGetFact:
			{
				auto upGetFactReq = singleRequest.upgetfact();
				ExpertAction::UpGetFact(upGetFactReq.factid(), upGetFactReq.factparam(), upGetFactReq.goalid());
				singleReply->mutable_upgetfactreply();
				break;
			}
			// Facts
			case protos::expert::Request::kGoal:
			{
				auto goalReq = singleRequest.goal();
				singleReply->mutable_goalreply()->set_goalvalue(ExpertFact::Goal(goalReq.goalid()));
				break;
			}
			case protos::expert::Request::kGoals:
			{
				auto goalsReq = singleRequest.goals();
				auto goals = ExpertFact::Goals();
				for (int i = 0; i < goals.size(); i++) singleReply->mutable_goalsreply()->add_goalvalue(goals.at(i));
				break;
			}
		}
	}
}

void Expert::PreUnload()
{
	commandQueue.Clear();
}

Expert::~Expert()
{
	DisableDetours();
}
