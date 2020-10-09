#pragma once
#include <string>
#include <atomic>
#include <thread>
#include <stdio.h>

class AIModule;

class DebugConsole
{
public:
	DebugConsole(AIModule* aiModule);
	~DebugConsole();

private:
	void Enable();
	bool IsEnabled();
	void Run();
	void ProcessUserCommand(std::string const& command);
	void Disable();
	void Unblock();

	AIModule* aiModule;
	std::atomic<bool> isEnabled;
	std::unique_ptr<std::thread> inputThread;

	int savedInputFileHandle;
	int savedOutputFileHandle;
	FILE *input;
	FILE *output;
};
