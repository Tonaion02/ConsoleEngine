#pragma once

#include "ConsoleEngine/BaseConsoleEngine/Window.h"





class LinuxWindow : public Window
{
public:
	LinuxWindow();
	
	virtual void create() override;
	virtual void destroy() override;
	virtual void write(const std::string& s) override;
	virtual void setCursorPos(const Vector2i& pos) override;
	
private:
	
};