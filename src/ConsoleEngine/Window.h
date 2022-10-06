#pragma once

#include "utils/Math/Vector2i.h"
#include "DataStructures/Surface.h"

#include <string>





class Window
{
public:
	Window();

	virtual void create() = 0; //Create the window
	virtual void destroy() = 0; //Destroy the window
	//virtual void setColor() = 0; //Set color for writing
	virtual void write(const std::string& s) = 0; //Write direct on screen a string
	//virtual void write(const std::string& s, const Vector2i& pos) = 0; //Write direct on screen a string in a pos
	//virtual void blit(const Surface& surface) = 0; //
	//virtual void draw() = 0; //Draw the screen buffer
	virtual void setCursorPos(const Vector2i& pos) = 0; //Set position of cursor
protected:
	Surface screenBuffer;
};