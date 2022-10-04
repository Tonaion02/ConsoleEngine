#include <cstdlib>
#include <unistd.h>
#include <cstdio>
#include <cstring>

#include "ConsoleEngine/Platforms/LinuxConsoleEngine.h"





//-----------------------------------------------------------------------------------------------------------------------------------------
//Class LinuxConsoleEngine
//-----------------------------------------------------------------------------------------------------------------------------------------
	//printf("\033[7;31mbold red text\n");
	//printf("\033[%d;%dH", 1, 1);



LinuxConsoleEngine::LinuxConsoleEngine()
{
    char  pidarg[256]; // the '--pid=' argument of tail
    pid_t child;       // the pid of the child proc
    pid_t parent;      // the pid of the parent proc
    FILE* fp;          // file to which output is redirected
    int   fn;          // file no of fp

    // Open file for redirection
    fp = fopen("/tmp/asdf.log","w");
    fn = fileno(fp);

    // Get pid of current process and create string with argument for tail
    parent = getpid();
    sprintf( pidarg, "--pid=%d", parent );

    // Create child process
    child = fork(); 
    if( child == 0 ) {
        // CHILD PROCESS

        // Replace child process with a gnome-terminal running:
        //      tail -f /tmp/asdf.log --pid=<parent_pid>
        // This prints the lines outputed in asdf.log and exits when
        // the parent process dies.
        execlp( "gnome-terminal", "gnome-terminal", "--geometry=120x60+10+10" ,"-x","tail","-f","/tmp/asdf.log", pidarg, NULL );

        // if there's an error, print out the message and exit
        perror("execlp()");
        exit( -1 );
    } else {
        // PARENT PROCESS
        close(1);      // close stdout
        int ok = dup2( fn, 1 ); // replace stdout with the file

        if( ok != 1 ) {
            perror("dup2()");
			exit(-1);
		}

        // Make stdout flush on newline, doesn't happen by default
        // since stdout is actually a file at this point.
        setvbuf( stdout, NULL, _IONBF, BUFSIZ );
    }
}



void LinuxConsoleEngine::write(const std::string& string)
{
	printf("\033[7;31m%s", string.c_str());	
}



void LinuxConsoleEngine::setCursorPos(int x, int y)
{
	printf("\033[%d;%dH", x, y);
}
//-----------------------------------------------------------------------------------------------------------------------------------------
//Class LinuxConsoleEngine
//-----------------------------------------------------------------------------------------------------------------------------------------