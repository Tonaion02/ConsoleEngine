#include <cstdio>

#include <chrono>
#include <thread>

#include "Game.h"
#include "ConsoleEngine/BaseConsoleEngine/ConsoleEngine.h"

#include "utils/PersonalAssert.h"

#include "ConsoleEngine/DataStructures/Surface.h"

#include "ConsoleEngine/BaseConsoleEngine/Window.h"
#include "ConsoleEngine/BaseConsoleEngine/InputHandler.h"





//-----------------------------------------------------------------------------------------------------------------------------------------
//Class Game
//-----------------------------------------------------------------------------------------------------------------------------------------
Game* Game::instance = nullptr;



Game::Game()
	:running(true)
{
	instance = this;
	
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
	
	while(running)
	{
		processInput();
		update();
		generateOutput();
		std::this_thread::sleep_for(std::chrono::milliseconds(40));
	}
}



class Game* Game::get()
{
	return instance;
}



bool Game::isRunning()
{
	return running;
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
	
	//surf1.blit(surf2, {119, 2}, {1, 1});
	surf2.blit(surf1);

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