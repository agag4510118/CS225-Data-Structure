// Cs 225 Lab06 Unit Tests

#include <iostream>
#include <sstream>
#include <string>

#include "png.h"
#include "proxy.h"
#include "util.h"

using namespace std;
using namespace util;

PNG brighten(PNG original, int amount);
PNG drawCrosshairs(PNG original, int centerX, int centerY, RGBAPixel color);
PNG blendImages(PNG firstImage, PNG secondImage);


PNG genTestPNG()
{
	PNG image(10, 10);
	for (uint8_t x = 0; x < image.width(); x++)
	{
		for (uint8_t y = 0; y < image.width(); y++)
		{
			image(x, y)->red = 10*x + 10*y;
			image(x, y)->green = 25*x;
			image(x, y)->blue = 255 - 2*x - 5*y;
		}
	}
	return image;
}

PNG genTestPNG2()
{
	PNG image(10, 10);
	for (uint8_t x = 0; x < image.width(); x++)
	{
		for (uint8_t y = 0; y < image.width(); y++)
		{
			image(x, y)->red = y/2 + 64;
			image(x, y)->green = 100 + 10*x - 10*y;
			image(x, y)->blue = 255 - 3*x - 3*y;
		}
	}
	return image;
}

UNIT_TEST(testBrighten, 0, 33, 1000)
{
	PNG image = genTestPNG();
	PNG brightened = brighten(image, 100);
	
	for (uint8_t x = 0; x < image.width(); x++)
	{
		for (uint8_t y = 0; y < image.width(); y++)
		{
			if (image(x, y)->red <= 255 - 100)
				ASSERT_EQUALS(image(x, y)->red + 100, (int)brightened(x, y)->red);
			else
				ASSERT(brightened(x, y)->red == 255);

			if (image(x, y)->green <= 255 - 100)
				ASSERT_EQUALS(image(x, y)->green + 100, (int)brightened(x, y)->green);
			else
				ASSERT(brightened(x, y)->green == 255);

			if (image(x, y)->blue <= 255 - 100)
				ASSERT_EQUALS(image(x, y)->blue + 100, (int)brightened(x, y)->blue);
			else
				ASSERT(brightened(x, y)->blue == 255);
		}
	}
}

bool pixels_same( const RGBAPixel & one, const RGBAPixel & two ) {
    return one.red == two.red && one.green == two.green && one.blue == two.blue && one.alpha == two.alpha;
}

UNIT_TEST(testCrosshairs, 0, 33, 1000)
{
	PNG image = genTestPNG();

	RGBAPixel red;
	red.red = 255;
	red.green = 0;
	red.blue = 0;

	PNG crosshairs = drawCrosshairs(image, 3, 6, red);
	
	for (uint8_t x = 0; x < image.width(); x++)
        ASSERT(pixels_same(red, *crosshairs(x, 6)));

	for (uint8_t y = 0; y < image.height(); y++)
        ASSERT(pixels_same(red, *crosshairs(3, y)));
}

UNIT_TEST(testBlendImages, 0, 34, 1000)
{
	PNG image1 = genTestPNG();
	PNG image2 = genTestPNG2();

	PNG blended = blendImages(image1, image2);

	for (uint8_t x = 0; x < image1.width(); x++)
	{
		for (uint8_t y = 0; y < image1.width(); y++)
		{
			ASSERT(abs((image1(x, y)->red + image2(x, y)->red)/2 - blended(x, y)->red) <= 1);
			ASSERT(abs((image1(x, y)->green + image2(x, y)->green)/2 - blended(x, y)->green) <= 1);
			ASSERT(abs((image1(x, y)->blue + image2(x, y)->blue)/2 - blended(x, y)->blue) <= 1);
		}
	}
}

