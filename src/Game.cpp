#include <cstdio>

#include <chrono>
#include <thread>

#include "Game.h"

//Including some utils
#include "utils/Math/Vector2f.h"

#include "utils/PersonalAssert.h"
//Including some utils

#include "ConsoleEngine/BaseConsoleEngine/ConsoleEngine.h"

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
	printf("Init enviroment and loading resources\n");
	ConsoleEngine::get();
}



void Game::generateOutput()
{
	std::string s = "";
	for (int y = 0; y < 35; y++)
	{
		for (int x = 0; x < 120; x++)
			s += "a";
	}



	//Some testing
	Surface surf1(forTest, {120, 35});
	Surface surf2(" cccc cccccc", {4, 3});
	
	//surf1.blit(surf2, {119, 2}, {1, 2});
	//surf1.blit(surf2, { 1, 2 });

	ConsoleEngine::get().window()->setCursorPos(Vector2i(0, 0));
	ConsoleEngine::get().window()->setColorBackground(Color(ColorId::black));
	ConsoleEngine::get().window()->setColorForeground(Color(ColorId::red));
	//ConsoleEngine::get().window()->blit(surf1, {0, 0}, surf1.getDim(), {0, 0});
	ConsoleEngine::get().window()->blit(surf2, { 0, 0 }, surf2.getDim(), { 0, 0 });
	ConsoleEngine::get().window()->draw();
	//Some testing
}



void Game::processInput()
{
	char c = ConsoleEngine::get().inputHandler()->command();
}
//-----------------------------------------------------------------------------------------------------------------------------------------
//Class Game
//-----------------------------------------------------------------------------------------------------------------------------------------