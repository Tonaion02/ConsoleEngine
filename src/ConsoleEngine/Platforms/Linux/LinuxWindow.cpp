#include <cstdlib>
#include <unistd.h>
#include <cstdio>
#include <cstring>

#include "ConsoleEngine/Platforms/Linux/LinuxWindow.h"





//-----------------------------------------------------------------------------------------------------------------------------------------
//Class LinuxWindow
//-----------------------------------------------------------------------------------------------------------------------------------------
LinuxWindow::LinuxWindow()
	:Window()
{
	this->create();
}


void LinuxWindow::create()
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
        execlp( "gnome-terminal", "gnome-terminal", "--geometry=120x60+10+10" ,"--zoom=0.7", "-x","tail","-f","/tmp/asdf.log", pidarg, NULL );

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



void LinuxWindow::destroy()
{
	
}



void LinuxWindow::setColorBackground(const Color& color)
{
	this->background = color;
	int bg = this->background.bgLinux();
	int fg = this->foreground.fgLinux();
	printf("\033[%d;%dm",  this->background.bgLinux(), this->foreground.fgLinux());
}



void LinuxWindow::setColorForeground(const Color& color)
{
	this->foreground = color;
	printf("\033[%d;%dm",  this->background.bgLinux(), this->foreground.fgLinux());
}



void LinuxWindow::write(const std::string& s)
{
	printf("%s", s.c_str());	
}



void LinuxWindow::setCursorPos(const Vector2i& pos) 
{
	printf("\033[%d;%dH", pos.x, pos.y);
}
//-----------------------------------------------------------------------------------------------------------------------------------------
//Class LinuxWindow
//-----------------------------------------------------------------------------------------------------------------------------------------