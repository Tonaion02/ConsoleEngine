#pragma once

//#include "utils/Math/Vector2i.h"
#include "utils/Math/Vector2.h"
#include "ConsoleEngine/BaseConsoleEngine/Window.h"





class LinuxWindow : public Window
{
public:
	LinuxWindow(const Vector2i& dim);
	
	virtual void create() override;
	virtual void destroy() override;
	virtual void write(const std::string& s) override;
	virtual void setColorBackground(const Color& color) override;
	virtual void setColorForeground(const Color& color) override;
	virtual void setCursorPos(const Vector2i& pos) override;
	//virtual void blit(const Surface& toBlit, const Vector2i& pos, const Vector2i& dimToBlit, const Vector2i& posToBlit) override; 
	//virtual void draw() override;
	
private:
};