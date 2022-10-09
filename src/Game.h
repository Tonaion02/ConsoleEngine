#pragma once

#include <string>





class Game
{
public:
	Game();

	void run();
	
	static class Game* get();

	bool isRunning();
private:
	void init();
	void update();
	void generateOutput();
	void processInput();
	
private:
	bool running;
	std::string forTest;
	
	static Game* instance;
};