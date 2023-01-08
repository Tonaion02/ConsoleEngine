#include "ConsoleEngine/Platforms/Windows/WindowsInputHandler.h"

//Including for retrieve input
#include <conio.h>
#include <iostream>
//Including for retrieve input

#include "ConsoleEngine/BaseConsoleEngine/ConsoleEngine.h"
#include "ConsoleEngine/BaseConsoleEngine/Window.h"





//-----------------------------------------------------------------------------------------------------------------------------------------
//Class WindowsInputHandler
//-----------------------------------------------------------------------------------------------------------------------------------------
char WindowsInputHandler::command()
{
	char input = 0;

	if (_kbhit())
	{
		input = _getch();
		//#for testing
		std::string s = "";
		s.push_back(input);
		ConsoleEngine::get().window()->setCursorPos({0, 36});
		ConsoleEngine::get().window()->write(s);
		ConsoleEngine::get().window()->setCursorPos({ 0, 0 });
		//#for testing
	}

	return input;
}



void WindowsInputHandler::cleanBuffer()
{

}
//-----------------------------------------------------------------------------------------------------------------------------------------
//Class WindowsInputHandler
//-----------------------------------------------------------------------------------------------------------------------------------------