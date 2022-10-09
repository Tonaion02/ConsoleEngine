#pragma once

#include <string>

#include "utils/Math/Vector2i.h"
#include "ConsoleEngine/DataStructures/Surface.h"
#include "ConsoleEngine/DataStructures/Color.h"





class Window
{
public:
	Window();

	//Create the window
	virtual void create() = 0;
	//Destroy the window
	virtual void destroy() = 0;
	//Set color for background
	virtual void setColorBackground(const Color& color) = 0;
	//Set color for foreground
	virtual void setColorForeground(const Color& color) = 0;
	//Write direct on screen a string
	virtual void write(const std::string& s) = 0;
	//Set position of cursor
	virtual void setCursorPos(const Vector2i& pos) = 0;
	//virtual void write(const std::string& s, const Vector2i& pos) = 0; //Write direct on screen a string in a pos
	//virtual void blit(const Surface& surface) = 0; //
	//virtual void draw() = 0; //Draw the screen buffer
protected:
	Surface screenBuffer;
	Color background, foreground;
};