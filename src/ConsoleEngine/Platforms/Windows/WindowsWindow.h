#include <Windows.h>

#include "ConsoleEngine/BaseConsoleEngine/Window.h"





class WindowsWindow : public Window
{
public:
	WindowsWindow();
	
	virtual void create() override; //Create the window
	virtual void destroy() override; //Destroy the window
	virtual void write(const std::string& s) override; //Write direct on screen a string
	virtual void setCursorPos(const Vector2i& pos) override; //Set position of cursor

protected:
	HANDLE handleWindow;
};