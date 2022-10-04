#pragma once

#include "ConsoleEngine/ConsoleEngine.h"





class LinuxConsoleEngine : public ConsoleEngine
{
public:
	LinuxConsoleEngine();
	
	virtual void write(const std::string& string) override;
	virtual void setCursorPos(int x, int y) override;
};