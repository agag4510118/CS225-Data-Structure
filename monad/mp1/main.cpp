#include<iostream>
#include"rgbapixel.h"
#include"png.h"
#include<algorithm>

using namespace std;

PNG rotateImage(PNG original)
{
	

 RGBAPixel middle;
	RGBAPixel middle2;
	size_t height = original.height();
	size_t width = original.width();

	PNG ooo(width,height);

	for (size_t x = 0; x < width; x++)
        for (size_t y = 0; y < height; y++)
	{	
	size_t x1 = original.width()-1-x;
	size_t y1 = original.height()-1-y;

	middle = *original(x,y);
	middle2 = *original(x1,y1);
	*ooo(x,y)=middle2;
	//	*original(x1,y1) = middle; 

	
	}


	return ooo;
}

int main()
{
	// OPen a new PNG image from the file in.png
	PNG inimage("in.png");

	//ROtate the image
	inimage = rotateImage(inimage);

	//Save the modified image to a file out.png
	inimage.writeToFile("out.png");


return 0;
}
