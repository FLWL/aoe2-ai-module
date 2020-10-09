#include "RPCServer.h"
#include "AIModule.h"

#include "misc/Configuration.h"
#include "protos/ai_module_api.grpc.pb.h"

RPCServer::RPCServer(AIModule* aiModule) :
	aiModule(aiModule)
{
	grpc::ServerBuilder builder;
	builder.AddListeningPort(aimodule_conf::RPC_SERVER_ADDRESS, grpc::InsecureServerCredentials());
	builder.RegisterService(aiModule->GetService());
	builder.RegisterService(aiModule->GetExpert()->GetService());

	// start rpc server on another thread
	server = builder.BuildAndStart();
	serverThread = std::make_unique<std::thread>(&RPCServer::ServerThread, this);
}

void RPCServer::ServerThread()
{
	server->Wait();
}

RPCServer::~RPCServer()
{
	// don't accept any new RPC calls and wait for existing to finish or timeout
	server->Shutdown();
	serverThread->join();
}
