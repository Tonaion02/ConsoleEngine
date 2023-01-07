#pragma once

#include <string>

#include "utils/Math/Vector2.h"
#include "ConsoleEngine/DataStructures/Surface.h"
#include "ConsoleEngine/DataStructures/Color.h"





class Window
{
public:
	Window(const Vector2i& dim);

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
	
	//Draw on screen buffer surface another surface
	virtual void blit(const Surface& toBlit, const Vector2i& pos, const Vector2i& dimToBlit, const Vector2i& posToBlit) = 0; 
	//Draw the screen buffer
	virtual void draw() = 0;
protected:
	Surface screenBuffer;
	Color background, foreground;
	Vector2i dim;
};