#include"scene.h"

// CLear
void Scene::clear()
{

  for (int i = 0; i < maximage; i++)
  {
 	if (sc[i] !=NULL)
	delete sc[i];
	sc[i] = NULL;
  }

  delete [] xcord;
  delete [] ycord;
  delete [] index;
  delete [] sc;
  xcord = NULL;
  ycord = NULL;
  index = NULL;
  sc = NULL;	
}

//Copy
void Scene::copy(const Scene &source)
{
	countn = source.countn;
  maximage = source.maximage;
  sc = new Image *[maximage];

  xcord = new int [maximage];
  ycord = new int [maximage];
  index = new int [maximage];

  for (int i = 0; i < maximage; i++)
    {
 	if(source.sc[i]!=NULL)
	{
      		sc[i] = new Image(*(source.sc[i]));
      		xcord[i] = source.xcord[i];
      		ycord[i] = source.ycord[i];
      		index[i] = source.index[i];
	} 
	 else sc[i]=NULL;  
    }

}

//Destructors
Scene::~Scene()
{
  clear();
}

//Constructor
Scene::Scene(int max)
{
	countn = 0;
	maximage = max;
	sc = new Image*[max];

 	 xcord = new int [maximage];
 	 ycord = new int [maximage];
 	 index = new int [maximage];
	
	for (int i=0; i < max; i ++)
	{
		sc[i]=NULL;
		xcord[i]=0;
		ycord[i]=0;
		index[i]=i;
	}
}

// Copy constructor
Scene::Scene(const Scene & source)
{
  copy(source);
}

//Overloaded =
const Scene& Scene::operator=(const Scene &source)
{
  if (this != & source)
    {

      clear();
      copy(source);
    }
  return *this;
}

// CHangemaxlayers
void Scene::changemaxlayers(int newmax)
{
  if (newmax<maximage)
	{
	for (int k = newmax; k < maximage; k++)
	{
		if(sc[k]!=NULL)
    		cout << "invalid newmax"<<endl;
	}
	}
  else
    {
      // maximage = newmax;
      Image ** ss = new Image *[maximage];
	int *xx = new int [maximage];
	int *yy= new int [maximage];

	for (int i = 0; i < maximage ; i ++)
	  {
	    ss[i] = sc[i];
	    xx[i] = xcord[i];
	    yy[i] = ycord[i];
	  }
 
	clear();

      sc = new Image *[newmax];
      xcord = new int [newmax];
      ycord = new int [newmax];
      index = new int [newmax];

      for (int j = 0; j < maximage; j++)
	{
	  sc[j] = ss[j];
	  xcord[j] = xx[j];
	  ycord[j] = yy[j];
	  index[j] = j;
	}
      for (int m = maximage; m < newmax; m++)
	{
	  sc[m] = NULL;
	  xcord[m] = 0;
	  ycord[m] = 0;
	  index[m] = m;
	}
       maximage = newmax;

	for(int p = 0; p < maximage;p++)
	{
		if(ss[p]!=NULL)
		{
			delete ss[p];
			ss[p] = NULL;
		}
	}
       delete [] ss;
       delete [] xx;
       delete [] yy;
       ss = NULL;
       xx = NULL;
       yy = NULL;
	

    }

}

//ADdpicture
void Scene::addpicture(const char* FileName, int index, int x, int y)
{
  if (index >= maximage || index <0)
    cout << "index out of bounds" << endl;
  else
    {
     sc[index] = new Image;
      sc[index]->readFromFile(FileName);
      xcord[index] = x;
      ycord[index] = y;
	countn+=1;

    }
  
}

// CHangelayer
void Scene::changelayer(int index, int newindex)
{
  if ((newindex >= maximage) || (index >= maximage))
    cout <<"invalid index" << endl;
  else{

    if (index != newindex)
      {
	if (sc[index]!=NULL)
	  {	
		delete sc[newindex];
		sc[newindex] = sc[index];
		sc[index] = NULL;
	        xcord[newindex]=xcord[index];
		ycord[newindex]= ycord[index];
	  }
	else
	  {
		sc[newindex] = sc[index];
		sc[index] = NULL;
		xcord[newindex]=xcord[index];
		ycord[newindex]= ycord[index];

	  }
      }
  }
}

//Translate
void Scene::translate(int index, int xcoord, int ycoord)
{
  if( (index>=maximage) || (sc[index]==NULL))
    cout << "invalid index " << endl;
  else
    {
      xcord[index] = xcoord;
      ycord[index] = ycoord;

    }

}

//Deletepicture
void Scene::deletepicture(int index)
{
   if( (index>=maximage) || (sc[index]==NULL))
    cout << "invalid index " << endl;
  else
    {
      delete sc[index];
	sc[index] = NULL;
      xcord[index] =0;
      ycord[index] = 0;
    }
}

// Get picture
Image * Scene::getpicture (int index) const
{
  if (index >= maximage)
    {
      cout << "invalid index" << endl;
      return NULL;
    }
  else
    {
      return sc[index];
    }
}

//Drawscene
Image Scene::drawscene() const
{	
	// Find the size of new image	
	// Check all not null pointers, record height and width
  	int max = maximage;
	size_t h = 0;
	size_t w = 0;

 	 for(int i =0; i < max ; i++)
	{
		if (sc[i]!=NULL)
		{
			if (h<sc[i]->height()+ycord[i])
				h = sc[i]->height()+ycord[i];
			if (w < (*sc[i]).width()+xcord[i])
				w = sc[i]->width()+xcord[i];	
		}
	}
	
	// create the image
	Image final(w,h);

	for (int j = 0; j < max ; j++)
	{
		if (sc[j]!=NULL)
		{
			int hh = sc[j]->height();
			int ww = sc[j]->width();
			int xc = xcord[j];
			int yc = ycord[j];

			for (int x = xc;x<(xc+ww); x++)
			{
				for (int y = yc;y<(yc+hh); y++)
				{
					*(final(x,y)) = *(*sc[j])(x-xc,y-yc);
				}
			}
		}
	}
	return final;
	

}

