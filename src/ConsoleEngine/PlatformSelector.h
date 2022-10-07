#pragma once





#ifdef WINDOWS
#define newConsoleEngine() new WindowConsoleEngine()
#endif

#ifdef LINUX
#define newConsoleEngine() new LinuxConsoleEngine()
#endif