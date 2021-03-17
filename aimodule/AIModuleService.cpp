#include "AIModuleService.h"

#include "AIModule.h"

AIModuleService::AIModuleService(AIModule* aiModule) :
	aiModule(aiModule)
{

}

AIModuleService::~AIModuleService()
{

}

grpc::Status AIModuleService::GetMatchStatus(grpc::ServerContext* context, const protos::GetMatchStatusRequest* request, protos::GetMatchStatusReply* reply)
{
	int matchStatus = aiModule->GetMatchStatus();
	if (matchStatus < 0) matchStatus = 0;
	if (matchStatus > 3) matchStatus = 2;

	reply->set_matchstatus(static_cast<protos::GetMatchStatusReply_MatchStatus>(matchStatus));
	return grpc::Status::OK;
}

grpc::Status AIModuleService::GetGameDataFilePath(grpc::ServerContext* context, const protos::GetGameDataFilePathRequest* request, protos::GetGameDataFilePathReply* reply)
{
	reply->set_result(aiModule->GetGameDataFilePath());
	return grpc::Status::OK;
}

grpc::Status AIModuleService::Unload(grpc::ServerContext* context, const protos::UnloadRequest* request, protos::UnloadReply* reply)
{
	aiModule->RequestUnload();
	return grpc::Status::OK;
}
