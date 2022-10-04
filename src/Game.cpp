#include <cstdio>

#include <chrono>
#include <thread>


#include "Game.h"
#include "ConsoleEngine/ConsoleEngine.h"





//-----------------------------------------------------------------------------------------------------------------------------------------
//Class Game
//-----------------------------------------------------------------------------------------------------------------------------------------
Game::Game()
	:isRunning(true)
{
	for(int y = 0; y < 35; y++)
	{
		for(int x = 0; x < 120; x++)
			forTest.push_back('w');
		forTest.push_back('\n');
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
	ConsoleEngine::get().setCursorPos(0, 0);
	ConsoleEngine::get().write(forTest);
}



void Game::processInput()
{
	
}
//-----------------------------------------------------------------------------------------------------------------------------------------
//Class Game
//-----------------------------------------------------------------------------------------------------------------------------------------