#pragma once


//To use Linux version(TEMPORARY)
//#undef WINDOWS
//#define LINUX


#ifdef WINDOWS
#define newConsoleEngine() new WindowConsoleEngine()
#endif

#ifdef LINUX
#define newConsoleEngine() new LinuxConsoleEngine()
#endif