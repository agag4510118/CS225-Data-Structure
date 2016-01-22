// CS 225 Lab02 Unit Tests

#include "png.h"
#include "util.h"
#include "proxy.h"

using namespace util;

#if MP_PART(0)

void sketchify();

void call_sketchify(const string & imageFile)
{
	exec("cp", imageFile, "in.png");
    sketchify();
}

UNIT_TEST(no_segfaults, 0, 20, 1000)
{
	call_sketchify("in_01.png");
}

UNIT_TEST(produces_out_png, 0, 10, 1000)
{
	call_sketchify("in_01.png");
	ASSERT(exists("out.png"));
}

UNIT_TEST(similar_sketch, 0, 30, 1000)
{
	call_sketchify("in_01.png");
	ASSERT(exists("out.png"));
	
	PNG out01("out.png");
	PNG soln_out01("out_01.png");
	
	ASSERT_EQUALS(soln_out01.width(), out01.width());
	ASSERT_EQUALS(soln_out01.height(), out01.height());

	RGBAPixel white(255, 255, 255);

	// Make sure all the white pixels in the solution
	// are white in the output, and that all the colored
	// pixels in the solution are colored in the output
	for (size_t y = 0; y < soln_out01.height(); y++)
	{
		for (size_t x = 0; x < soln_out01.width(); x++)
		{
			if (*soln_out01(x, y) == white)
				ASSERT_EQUALS(white, *out01(x, y));
			else
				ASSERT(*out01(x, y) != white);
		}
	}
}

UNIT_TEST(complete_in_01_png, 0, 20, 1000)
{
	call_sketchify("in_01.png");
	ASSERT(exists("out.png"));

	PNG out01("out.png");
	PNG soln_out01("out_01.png");

	ASSERT(out01 == soln_out01);

	PASS;
}


UNIT_TEST(complete_in_02_png, 0, 20, 1000)
{
	call_sketchify("in_02.png");
	ASSERT(exists("out.png"));

	PNG out02("out.png");
	PNG soln_out02("out_02.png");

	ASSERT(out02 == soln_out02);

	PASS;
}

#endif
