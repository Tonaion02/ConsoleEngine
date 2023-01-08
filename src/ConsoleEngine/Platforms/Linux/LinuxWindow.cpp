#include <cstdlib>
#include <cstdio>
#include <cstring>

#include "ConsoleEngine/Platforms/Linux/LinuxWindow.h"





//-----------------------------------------------------------------------------------------------------------------------------------------
//Class LinuxWindow
//-----------------------------------------------------------------------------------------------------------------------------------------
LinuxWindow::LinuxWindow(const Vector2i& dim)
	:Window(dim)
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
	//int bg = this->background.bgLinux();
	//int fg = this->foreground.fgLinux();
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



//void LinuxWindow::blit(const Surface& toBlit, const Vector2i& pos, const Vector2i& dimToBlit, const Vector2i& posToBlit)
//{
//	screenBuffer.blit(toBlit, pos, dimToBlit, posToBlit);
//} 
//
//
//
//void LinuxWindow::draw()
//{
//	this->write(screenBuffer.raw());
//}
//-----------------------------------------------------------------------------------------------------------------------------------------
//Class LinuxWindow
//-----------------------------------------------------------------------------------------------------------------------------------------