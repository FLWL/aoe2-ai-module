#include "ExpertService.h"

#include "Expert.h"

ExpertService::ExpertService(Expert* expert) :
	expert(expert)
{
	
}


ExpertService::~ExpertService()
{

}

grpc::Status ExpertService::RunRequestList(grpc::ServerContext * context, const protos::expert::RequestList * request, protos::expert::ReplyList * reply)
{
	return expert->GetCommandQueue()->PushAndWaitForCompletion(request, reply);
}
