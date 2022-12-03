#include "ConsoleEngine/Platforms/Linux/LinuxWindow.h"
#include "ConsoleEngine/Platforms/Linux/LinuxInputHandler.h"

#include "ConsoleEngine/Platforms/Linux/LinuxConsoleEngine.h"





//-----------------------------------------------------------------------------------------------------------------------------------------
//Class LinuxConsoleEngine
//-----------------------------------------------------------------------------------------------------------------------------------------
LinuxConsoleEngine::LinuxConsoleEngine()
	:ConsoleEngine()
{
	this->windowInstance = new LinuxWindow(this->dimWindow);
	this->inputHandlerInstance = new LinuxInputHandler();
}
//-----------------------------------------------------------------------------------------------------------------------------------------
//Class LinuxConsoleEngine
//-----------------------------------------------------------------------------------------------------------------------------------------