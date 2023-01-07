#include "ConsoleEngine/Platforms/Windows/WindowsWindow.h"

//Including some utils
#include "utils/StringAndFile/XMLvariab.h"
#include "utils/StringAndFile/MyString.h"
//Including some utils

#include <cstdio>





//-----------------------------------------------------------------------------------------------------------------------------------------
//Class WindowsWindow
//-----------------------------------------------------------------------------------------------------------------------------------------
WindowsWindow::WindowsWindow()
	:Window(dim), handleWindow(GetStdHandle(STD_OUTPUT_HANDLE))
{
	this->create();
}



void WindowsWindow::create()
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


	dim = { std::stoi(w), std::stoi(h) };

	//Create the window
	COORD sizeWindow = { dim.x, dim.y };
	SMALL_RECT* rect = new SMALL_RECT();
	rect->Top = 0;
	rect->Left = 0;
	rect->Right = sizeWindow.X - 1;
	rect->Bottom = sizeWindow.Y - 1;
	int result = SetConsoleWindowInfo(handleWindow, true, rect);
	//Create the window
}



void WindowsWindow::destroy()
{
}



void WindowsWindow::write(const std::string& s)
{
	printf("%s", s.c_str());
}



void WindowsWindow::setCursorPos(const Vector2i& pos)
{
	COORD p = { pos.x, pos.y };
	SetConsoleCursorPosition(handleWindow, p);
}
//-----------------------------------------------------------------------------------------------------------------------------------------
//Class WindowsWindow
//-----------------------------------------------------------------------------------------------------------------------------------------