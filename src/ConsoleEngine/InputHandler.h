#pragma once





class InputHandler
{
public:
	virtual char command() = 0;
	virtual void cleanBuffer() = 0;
};