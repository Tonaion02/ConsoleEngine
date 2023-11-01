#pragma once

#ifdef WINDOWS
#include "ConsoleEngine/Platforms/Windows/WindowConsoleEngine.h"
#include "ConsoleEngine/Platforms/Windows/WindowsWindow.h"
#include "ConsoleEngine/Platforms/Windows/WindowsInputHandler.h"
#endif

#ifdef LINUX
#include "ConsoleEngine/Platforms/Linux/LinuxConsoleEngine.h"
#include "ConsoleEngine/Platforms/Linux/LinuxWindow.h"
#include "ConsoleEngine/Platforms/Linux/LinuxInputHandler.h"
#endif

//#include "General/Camera.h"
//#include "General/Scene.h"
//#include "General/SceneHandler.h"

inline Window* window() { return ConsoleEngine::get().window(); }
inline InputHandler* inputHandler() { return ConsoleEngine::get().inputHandler(); }