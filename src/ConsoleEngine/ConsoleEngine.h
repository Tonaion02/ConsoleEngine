#pragma once

#include <string>





class ConsoleEngine
{
public:
	static ConsoleEngine& get();
	
	virtual void write(const std::string& string) = 0;
	virtual void setCursorPos(int x, int y) = 0;
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
	ConsoleEngine()
	{}

protected:
	/*
	class Window* window;
	class InputHandler* inputHandler;
	 */
};