#include "ConsoleEngine/BaseConsoleEngine/ConsoleEngine.h"

#include "utils/StringAndFile/MyString.h"
#include "utils/StringAndFile/XMLvariab.h"

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



ConsoleEngine::ConsoleEngine() 
{
	//std::vector<std::string> lines = getLines("data/options.xml");
	//std::vector<XMLvariab> xmlVariables = getXMLvariables(lines);
	//XMLvariab windowOptions = xmlVariables[0];
	//dimWindow = Vector2i(stoi(windowOptions.getValue("width")), 
	//			   stoi(windowOptions.getValue("heigth"))-1);
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