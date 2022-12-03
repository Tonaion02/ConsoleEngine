workspace "ConsoleEngine" --usually same of the project
	architecture "x64"

    configurations { "Debug", "Release" }  -- all the configurations

	filter "system:windows"
		systemversion "10.0.17763.0"


project "ConsoleEngine"
    kind "ConsoleApp"
    language "C++"



	-- filtering for the different systems
	filter { "system:windows" }
		defines {"WINDOWS"}
		includedirs ("$(ProjectDir)/src")
		
	filter { "system:linux" }
		defines {"LINUX"}
		includedirs ("$(WorkspacePath)/src")
		
	filter { }





	if not os.isdir("src") then os.mkdir("src") end

	--template main code
	mainFile = "int main()\n{\n	return 0;\n}"
	--template main code

	if not os.isfile("src/Main.cpp") and not os.isfile("src/main.cpp") then io.writefile("src/Main.cpp", mainFile) end

	includedirs -- directory where there is .h and .cpp
	{ 
				
	}
    
	libdirs -- directory for the location of the library(.lib and .dll)
	{ 		

	}

	links -- .lib file to link
	{ 

	}

	files { "src/**.h", "src/**.cpp" } -- source files
	removefiles { "src/ToDo.h" }       -- files to exclude from compilation

	removefiles { "src/ConsoleEngine/Platforms/Linux/LinuxLauncher.cpp" } --exclude the LinuxLauncher from all project

	objdir "output/obj"                -- directory where object and other intermediate files should be placed when building a project

	defines { }                         -- common defines beetween all the configurations





	-- filtering for the different configurations
    filter { "configurations:Debug" }		-- debug configuration
        defines { "DEBUG" }
        symbols "On"
		targetdir "output/bin/debug"

    filter { "configurations:Release" }		-- release configuration
        defines { "NDEBUG" }
        optimize "On"
		targetdir "output/bin/release"

	filter { }


	-- filtering for the different systems
	filter { "system:windows" }
		removefiles("src/ConsoleEngine/Platforms/Linux/**.h")
		removefiles("src/ConsoleEngine/Platforms/Linux/**.cpp")

	filter { "system:linux" }
		removefiles("src/ConsoleEngine/Platforms/Windows/**.h")
		removefiles("src/ConsoleEngine/Platforms/Windows/**.cpp")
		
	filter { }






-- Clean Function --
newaction {
	trigger = "clean",
	description = "clean the software",
	execute = function()
		print("clean the build...")
		
		-- Clean the directory and files for Linux build --
		os.remove("./**.mk")
		os.remove("./**.project")
		os.remove("./**.txt")
		os.remove("./**.workspace")
		os.remove("./Makefile")
		os.rmdir("./output")
		
		-- Clean the directory and files for Windows build --
		os.remove("./**.sln")
		os.remove("./**.vcxproj")
		os.remove("./**.vcxproj.filters")		
		os.remove("./**.vcxproj.user")		
		
		print("done.")
	end
}