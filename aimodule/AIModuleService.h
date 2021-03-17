#pragma once
#include "protos/ai_module_api.grpc.pb.h"

class AIModule;

class AIModuleService final : public protos::AIModuleAPI::Service
{
public:
	AIModuleService(AIModule* aiModule);
	~AIModuleService();

	grpc::Status GetMatchStatus(grpc::ServerContext* context, const protos::GetMatchStatusRequest* request, protos::GetMatchStatusReply* reply) override;
	grpc::Status GetGameDataFilePath(grpc::ServerContext* context, const protos::GetGameDataFilePathRequest* request, protos::GetGameDataFilePathReply* reply) override;
	grpc::Status Unload(grpc::ServerContext* context, const protos::UnloadRequest* request, protos::UnloadReply* reply) override;
private:
	AIModule* aiModule;
};
