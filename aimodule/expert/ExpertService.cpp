#include "ExpertService.h"

#include "Expert.h"

ExpertService::ExpertService(Expert* expert) :
	expert(expert)
{
	
}


ExpertService::~ExpertService()
{

}

grpc::Status ExpertService::ExecuteCommandList(grpc::ServerContext* context, const protos::expert::CommandList* commandList, protos::expert::CommandResultList* commandResultList)
{
	return expert->GetCommandQueue()->PushAndWaitForCompletion(commandList, commandResultList);
}
