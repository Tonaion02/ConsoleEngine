#include "ConsoleEngine/BaseConsoleEngine/Window.h"





//-----------------------------------------------------------------------------------------------------------------------------------------
//Class Window
//-----------------------------------------------------------------------------------------------------------------------------------------
Window::Window(const Vector2i& dim)
	:screenBuffer(Surface(dim)), dim(dim)
{

}



void Window::blit(const Surface& toBlit, const Vector2i& pos, const Vector2i& dimToBlit, const Vector2i& posToBlit)
{
	screenBuffer.blit(toBlit, pos, dimToBlit, posToBlit);
}



void Window::draw()
{
	this->write(screenBuffer.raw());
}
//-----------------------------------------------------------------------------------------------------------------------------------------
//Class Window
//-----------------------------------------------------------------------------------------------------------------------------------------