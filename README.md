# ConsoleEngine
## An engine for games and app that runs in console
	You can build the project for CodeLite(Linux) and for Visual Studio(Windows)
	
	###Requirements:
	To run ConsoleEngine in Linux, you need to compile in Debug Mode the ConsoleEgine in CodeLite and
	compile the LinuxLauncher with this command while you are in principle folder:
	``` g++ ./src/ConsoleEngine/Platforms/Linux/LinuxLauncher.cpp ./src/utils/StringAndFile/MyString.cpp ./src/utils/StringAndFile/XMLvariab.cpp -o LinuxLauncher```
	For Linux you need also to install:
		-gnome-terminal
		-g++