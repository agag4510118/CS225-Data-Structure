#include"image.h"

void Image::flipleft()
{
	int height = this->height();
	int width = this->width();

	
	for (int i = 0; i < width/2;i++)
		for (int j= 0; j< height;j++)
		{	
		  RGBAPixel *tem = new RGBAPixel;
			*tem = *(*this)(i,j);
			*(*this)(i,j) = *(*this)(width-1-i,j);
			*(*this)(width-1-i,j)= *tem; 	
			//	tem = NULL;
			delete tem;
			tem = NULL;
		}

	
}

void Image::adjustbrightness(int r, int g, int b)
{
	int height = this->height();
	int width = this->width();

	for(int i = 0; i < width;i++)
	for(int j = 0; j < height;j++)
	{	
		int red = (*this)(i,j)->red;
		int green = (*this)(i,j)->green;
		int blue = (*this)(i,j)->blue;
				
		if (red + r > 255)
		(*this)(i,j)->red = 255;
		else if (red + r <0)
		(*this)(i,j)->red = 0;
		else
		(*this)(i,j)->red += r;

		if (green + g > 255)
		(*this)(i,j)->green = 255;
		else if (green + g < 0)
		(*this)(i,j)->green =0;
		else
		(*this)(i,j)->green += g;

		if (blue + b > 255)
		(*this)(i,j)->blue = 255;
		else if (blue + b < 0)
		(*this)(i,j)->blue = 0;
		else
		(*this)(i,j)->blue +=b;		
	}
}

void Image::invertcolors()
{
	int height = this->height();
	int width = this->width();
	for(int i = 0; i < width; i++)
	for(int j = 0; j < height; j++)
	{
	int red = (*this)(i,j)->red ;
	int green = (*this)(i,j)->green;
	int blue = (*this)(i,j)->blue;
	
	(*this)(i,j)->red = 255-red;
	(*this)(i,j)->green = 255-green;
	(*this)(i,j)->blue = 255-blue;	
	}
}

