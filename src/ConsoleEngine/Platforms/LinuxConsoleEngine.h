#pragma once

#include "ConsoleEngine/ConsoleEngine.h"





class LinuxConsoleEngine : public ConsoleEngine
{
public:
	LinuxConsoleEngine();

	virtual int exampleMethod() override;
};