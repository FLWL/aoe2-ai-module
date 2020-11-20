#include "AIModuleService.h"

#include "AIModule.h"

AIModuleService::AIModuleService(AIModule* aiModule) :
	aiModule(aiModule)
{

}

AIModuleService::~AIModuleService()
{

}

grpc::Status AIModuleService::IsMatchInProgress(grpc::ServerContext* context, const protos::IsMatchInProgressRequest* request, protos::IsMatchInProgressReply* reply)
{
	reply->set_result(aiModule->IsMatchInProgress());
	return grpc::Status::OK;
}

grpc::Status AIModuleService::Unload(grpc::ServerContext* context, const protos::UnloadRequest* request, protos::UnloadReply* reply)
{
	aiModule->RequestUnload();
	return grpc::Status::OK;
}
