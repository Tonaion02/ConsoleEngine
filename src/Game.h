#pragma once

#include <string>





class Game
{
public:
	Game();

	void run();
	
	class Game* get();
	
private:
	void init();
	void update();
	void generateOutput();
	void processInput();
	
private:
	bool isRunning;
	std::string forTest;
};