#include <cstdio>

#include <chrono>
#include <thread>


#include "utils/PersonalAssert.h"

#include "ConsoleEngine/DataStructures/Surface.h"

#include "ConsoleEngine/BaseConsoleEngine/Window.h"
#include "ConsoleEngine/Platforms/Linux/LinuxWindow.h"

#include "Game.h"
#include "ConsoleEngine/BaseConsoleEngine/ConsoleEngine.h"





//-----------------------------------------------------------------------------------------------------------------------------------------
//Class Game
//-----------------------------------------------------------------------------------------------------------------------------------------
Game::Game()
	:isRunning(true)
{
	for(int y=0;y<35;y++)
	{
		for(int x=0;x<120;x++)
			forTest += "a";
		forTest += "\n";
	}
}



void Game::run()
{
	init();
	
	while(isRunning)
	{
		processInput();
		update();
		generateOutput();
		std::this_thread::sleep_for(std::chrono::milliseconds(16));
	}
}



class Game* Game::get()
{
	return this;
}



void Game::update()
{
	
}



void Game::init()
{
	printf("Init enviroment and loading resources");
	ConsoleEngine::get();
}



void Game::generateOutput()
{
	Surface surf1(forTest);
	Surface surf2("cccc\ncccc\ncccc\n");
	
	surf1.blit(surf2, {2, 1}, {2, 2});
	
	ConsoleEngine::get().window()->setCursorPos(Vector2i(0, 0));
	ConsoleEngine::get().window()->setColorBackground(Color(ColorId::black));
	ConsoleEngine::get().window()->setColorForeground(Color(ColorId::red));
	ConsoleEngine::get().window()->write(surf1.getData());
}



void Game::processInput()
{
	
}
//-----------------------------------------------------------------------------------------------------------------------------------------
//Class Game
//-----------------------------------------------------------------------------------------------------------------------------------------