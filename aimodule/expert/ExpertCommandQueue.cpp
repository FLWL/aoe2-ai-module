#include "ExpertCommandQueue.h"
#include "misc/Statics.h"
#include "misc/Configuration.h"

ExpertCommandQueue::ExpertCommandQueue()
{

}


ExpertCommandQueue::~ExpertCommandQueue()
{
	
}

grpc::Status ExpertCommandQueue::PushAndWaitForCompletion(const protos::expert::CommandList* commandList, protos::expert::CommandResultList* commandResultList)
{
#if defined VERBOSE_DEBUG
	std::cout << "ExpertCommandQueue::PushAndWaitForCompletion(): Pushing new command to queue." << std::endl;
#endif

	// vars to determine when this request has been processed by the game thread
	bool isProcessed = false;
	std::condition_variable conditionVar;
	grpc::Status status = grpc::Status::OK;

	// data about this request to pass to the game thread
	Item item;
	item.commandList = commandList;
	item.commandResultList = commandResultList;
	item.isProcessed = &isProcessed;
	item.conditionVar = &conditionVar;
	item.status = &status;

	// acquire lock on the command queue, push our new item, wait until it is completed
	std::unique_lock<std::mutex> ulock(commandQueueMutex);
	commandQueue.push_back(&item);
	if (!conditionVar.wait_for(ulock, std::chrono::seconds(expert_conf::COMMAND_TIMEOUT_SECONDS), [&isProcessed] { return isProcessed; }))
	{
#if defined VERBOSE_DEBUG
		std::cout << "ExpertCommandQueue::PushAndWaitForCompletion(): Timeout occurred." << std::endl;
#endif

		// wait timed out, remove from queue and mark item as cancelled
		commandQueue.erase(std::remove(commandQueue.begin(), commandQueue.end(), &item), commandQueue.end());
		return grpc::Status(grpc::StatusCode::CANCELLED, "Request was not processed in time by the game thread.");
	}
	
#if defined VERBOSE_DEBUG
	std::cout << "ExpertCommandQueue::PushAndWaitForCompletion(): Command marked as processed. Sending reply." << std::endl;
#endif

	return status;
}

std::mutex* ExpertCommandQueue::GetMutex()
{
	return &commandQueueMutex;
}

std::deque<ExpertCommandQueue::Item*>* ExpertCommandQueue::GetInternalQueue()
{
	return &commandQueue;
}

ExpertCommandQueue::Item* ExpertCommandQueue::Pop()
{
	Item* item = commandQueue.front();
	commandQueue.pop_front();
	
	return item;
}

void ExpertCommandQueue::Clear()
{
	std::lock_guard<std::mutex> lguard(commandQueueMutex);
	while (!IsEmpty())
	{
		Item* item = Pop();
		*item->isProcessed = true;
		*item->status = grpc::Status(grpc::StatusCode::CANCELLED, "Processing queue is being cleared.");
		item->conditionVar->notify_one();
	}
}

bool ExpertCommandQueue::IsEmpty()
{
	return commandQueue.empty();
}
