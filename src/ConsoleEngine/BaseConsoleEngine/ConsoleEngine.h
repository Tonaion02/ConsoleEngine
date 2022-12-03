#pragma once

#include <string>

#include "utils/Math/Vector2i.h"





class ConsoleEngine
{
public:
	static ConsoleEngine& get();
	
	class Window* window();
	class InputHandler* inputHandler();
	/*
	//Window methods
	virtual void createWindow() = 0;
	virtual void destroyWindow() = 0;
	virtual void draw() = 0;
	virtual void resetCursor() = 0;
	virtual void clear() = 0;
	
	//InputHandler methods
	virtual void createInputHandler() = 0;
	virtual void command();
	*/
protected:
	ConsoleEngine();

protected:
	class Window* windowInstance;
	class InputHandler* inputHandlerInstance;
	Vector2i dimWindow;
};