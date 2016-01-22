// **************************************************************
// *		   
// *  quadtree.h
// *		   
// *  Quadtree class
// *		   
// *  CS 225 Spring 2008
// *		   
// **************************************************************

#ifndef QUADTREE_H
#define QUADTREE_H

#include "png.h"
#include "rgbapixel.h"
#include<math.h>

class Quadtree
{
	public:
	// Default constructor, empty Quadtree object 
	Quadtree();

	// Constructor takes two arguments
	Quadtree(PNG const & source, int resolution);

	// Desturctor
	~Quadtree();

	// Copy constructor
	Quadtree(const Quadtree & other);

	// Assignment operator
	const Quadtree & operator=(const Quadtree & other);
	
	//buiildTree Function
	void buildTree(PNG const & source, int resolution);
	
	RGBAPixel getPixel(int x, int y) const;
	PNG decompress() const;
	void clockwiseRotate();
	void prune(int tolerance);
	int pruneSize(int tolerance) const;
	int idealPrune(int numLeaves) const;
	
	
	private:

	// A simple class representing a single node of a Quadtree.
	// You may want to add to this class; in particular, it could probably
	// use a constructor or two...
	class QuadtreeNode
	{
		public:
		QuadtreeNode* nwChild;  // pointer to northwest child
		QuadtreeNode* neChild;  // pointer to northeast child
		QuadtreeNode* swChild;  // pointer to southwest child
		QuadtreeNode* seChild;  // pointer to southeast child

		RGBAPixel element;  // the pixel stored as this node's "data"

		QuadtreeNode(RGBAPixel e):nwChild(NULL),neChild(NULL),swChild(NULL),seChild(NULL),element(e){}

		QuadtreeNode():nwChild(NULL),neChild(NULL),swChild(NULL),seChild(NULL){}
		
	};
	
	QuadtreeNode* root;    // pointer to root of quadtree
	
	int d; //SIze of the png
	
	// Private helper functions
	void clear(QuadtreeNode * current);
	void copy(const Quadtree & other);
	QuadtreeNode * copy(const QuadtreeNode * current);

	// Buildtree helper
	QuadtreeNode * buildTreeHelper(PNG const & source, int resolution, int x, int y) const;
	void decompressHelper(PNG & s,QuadtreeNode * r, int x, int y, int d) const;
	RGBAPixel getPixelHelper(QuadtreeNode * r, int x, int y,int m,int n, int d) const;
	
	//MP5.2 Helper
	void clockwiseRotateHelper(QuadtreeNode * current);

	void pruneHelper(int tolerance,QuadtreeNode * current) ;
	bool isprune(int tolerance,QuadtreeNode * current,QuadtreeNode * a) const;
	int diff(RGBAPixel a, RGBAPixel b) const;

	int pruneSizeHelper(int tolerance,QuadtreeNode * current) const;

	int idealPruneHelper(int numLeaves,QuadtreeNode * current) const;
	
	/**** Functions added for testing/grading                ****/
	/**** Do not remove this line or copy its contents here! ****/
	#include "quadtree_given.h"
};

#endif
