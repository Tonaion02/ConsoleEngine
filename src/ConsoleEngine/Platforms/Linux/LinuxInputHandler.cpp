#include <cstdio>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

#include "Game.h"
#include "ConsoleEngine/Platforms/Linux/LinuxInputHandler.h"





//-----------------------------------------------------------------------------------------------------------------------------------------
//Class LinuxInputHandler
//-----------------------------------------------------------------------------------------------------------------------------------------
int LinuxInputHandler::kbhit(void)
{
	struct termios oldt, newt;
	int ch;
	int oldf;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

	ch = getchar();

	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);

	if(ch != EOF)
	{
		ungetc(ch, stdin);
		return 1;
	}

	return 0;
}



char LinuxInputHandler::command()
{
	if(kbhit() == 1)
		return getchar();
	return '\0';
}



void LinuxInputHandler::cleanBuffer()
{

}
//-----------------------------------------------------------------------------------------------------------------------------------------
//Class LinuxInputHandler
//-----------------------------------------------------------------------------------------------------------------------------------------