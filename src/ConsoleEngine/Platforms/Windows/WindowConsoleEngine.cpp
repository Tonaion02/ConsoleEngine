#include "ConsoleEngine/Platforms/Windows/WindowConsoleEngine.h"

//Including some utils
#include "utils/StringAndFile/XMLvariab.h"
#include "utils/StringAndFile/MyString.h"
//Including some utils

#include "ConsoleEngine/Platforms/Windows/WindowsInputHandler.h"
#include "ConsoleEngine/Platforms/Windows/WindowsWindow.h"





//-----------------------------------------------------------------------------------------------------------------------------------------
//Class WindowConsoleEngine
//-----------------------------------------------------------------------------------------------------------------------------------------
WindowConsoleEngine::WindowConsoleEngine()
	:ConsoleEngine()
{
	//Take options from file
	std::string optionsFile = "data/options.xml";
	std::vector<std::string> lines = getLines(optionsFile);

	std::vector<XMLvariab> xmlVariables = getXMLvariables(lines);
	XMLvariab windowOptions = xmlVariables[0];
	std::string x = windowOptions.getValue("x");
	std::string y = windowOptions.getValue("y");
	std::string w = windowOptions.getValue("width");
	std::string h = windowOptions.getValue("heigth");
	std::string zoom = windowOptions.getValue("zoom");
	//Take options from file


	Vector2i dim = { std::stoi(w), std::stoi(h) };

	windowInstance = new WindowsWindow(dim);
	inputHandlerInstance = new WindowsInputHandler();
}
//-----------------------------------------------------------------------------------------------------------------------------------------
//Class WindowConsoleEngine
//-----------------------------------------------------------------------------------------------------------------------------------------