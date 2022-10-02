#include "ConsoleEngine/ConsoleEngine.h"

#include "ConsoleEngine/PlatformSelector.h"
#include "ConsoleEngine/Platforms/WindowConsoleEngine.h"
#include "ConsoleEngine/Platforms/LinuxConsoleEngine.h"





//-----------------------------------------------------------------------------------------------------------------------------------------
//Class ConsoleEngine
//-----------------------------------------------------------------------------------------------------------------------------------------
ConsoleEngine& ConsoleEngine::get()
{
	static ConsoleEngine* instance = newConsoleEngine();
	return *instance;
}
//-----------------------------------------------------------------------------------------------------------------------------------------
//Class ConsoleEngine
//-----------------------------------------------------------------------------------------------------------------------------------------