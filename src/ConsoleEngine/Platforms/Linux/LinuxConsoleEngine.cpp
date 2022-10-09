#include "ConsoleEngine/Platforms/Linux/LinuxWindow.h"
#include "ConsoleEngine/Platforms/Linux/LinuxInputHandler.h"

#include "ConsoleEngine/Platforms/Linux/LinuxConsoleEngine.h"





//-----------------------------------------------------------------------------------------------------------------------------------------
//Class LinuxConsoleEngine
//-----------------------------------------------------------------------------------------------------------------------------------------
LinuxConsoleEngine::LinuxConsoleEngine()
{
	this->windowInstance = new LinuxWindow();
	this->inputHandlerInstance = new LinuxInputHandler();
}
//-----------------------------------------------------------------------------------------------------------------------------------------
//Class LinuxConsoleEngine
//-----------------------------------------------------------------------------------------------------------------------------------------