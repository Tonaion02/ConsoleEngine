#include "ConsoleEngine/DataStructures/Color.h"





//-----------------------------------------------------------------------------------------------------------------------------------------
//Class Color
//-----------------------------------------------------------------------------------------------------------------------------------------
Color::Color(ColorId idColor)
	:id(idColor)
{
	
}



ColorId Color::Id()
{
	return id;
}



int Color::fgWindow() const
{
	return static_cast<int>(id);
}



int Color::bgWindow() const 
{
	return static_cast<int>(id);
}



int Color::fgLinux() const
{
	if(id < static_cast<int>(bBlack))
		return 30 + id;
	return 82 + id;	
}



int Color::bgLinux() const 
{
	if(id < static_cast<int>(bBlack))
		return 40 + id;
	return 92 + id;
}
//-----------------------------------------------------------------------------------------------------------------------------------------
//Class Color
//-----------------------------------------------------------------------------------------------------------------------------------------