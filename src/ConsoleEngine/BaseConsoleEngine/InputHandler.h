#pragma once





class InputHandler
{
public:
	//InputHandler() {}

	virtual char command() = 0;
	virtual void cleanBuffer() = 0;
};