#include "AIModuleService.h"

#include "AIModule.h"

AIModuleService::AIModuleService(AIModule* aiModule) :
	aiModule(aiModule)
{

}

AIModuleService::~AIModuleService()
{

}

grpc::Status AIModuleService::Unload(grpc::ServerContext* context, const protos::UnloadRequest* request, protos::UnloadReply* reply)
{
	aiModule->RequestUnload();
	return grpc::Status::OK;
}
