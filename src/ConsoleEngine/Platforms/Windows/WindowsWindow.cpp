#include "ConsoleEngine/Platforms/Windows/WindowsWindow.h"

#include <cstdio>





//-----------------------------------------------------------------------------------------------------------------------------------------
//Class WindowsWindow
//-----------------------------------------------------------------------------------------------------------------------------------------
WindowsWindow::WindowsWindow(const Vector2i& dim)
	:Window(dim), handleWindow(GetStdHandle(STD_OUTPUT_HANDLE))
{
	this->create();
}



void WindowsWindow::create()
{
	//Create the window
	COORD sizeWindow = { static_cast<SHORT>(dim.x), static_cast<SHORT>(dim.y) };
	SMALL_RECT* rect = new SMALL_RECT();
	rect->Top = 0;
	rect->Left = 0;
	rect->Right = sizeWindow.X - 1;
	rect->Bottom = sizeWindow.Y - 1;
	int result = SetConsoleWindowInfo(handleWindow, true, rect);
	//Create the window

	this->setCursorVisibility(false);
}



void WindowsWindow::destroy()
{
}



void WindowsWindow::write(const std::string& s)
{
	WriteConsoleA(handleWindow, (void*)s.c_str(), static_cast<DWORD>(s.size()), nullptr, nullptr);
}



void WindowsWindow::setCursorPos(const Vector2i& pos)
{
	COORD p = { static_cast<SHORT>(pos.x), static_cast<SHORT>(pos.y) };
	SetConsoleCursorPosition(handleWindow, p);
}



void WindowsWindow::setCursorVisibility(bool visible)
{
	CONSOLE_CURSOR_INFO c;
	GetConsoleCursorInfo(handleWindow, &c);

	c.bVisible = visible;

	SetConsoleCursorInfo(handleWindow, &c);
}
//-----------------------------------------------------------------------------------------------------------------------------------------
//Class WindowsWindow
//-----------------------------------------------------------------------------------------------------------------------------------------