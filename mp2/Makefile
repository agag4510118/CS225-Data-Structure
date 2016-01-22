EXENAME1 = testimage
EXENAME2 = testscene
OBJS1 = testimage.o png.o image.o rgbapixel.o
OBJS2 = testscene.o png.o image.o rgbapixel.o scene.o

CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lpng -lc++abi

all : $(EXENAME1)
	$(EXENAME2)

$(EXENAME1) : $(OBJS1)
	$(LD) $(OBJS1) $(LDFLAGS) -o $(EXENAME1)
$(EXENAME2) : $(OBJS2)
	$(LD) $(OBJS2) $(LDFLAGS) -o $(EXENAME2)


testimage.o : testimage.cpp image.h
	$(CXX) $(CXXFLAGS) testimage.cpp

png.o : png.cpp png.h rgbapixel.h
	$(CXX) $(CXXFLAGS) png.cpp

image.o : image.cpp image.h png.h
	$(CXX) $(CXXFLAGS) image.cpp

rgbapixel.o : rgbapixel.cpp rgbapixel.h
	$(CXX) $(CXXFLAGS) rgbapixel.cpp

testscene.o : testscene.cpp image.h scene.h
	$(CXX) $(CXXFLAGS) testscene.cpp

scene.o: scene.cpp image.h scene.h
	$(CXX) $(CXXFLAGS) scene.cpp

clean :
	-rm -f *.o $(EXENAME1)
	-rm -f *.o $(EXENAME2)



