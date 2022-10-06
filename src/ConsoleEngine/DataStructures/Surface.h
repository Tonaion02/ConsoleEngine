#pragma once

#include <string>

#include "utils/Math/Vector2i.h"





class Surface
{
public:
	Surface() {}; //To delete
	//Create a surface copying content from string
	Surface(const std::string& data);
	//Create a blank surface o with dim sizes
	Surface(const Vector2i& dim); 
	
	//Blit another surface on this surface
	void blit(const Surface& toBlit);
	//Blit another surface on this surface starting from a specific pos
	void blit(const Surface& toBlit, const Vector2i& pos);
	//Blit another surface on this surface starting from a specific pos and copy only a specific part
	void blit(const Surface& toBlit, const Vector2i& pos, const Vector2i& dimToBlit);
	
	const char* raw();
	std::string getData() const;
	Vector2i getDim() const;
	
private:
	std::string data;
	Vector2i dim;
};