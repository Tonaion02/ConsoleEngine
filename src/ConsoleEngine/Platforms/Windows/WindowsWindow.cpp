#include "ConsoleEngine/Platforms/Windows/WindowsWindow.h"

#include <cstdio>





//-----------------------------------------------------------------------------------------------------------------------------------------
//Class WindowsWindow
//-----------------------------------------------------------------------------------------------------------------------------------------
WindowsWindow::WindowsWindow()
	:Window(), handleWindow(GetStdHandle(STD_OUTPUT_HANDLE))
{
	this->create();
}



void WindowsWindow::create()
{
	COORD sizeWindow = { 120, 60 };
	SMALL_RECT* rect = new SMALL_RECT();
	rect->Top = 0;
	rect->Left = 0;
	rect->Right = sizeWindow.X - 1;
	rect->Bottom = sizeWindow.Y - 1;
	int result = SetConsoleWindowInfo(handleWindow, true, rect);
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