#pragma once





class ConsoleEngine
{
public:
	static ConsoleEngine& get();

	virtual int exampleMethod() = 0;

protected:
	ConsoleEngine()
		:forTest(0)
	{}

protected:
	int forTest;
};