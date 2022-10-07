#pragma once





enum ColorId
{
	NoneColor = -1,
	black,
	red,
	green,
	yellow,
	blue,
	magenta,
	cyan,
	white,
	bBlack,
	bRed,
	bGreen,
	bYellow,
	bBlue,
	bMagenta,
	bCyan,
	bWhite
};





class Color
{
public:
	Color(ColorId idColor = ColorId::black);
	
	ColorId Id();
	
	int fgWindow() const;
	int bgWindow() const;
	int fgLinux() const;
	int bgLinux() const;
	
protected:
	ColorId id;
};