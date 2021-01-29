#include "RPCServer.h"
#include "AIModule.h"

#include "misc/Configuration.h"
#include "protos/ai_module_api.grpc.pb.h"

RPCServer::RPCServer(AIModule* aiModule) :
	aiModule(aiModule),
	assignedServerPort(-1)
{
	server = BuildAndStart(aimodule_conf::RPC_SERVER_ADDRESS, assignedServerPort);
	if (!server)
	{
		std::cout << "[RPC Server] Warning: failed to bind to " << aimodule_conf::RPC_SERVER_ADDRESS << "." << std::endl;
		server = BuildAndStart("0.0.0.0:0", assignedServerPort);
	}
	
	if (server)
	{
		serverThread = std::make_unique<std::thread>(&RPCServer::ServerThread, this);
		std::cout << "[RPC Server] Listening on port " << assignedServerPort << "." << std::endl;
	}
	else
	{
		std::cout << "[RPC Server] Error: failed to start, RPC calls won't be available" << "." << std::endl;
	}
}

std::unique_ptr<grpc::Server> RPCServer::BuildAndStart(const std::string& uri, int& assignedServerPort)
{
	grpc::ServerBuilder builder;
	builder.AddListeningPort(uri, grpc::InsecureServerCredentials(), &assignedServerPort);
	builder.RegisterService(aiModule->GetService());
	builder.RegisterService(aiModule->GetExpert()->GetService());

	return builder.BuildAndStart();
}

void RPCServer::ServerThread()
{
	server->Wait();
}

RPCServer::~RPCServer()
{
	// don't accept any new RPC calls and wait for existing to finish or timeout
	if (server)
	{
		server->Shutdown();
		serverThread->join();
	}
}
