// **************************************************************
// *		   
// *  quadtree.cpp
// *		   
// *  Quadtree class
// *		   
// *  CS 225 Spring 2008
// *		   
// **************************************************************

#include "quadtree.h"

	// Private helper functions
	void Quadtree::clear(QuadtreeNode * current)
	{
		if(current == NULL)
			return;
		clear(current->nwChild);
		clear(current->neChild);
		clear(current->swChild);
		clear(current->seChild);
		delete current;
	
	}

	void Quadtree::copy(const Quadtree & other)
	{
		root = copy(other.root);
		d = other.d;
	}

	Quadtree::QuadtreeNode * Quadtree::copy(const QuadtreeNode * current)
	{
		if(current == NULL)
			return NULL;
		
		QuadtreeNode * node = new QuadtreeNode(current->element);
		node->nwChild = copy(current->nwChild);
		node->neChild = copy(current->neChild);
		node->swChild = copy(current->swChild);
		node->seChild = copy(current->seChild);

		return node;
	}
	
	// Public
	// Big three
	// Copy constructor
	Quadtree::Quadtree(const Quadtree & other)
	{
		copy(other);
	}

	// Assignment operator
	const Quadtree & Quadtree::operator=(const Quadtree & other)
	{
		if(this != &other){
			clear(root);
			copy(other);
		}
			
		return *this;
	}

	//Destructor
	Quadtree::~Quadtree()
	{
		clear(root);
		root = NULL;
	}

	//
	// Default constructor, empty Quadtree object 
	Quadtree::Quadtree()
	{
		root = NULL;
		d = 0;
	}

	// Constructor takes two arguments
	Quadtree::Quadtree(PNG const & source, int resolution)
	{
		root = NULL;
		buildTree(source,resolution);
		d = resolution;
	}
	

	//buiildTree Function
	void Quadtree::buildTree(PNG const & source, int resolution)
	{
		// deletes the current cotents of this Quadtree object
		clear(root);
		d = resolution;		
		root = buildTreeHelper(source,resolution,0,0);
	}
	// Buildtree helper
	Quadtree::QuadtreeNode * Quadtree::buildTreeHelper(PNG const & source, int resolution, int x, int y) const
	{
		if(resolution ==1)
		{
			QuadtreeNode * temp = new QuadtreeNode(*source(x,y));
			return temp;
		}

		QuadtreeNode * t = new QuadtreeNode;
		
		t->nwChild = buildTreeHelper(source,resolution/2,x,y);
		t->neChild = buildTreeHelper(source,resolution/2,x+resolution/2,y);
		t->swChild = buildTreeHelper(source, resolution/2,x,y+resolution/2);
		t->seChild = buildTreeHelper(source, resolution/2,x+resolution/2,y+resolution/2);

		t->element.red=(t->nwChild->element.red+ t->neChild->element.red + t->swChild->element.red + t->seChild->element.red)/4;
		t->element.green=(t->nwChild->element.green + t->neChild->element.green + t->swChild->element.green + t->seChild->element.green)/4;
		t->element.blue=(t->nwChild->element.blue+ t->neChild->element.blue + t->swChild->element.blue + t->seChild->element.blue)/4;

		return t;
	}

	// getPixel
	RGBAPixel Quadtree::getPixel(int x, int y) const
	{
		if(x>=d || y>=d || d ==0)
		{	
			return RGBAPixel();
		}

		return getPixelHelper(root, x, y,0,0,d);
	}

	// getPixel Helper
	RGBAPixel Quadtree::getPixelHelper(QuadtreeNode * r, int x, int y, int m, int n,int d) const
	{
		if(r->nwChild == NULL && r->neChild == NULL && r->swChild == NULL && r->seChild == NULL  )
			return r->element;

		if(x< m + d/2 && y< n + d/2)
			return getPixelHelper(r->nwChild,x,y,m,n,d/2);
		else if(x>= m + d/2 && y< n + d/2)
			return getPixelHelper(r->neChild,x,y,m+d/2,n,d/2);
		else if(x< m + d/2 && y>= n + d/2)
			return getPixelHelper(r->swChild,x,y,m,n+d/2,d/2);
		else if(x>= m + d/2 && y>= n + d/2)
			return getPixelHelper(r->seChild,x,y,m+d/2,n+d/2,d/2);
		
		return RGBAPixel();
	}

	//decompress
	PNG Quadtree::decompress() const
	{
		if (root == NULL)
			return PNG();

		PNG tem(d,d);

		decompressHelper(tem,root,0,0,d);
		return tem;
		
	}
	// Decompress helper
	void Quadtree::decompressHelper(PNG & s,QuadtreeNode * r, int x, int y, int d) const
	{
		if(r->nwChild == NULL || r->neChild == NULL || r->swChild == NULL || r->seChild == NULL  )
		{
			for(int i =x; i < x+d;i++)
			{
				for(int j = y; j < y+d;j++)
				{
					*s(i,j) = r->element;
				}
			}
			return;
		}
		
		decompressHelper(s,r->nwChild,x,y,d/2);
		decompressHelper(s,r->neChild,x+d/2,y,d/2);
		decompressHelper(s,r->swChild,x,y+d/2,d/2);
		decompressHelper(s,r->seChild,x+d/2,y+d/2,d/2);
		
		
	}


	// MP5.2
	// ClockwiseRotate
	void Quadtree::clockwiseRotate()
	{
		clockwiseRotateHelper(root);
	}
	//Helper function
	void Quadtree::clockwiseRotateHelper(QuadtreeNode * current)
	{
		// Base
		if (current == NULL)
			return;
	
		// Svae temperory tree nodes
		QuadtreeNode * tempnw= current->nwChild;
		QuadtreeNode * tempne= current->neChild;
		QuadtreeNode * tempsw= current->swChild;
		QuadtreeNode * tempse= current->seChild;
	
		//Exchange
		current->nwChild = tempsw;
		current->neChild = tempnw;
		current->swChild = tempse;
		current->seChild = tempne;

		// Recursion
		clockwiseRotateHelper(current->nwChild);
		clockwiseRotateHelper(current->neChild);
		clockwiseRotateHelper(current->swChild);
		clockwiseRotateHelper(current->seChild);
	}

	// Prune
	void Quadtree::prune(int tolerance)
	{
		pruneHelper(tolerance,root);
	}

	void Quadtree::pruneHelper(int tolerance,QuadtreeNode * current) 
	{
		// EMpty Tree
		if (current == NULL)
			return;

		// If we can prune this node
		if (isprune(tolerance,current,current))
		{
			clear(current->nwChild);
			clear(current->neChild);
			clear(current->swChild);
			clear(current->seChild);
		current->nwChild = NULL;
		current->neChild = NULL;
		current->swChild = NULL;
		current->seChild = NULL;
			
			return;
		}
			
		// Check for all quad
		pruneHelper(tolerance,current->nwChild);
		pruneHelper(tolerance,current->neChild);
		pruneHelper(tolerance,current->swChild);
		pruneHelper(tolerance,current->seChild);
	}

	bool Quadtree::isprune(int tolerance,QuadtreeNode * current, QuadtreeNode * a) const
	{
		// if the root is null
		//if (current == NULL)
			//return true; 
	
		// Check if we get the leave
		if(current->nwChild != NULL)
		{
			bool judge = false;
			// Only ture when all leaf are true 			
			judge = (isprune(tolerance,current->nwChild,a)&&isprune(tolerance,current->neChild,a)&&isprune(tolerance,current->swChild,a)&&isprune(tolerance,current->seChild,a));
			return judge;
		}
		
		// For the leaf, we need to satisfy the tolerance
		//if(current->nwChild == NULL)
		if (diff(current->element,a->element)<=tolerance)
			return true;
		
		return false;
		
	}

	int Quadtree::diff(RGBAPixel a, RGBAPixel b) const
	{
		return pow((a.red-b.red),2)+pow((a.green-b.green),2)+pow((a.blue-b.blue),2);
	}

	//PruneSize
	int Quadtree::pruneSize(int tolerance) const
	{return pruneSizeHelper(tolerance,root);}

	int Quadtree::pruneSizeHelper(int tolerance,QuadtreeNode * current) const
	{
		// Empty tree
		if (current == NULL)
			return 0;
		//Base case
		if (isprune(tolerance,current,current))
			return 1;
		// Leaf node
		if (current->nwChild == NULL)
			return 1;

		// Recursion
		return pruneSizeHelper(tolerance,current->nwChild) + pruneSizeHelper(tolerance,current->neChild) +pruneSizeHelper(tolerance,current->seChild) +pruneSizeHelper(tolerance,current->swChild) ;

	}
		
	//IdealPrune
	int Quadtree::idealPrune(int numLeaves) const
	{return idealPruneHelper(numLeaves,root);}

	//IdealPrune Helper
	int Quadtree::idealPruneHelper(int numLeaves,QuadtreeNode * current) const
	{
		// Max number for a pixel
		int a = 255;
		// Max tolerance
		int max = pow(a,2)*3;
		// Min tolerance
		int min = 0;
		int result = 0;
		int tolerance = (min + max)/2;
		int size = pruneSize(tolerance);
		

		// When tolerance bigger, the size will be smaller
		while (tolerance < max && tolerance > min)
		{
			size = pruneSize(tolerance);
			if(size<=numLeaves)
			{	
				// Try to increase size by reduce tolerance 
				// Record the current tolerance 
				max = tolerance;
				result = tolerance;
			}
			else
			{
				min = tolerance;
			}
			tolerance = (min + max)/2;
		}
		

		return result;
	}

