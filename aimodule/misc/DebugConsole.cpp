#include "DebugConsole.h"

#include <iostream>
#include <io.h>

#include "misc/Statics.h"
#include "misc/MemoryUtils.h"
#include "structs/Game.h"

#include "AIModule.h"


DebugConsole::DebugConsole(AIModule* aiModule) :
	aiModule(aiModule),
	isEnabled(false)
{
	Enable();
}

void DebugConsole::Enable()
{
	if (!IsEnabled())
	{
		// save old stdin and stdout values
		savedInputFileHandle = _dup(0);
		savedOutputFileHandle = _dup(1);
		
		// create a console and redirect stdin and stdout to it
		AllocConsole();
		UpdateTitle();
		freopen_s(&input, "CONIN$", "r", stdin);
		freopen_s(&output, "CONOUT$", "w", stdout);

		// start listening to user input in a separate thread
		isEnabled = true;
		inputThread = std::make_unique<std::thread>(&DebugConsole::Run, this);

		std::cout << "[Console] Enabled." << std::endl;
	}
}

void DebugConsole::UpdateTitle()
{
	std::wstring title = L"AoE2 AI Module " + aimodule_conf::VERSION;
	SetConsoleTitle(title.c_str());
}

bool DebugConsole::IsEnabled()
{
	return isEnabled.load();
}

void DebugConsole::Run()
{
	while (IsEnabled())
	{
		std::string command;
		std::getline(std::cin, command);

		ProcessUserCommand(command);
	}
}

void DebugConsole::ProcessUserCommand(const std::string& command)
{
	if (IsEnabled())
	{
		if (command == "unload")
		{
			aiModule->RequestUnload();
			std::cout << "[AI Module] Requested unload." << std::endl;
		}
		else if (command == "test")
		{

		}
	}
}

DebugConsole::~DebugConsole()
{
	Disable();
}

void DebugConsole::Disable()
{
	if (IsEnabled())
	{
		// unblock the input listening thread
		isEnabled = false;
		Unblock();
		inputThread->join();

		// close streams and console
		fflush(stdin);
		fclose(stdin);
		fflush(stdout);
		fclose(stdout);
		FreeConsole();

		// restore saved stdin and stdout values
		_dup2(savedInputFileHandle, 0);
		_dup2(savedOutputFileHandle, 1);
	}
}

void DebugConsole::Unblock()
{
	// hack from https://stackoverflow.com/a/31721867/11467123
	// to make std::getline return

	DWORD dwTmp;
	INPUT_RECORD ir[2];
	ir[0].EventType = KEY_EVENT;
	ir[0].Event.KeyEvent.bKeyDown = TRUE;
	ir[0].Event.KeyEvent.dwControlKeyState = 0;
	ir[0].Event.KeyEvent.uChar.UnicodeChar = VK_RETURN;
	ir[0].Event.KeyEvent.wRepeatCount = 1;
	ir[0].Event.KeyEvent.wVirtualKeyCode = VK_RETURN;
	ir[0].Event.KeyEvent.wVirtualScanCode = MapVirtualKey(VK_RETURN, MAPVK_VK_TO_VSC);
	ir[1] = ir[0];
	ir[1].Event.KeyEvent.bKeyDown = FALSE;
	WriteConsoleInput(GetStdHandle(STD_INPUT_HANDLE), ir, 2, &dwTmp);
}
