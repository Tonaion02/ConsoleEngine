#include "ConsoleEngine/BaseConsoleEngine/ConsoleEngine.h"

#include "ConsoleEngine/PlatformSelector.h"
#include "ConsoleEngine/Platforms/Windows/WindowConsoleEngine.h"
#include "ConsoleEngine/Platforms/Linux/LinuxConsoleEngine.h"





//-----------------------------------------------------------------------------------------------------------------------------------------
//Class ConsoleEngine
//-----------------------------------------------------------------------------------------------------------------------------------------
ConsoleEngine& ConsoleEngine::get()
{
	static ConsoleEngine* instance = newConsoleEngine();
	return *instance;
}



Window* ConsoleEngine::window()
{
	return windowInstance;
}



InputHandler* ConsoleEngine::inputHandler()
{
	return inputHandlerInstance;
}
//-----------------------------------------------------------------------------------------------------------------------------------------
//Class ConsoleEngine
//-----------------------------------------------------------------------------------------------------------------------------------------