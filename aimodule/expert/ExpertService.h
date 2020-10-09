#pragma once
#include "protos/expert/expert_api.grpc.pb.h"

class Expert;

class ExpertService final : public protos::expert::ExpertAPI::Service
{
public:
	ExpertService(Expert* expert);
	~ExpertService();

	grpc::Status RunRequestList(grpc::ServerContext* context, const protos::expert::RequestList* request, protos::expert::ReplyList* reply) override;

private:
	Expert* expert;


};

