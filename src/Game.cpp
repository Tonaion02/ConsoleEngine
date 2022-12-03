#include <cstdio>

#include <chrono>
#include <thread>

#include "Game.h"
#include "ConsoleEngine/BaseConsoleEngine/ConsoleEngine.h"

#include "utils/PersonalAssert.h"

#include "ConsoleEngine/DataStructures/Surface.h"

#include "ConsoleEngine/BaseConsoleEngine/Window.h"
#include "ConsoleEngine/BaseConsoleEngine/InputHandler.h"

#include "utils/Math/Vector2f.h"





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
	Vector2i v;
	Vector2f vf = v;

	printf("Init enviroment and loading resources\n");
	ConsoleEngine::get();
}



void Game::generateOutput()
{
	//Some testing
	Surface surf1(forTest);
	Surface surf2(" ccc\nc cc\ncccc\n");
	
	//surf1.blit(surf2, {119, 2}, {1, 2});
	surf1.blit(surf2, {1, 2});

	ConsoleEngine::get().window()->setCursorPos(Vector2i(0, 0));
	ConsoleEngine::get().window()->setColorBackground(Color(ColorId::black));
	ConsoleEngine::get().window()->setColorForeground(Color(ColorId::red));
	ConsoleEngine::get().window()->blit(surf1, {0, 0}, surf1.getDim(), {0, 0});
	ConsoleEngine::get().window()->draw();
	//Some testing
}



void Game::processInput()
{
	
}
//-----------------------------------------------------------------------------------------------------------------------------------------
//Class Game
//-----------------------------------------------------------------------------------------------------------------------------------------