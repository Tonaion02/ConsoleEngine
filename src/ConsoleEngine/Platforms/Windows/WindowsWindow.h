#include <Windows.h>

#include "ConsoleEngine/BaseConsoleEngine/Window.h"





class WindowsWindow : public Window
{
public:
	WindowsWindow(const Vector2i& dim);
	
	virtual void create() override; //Create the window
	virtual void destroy() override; //Destroy the window
	virtual void write(const std::string& s) override; //Write direct on screen a string
	virtual void setCursorPos(const Vector2i& pos) override; //Set position of cursor

	//Set color for background
	virtual void setColorBackground(const Color& color) {};
	//Set color for foreground
	virtual void setColorForeground(const Color& color) {};

	//Set visibility of the cursor of console
	void setCursorVisibility(bool visible);

	////Draw on screen buffer surface another surface
	//virtual void blit(const Surface& toBlit, const Vector2i& pos, const Vector2i& dimToBlit, const Vector2i& posToBlit);
	////Draw the screen buffer
	//virtual void draw();

protected:
	HANDLE handleWindow;
};