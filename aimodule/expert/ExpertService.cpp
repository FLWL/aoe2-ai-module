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

grpc::Status ExpertService::ResolveConst(grpc::ServerContext* context, const protos::expert::ResolveConstRequest* resolveConstRequest, protos::expert::ResolveConstResponse* resolveConstResponse)
{
	int constValue = expert->ResolveConst(resolveConstRequest->consttoresolve());
	resolveConstResponse->set_constvalue(constValue);

	return grpc::Status::OK;
}
