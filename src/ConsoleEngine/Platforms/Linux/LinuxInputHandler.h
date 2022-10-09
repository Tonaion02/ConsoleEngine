#pragma once

#include <thread>

#include "ConsoleEngine/BaseConsoleEngine/InputHandler.h"





class LinuxInputHandler : public InputHandler
{
public:
	virtual char command() override;
	virtual void cleanBuffer() override;
	
private:
	int kbhit(void);
};