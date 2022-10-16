#include <cstdio>
#include <cstdlib>

#include "../../../utils/StringAndFile/MyString.h"
#include "../../../utils/StringAndFile/XMLvariab.h" 





int main()
{
	std::string optionsFile = "data/options.xml";
	std::vector<std::string> lines = getLines(optionsFile);
	
	//std::vector<XMLvariab> xmlVariables = getXMLvariables(lines);
	//XMLvariab options = xmlVariables[0];
	std::vector<XMLvariab> xmlVariables = getXMLvariables(lines);
	XMLvariab windowOptions = xmlVariables[0];
	std::string x = windowOptions.getValue("x");
	std::string y = windowOptions.getValue("y");
	std::string w = windowOptions.getValue("width");
	std::string h = windowOptions.getValue("heigth");
	std::string zoom = windowOptions.getValue("zoom");
	
	
	std::string command = "gnome-terminal ";
	command += "--geometry=" + w + "x" + h + "+" + x + "+" + y;
	command += " ";
	command += "--zoom=" + zoom;
	command += " ";
	command += "-- ./output/bin/debug/ConsoleEngine";
	
	printf("%s\n", command.c_str());
	system(command.c_str());
	
	return 0;
}