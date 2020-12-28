#pragma once
#include <memory>
#include <thread>

#include <Windows.h>
#include <grpcpp/grpcpp.h>

class AIModule;

class RPCServer
{
public:
	RPCServer(AIModule* aiModule);
	~RPCServer();

private:
	void ServerThread();

	AIModule* aiModule;
	std::unique_ptr<grpc::Server> server;
	std::unique_ptr<std::thread> serverThread;
	int assignedServerPort;
};
