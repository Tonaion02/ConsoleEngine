#include "ConsoleEngine/DataStructures/Surface.h"





//-----------------------------------------------------------------------------------------------------------------------------------------
//Class Surface
//-----------------------------------------------------------------------------------------------------------------------------------------
Surface::Surface(const std::string& data)
	:data(data)
{
	//Calculate the size of the surface searching the '\n' for the end of each row
	dim.x = data.find_first_of('\n');
	dim.y = data.size() / (dim.x + 1);
	//Calculate the size of the surface searching the '\n' for the end of each row
}



Surface::Surface(const Vector2i& dim)
	:dim(dim), data("")
{
	for(int y=0;y<dim.y;y++)
	{
		for(int x=0;x<dim.x;x++)
			data += " ";
		data += "\n";
	}
}



const char* Surface::raw()
{
	return data.c_str();
}



std::string Surface::getData() const
{
	return data;
}



Vector2i Surface::getDim() const
{
	return dim;
}



void Surface::blit(const Surface& surface)
{
	//Controll if the dimension of the surface toBlit is bigger of this surface
	if(dim.x < surface.dim.x)
		printf("Error: width");
		
	if(dim.y < surface.dim.y)
		printf("Error: height");
	//Controll if the dimension of the surface toBlit is bigger of this surface
	
	
	
	//Copy content of toBlit surface on this surface
	for(int y = 0;y < surface.dim.y;y++)
	{
		//Calculate the index of line to copy and size to copy
		int startLineToCopy = (y * (surface.dim.x + 1));
		int sizeToCopy = surface.dim.x;
		//Calculate the index of line to copy and size to copy
		
		//Calculate the starting and ending index of line on to write
		int startLineToWrite = (y * (dim.x + 1 )); 
		int endLineToWrite = startLineToWrite + surface.dim.x;
		//Calculate the starting and ending index of line on to write
		
		//Copy the selected part of the string
		data.replace(data.begin() + startLineToWrite, 
					 data.begin() + endLineToWrite, 
					surface.getData().substr(startLineToCopy, sizeToCopy));
		//Copy the selected part of the string
	}
	//Copy content of toBlit surface on this surface
}



void Surface::blit(const Surface& toBlit, const Vector2i& pos)
{
	//Controll if the dimension of the surface toBlit is bigger of this surface
	if(dim.x < toBlit.dim.x)
		printf("Error: width");
		
	if(dim.y < toBlit.dim.y)
		printf("Error: height");
	//Controll if the dimension of the surface toBlit is bigger of this surface

	for(int y = pos.y;y < toBlit.dim.y;y++)
	{
		//Calculate the index of line to copy and size to copy
		int startLineToCopy = (y * (toBlit.dim.x + 1));
		int sizeToCopy = toBlit.dim.x;
		//Calculate the index of line to copy and size to copy
		
		//Calculate the starting and ending index of line on to write
		int startLineToWrite = pos.x + y * (dim.x + 1); 
		int endLineToWrite = startLineToWrite + toBlit.dim.x;
		//Calculate the starting and ending index of line on to write
		
		//Calculate the last line on to write
		int limitLineToWrite = y * (dim.x + 1) + dim.x;
		//Calculate the last line on to write
		
		//Control if the starting index of line on to write is bigger than the limit of the line
		if(startLineToWrite >= limitLineToWrite)
			return;
		//Control if the starting index of line on to write is bigger than the limit of the line

		//Controll if the ending index of line on to write is bigger than the limit of the line
		if(endLineToWrite > limitLineToWrite)
		{
			sizeToCopy = endLineToWrite - limitLineToWrite;
			endLineToWrite = limitLineToWrite;
		}
		//Controll if the ending index of line on to write is bigger than the limit of the line
		
		//Copy the selected part of the string		
		data.replace(data.begin() + startLineToWrite, 
					 data.begin() + endLineToWrite, 
					 toBlit.getData().substr(startLineToCopy, sizeToCopy));
		//Copy the selected part of the string
	}
	//Copy content of toBlit surface on this surface
}



void Surface::blit(const Surface& toBlit, const Vector2i& pos, const Vector2i& dimToBlit)
{
	//Controll if the dimension of the surface toBlit is bigger of this surface	
	if(toBlit.dim.x < dimToBlit.x)
		printf("Error: width dimToBlit");

	if(toBlit.dim.y < dimToBlit.y)
		printf("Error: height dimToBlit");
	//Controll if the dimension of the surface toBlit is bigger of this surface
	
	/*
	if(dim.x < toBlit.getDim().x)
		printf("Error: width");
		
	if(dim.y < toBlit.getDim().y)
		printf("Error: height");
	*/
	
	//Calculate the last line on to write
	int lastLineToWrite = dimToBlit.y + pos.y;
	//Calculate the last line on to write
	
	
	
	//Copy content of toBlit surface on this surface
	for(int y = pos.y;y < lastLineToWrite;y++)
	{
		//Calculate the index of line to copy and size to copy		
		int startLineToCopy = (y * (toBlit.dim.x + 1));
		int sizeToCopy = dimToBlit.x;
		//Calculate the index of line to copy and size to copy

		//Calculate the starting and ending index of line on to write
		int startLineToWrite = pos.x + y * (dim.x + 1); 
		int endLineToWrite = startLineToWrite + dimToBlit.x;
		//Calculate the starting and ending index of line on to write

		//Calculate the last line on to write
		int limitLineToWrite = y * (dim.x + 1) + dim.x;
		//Calculate the last line on to write

		//Control if the starting index of line on to write is bigger than the limit of the line		
		if(startLineToWrite >= limitLineToWrite)
			return;
		//Control if the starting index of line on to write is bigger than the limit of the line

		//Controll if the ending index of line on to write is bigger than the limit of the line
		if(endLineToWrite > limitLineToWrite)
		{
			sizeToCopy = endLineToWrite - limitLineToWrite;
			endLineToWrite = limitLineToWrite;
		}
		//Controll if the ending index of line on to write is bigger than the limit of the line

		//Copy the selected part of the string		
		data.replace(data.begin() + startLineToWrite, 
			data.begin() + endLineToWrite, 
			toBlit.getData().substr(startLineToCopy, sizeToCopy));
		//Copy the selected part of the string
	}
	//Copy content of toBlit surface on this surface
}
//-----------------------------------------------------------------------------------------------------------------------------------------
//Class Surface
//-----------------------------------------------------------------------------------------------------------------------------------------