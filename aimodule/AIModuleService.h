#pragma once
#include "protos/ai_module_api.grpc.pb.h"

class AIModule;

class AIModuleService final : public protos::AIModuleAPI::Service
{
public:
	AIModuleService(AIModule* aiModule);
	~AIModuleService();

	grpc::Status IsMatchInProgress(grpc::ServerContext* context, const protos::IsMatchInProgressRequest* request, protos::IsMatchInProgressReply* reply) override;
	grpc::Status GetGameDataFilePath(grpc::ServerContext* context, const protos::GetGameDataFilePathRequest* request, protos::GetGameDataFilePathReply* reply) override;
	grpc::Status Unload(grpc::ServerContext* context, const protos::UnloadRequest* request, protos::UnloadReply* reply) override;
private:
	AIModule* aiModule;
};
