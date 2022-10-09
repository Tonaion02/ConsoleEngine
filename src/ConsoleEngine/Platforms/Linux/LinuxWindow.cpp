#include <cstdlib>
//#include <unistd.h>
#include <cstdio>
#include <cstring>

#include "ConsoleEngine/Platforms/Linux/LinuxWindow.h"





//-----------------------------------------------------------------------------------------------------------------------------------------
//Class LinuxWindow
//-----------------------------------------------------------------------------------------------------------------------------------------
LinuxWindow::LinuxWindow()
	:Window()
{
	this->create();
}


void LinuxWindow::create()
{
	
}



void LinuxWindow::destroy()
{
	
}



void LinuxWindow::setColorBackground(const Color& color)
{
	this->background = color;
	int bg = this->background.bgLinux();
	int fg = this->foreground.fgLinux();
	printf("\033[%d;%dm",  this->background.bgLinux(), this->foreground.fgLinux());
}



void LinuxWindow::setColorForeground(const Color& color)
{
	this->foreground = color;
	printf("\033[%d;%dm",  this->background.bgLinux(), this->foreground.fgLinux());
}



void LinuxWindow::write(const std::string& s)
{
	printf("%s", s.c_str());	
}



void LinuxWindow::setCursorPos(const Vector2i& pos) 
{
	printf("\033[%d;%dH", pos.y, pos.x);
}
//-----------------------------------------------------------------------------------------------------------------------------------------
//Class LinuxWindow
//-----------------------------------------------------------------------------------------------------------------------------------------