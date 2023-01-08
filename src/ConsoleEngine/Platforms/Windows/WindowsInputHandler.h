#pragma once

#include "ConsoleEngine/BaseConsoleEngine/InputHandler.h"





class WindowsInputHandler : public InputHandler
{
public:
	virtual char command() override;
	virtual void cleanBuffer() override;
};