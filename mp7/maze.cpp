// Author: Li Miao
// December 8, 2015

#include"maze.h"

// Constructor
SquareMaze::SquareMaze()
{
    
}

void SquareMaze::makeMaze(int width, int height)
{
    // Initialization
    w = width;
    h = height;
    cells.addelements(w*h);
   
    // Let all walls exist
    // So it is a grid
    for(int i =0; i < w*h; i++){
        down.push_back(true);
        right.push_back(true);
    }
    
    // Select random walls
    srand(time(NULL));
    vector<int> myvector;
    for (int i=0; i<w*h*2; i++) myvector.push_back(i);
    random_shuffle(myvector.begin(), myvector.end() );
    
    // break w*h*2 random walls
    for (int i = 0; i < w*h*2; i++){
        // the number of the cell
        //int x = rand() % w;
       // int y = rand() % h;
        //int k = y*w + x;
        // 0 = right wall, 1 = down wall
        int whichwalltobreak = 0;
        whichwalltobreak = rand() % 2;
        
        int k =0;
        
        // break the right wall
        if(myvector[i]<w*h){
            k = myvector[i];
           // int x =  ;
            //x == w-1
            if((k+1)%w == 0)
                continue;
            
            if(right[k] == true && cells.find(k) != cells.find(k+1))
            {
                right[k] = false;
                cells.setunion(k,k+1);
            }
            
        }
        else{
            
            k = myvector[i]-w*h;
          //  int y = ;
            //y == h-1
            if(k >= w*(h-1))
                continue;
            
            if(down[k] == true && cells.find(k)!=cells.find(k + w))
            {
                down[k] = false;
                cells.setunion(k,k+w);
            }
        }
        
    }
    
    // If we can still break more walls
    
    
    
    
}

bool SquareMaze::canTravel(int x, int y, int dir) const
{
    // go right
    if(dir == 0)
    {
        if(x == w - 1)
            return false;
        
        return (!right[y*w + x]);
        
    }
    
    // go down
    if(dir == 1)
    {
        if(y == h-1)
            return false;
        
        return (!down[y*w + x]);
        
    }
    
    // go left
    if(dir == 2)
    {
        if(x==0)
            return false;
        
        return (!right[y*w+x-1]);
        
    }
    
    // go up
    if(dir == 3)
    {
        if(y ==0)
            return false;
        
        return(!down[(y-1)*w+x]);
        
    }
    
    return false;
    
}

void SquareMaze::setWall(int x, int y, int dir, bool exists)
{
    // the number of cell
    int k = y*w + x;
    
    // right
    if(dir ==0){
        right[k] = exists;
    }
    // down
    if(dir == 1){
        down[k] = exists;
    }
    
    
}

vector<int> SquareMaze::solveMaze()
{
    // 0 : right
    // 1 : down
    // 2 : left
    // 3 : up
    vector<int> finalpath;
    finalpath = solveMaze_helper(0,0,3);
    if(!finalpath.empty() )
    {
    finalpath.pop_back();
    }
    return finalpath;
}

vector<int> SquareMaze::solveMaze_helper(int x, int y, int wherefrom)
{
    // 0 : right
    // 1 : down
    // 2 : left
    // 3 : up
    
    // we get the bottom
    if(y == h-1)
    {
	// come from right, no walls left and up
        if (wherefrom == 0 && !canTravel(x,y,2) && !canTravel(x,y,3))
            return vector<int>(1,-1);
	// come from left, no walls up and right
        if (wherefrom == 2 && !canTravel(x,y,0) && !canTravel(x,y,3))
            return vector<int>(1,-1);
	// come from up, no walls left and right
        if (wherefrom == 3 && !canTravel(x,y,0) && !canTravel(x,y,2))
            return vector<int>(1,-1);
    }
    
    vector<int> path;
    vector<vector<int>> allpath;
    
    if(wherefrom!=0 && canTravel(x,y,0))
    {
        path = solveMaze_helper(x+1,y,2);
        if(!path.empty() )
        {
            path.insert(path.begin(),1,0);
            allpath.push_back(path);
        }
    }
    
    if(wherefrom!=1 && canTravel(x,y,1))
    {
        path = solveMaze_helper(x,y+1,3);
        
        if(!path.empty() )
        {
            path.insert(path.begin(),1,1);
            allpath.push_back(path);
        }
    }
    
    if(wherefrom!=2 && canTravel(x,y,2))
    {
        path = solveMaze_helper(x-1,y,0);
        
        if(!path.empty() )
        {
            path.insert(path.begin(),1,2);
            allpath.push_back(path);
        }
    }
    
    if(wherefrom!=3 && canTravel(x,y,3))
    {
        path = solveMaze_helper(x,y-1,1);
        
        if(!path.empty() )
        {
            path.insert(path.begin(),1,3);
            allpath.push_back(path);
        }
    }
    
    
    vector<int> final;
 //   final = allpath[0];
   if(y == h-1)
{
final = vector<int>(1,-1);
} 
    for(vector<vector<int> >::iterator i = allpath.begin();
        i != allpath.end(); i++)
    {
        if(final.size()<i->size())
            final = *i;
	}    
    
    return final;
}

PNG* SquareMaze::drawMaze() const
{
    PNG* result = new PNG(w*10 + 1, h*10 + 1);
    int ww = result->width();
    int hh = result->height();
    // topmost
    for(int i = 10; i < ww; i++){
        (*result)(i,0)->red = 0;
        (*result)(i,0)->green = 0;
        (*result)(i,0)->blue = 0;
    }
    
    //leftmost
    for(int i = 0; i < hh; i++){
        (*result)(0,i)->red = 0;
        (*result)(0,i)->green = 0;
        (*result)(0,i)->blue = 0;
    }
    
    // cells
    for(int i = 0; i < w*h ; i++){
        
        int x = (i%w +1)*10;
        int y = (i/w)*10;
        
        if(right[i] == true)
        {
            for(int j = 0; j <=10; j++)
            {
                (*result)(x,y+j)->red = 0;
                (*result)(x,y+j)->green = 0;
                (*result)(x,y+j)->blue = 0;
            }
        }
        
        if(down[i] == true)
        {
            for(int j = 0; j <=10; j++)
            {
                (*result)(x-10+j,y+10)->red = 0;
                (*result)(x-10+j,y+10)->green = 0;
                (*result)(x-10+j,y+10)->blue = 0;
            }
        }
    }
    
    return result;
}

PNG* SquareMaze::drawMazeWithSolution()
{
    // Initialization
    vector<int> finalpath = solveMaze();
    PNG * picture = drawMaze();
    
    int steps = finalpath.size();
    int x =5;
    int y = 5;
    
    
    for(int i =0; i < steps; i++)
    {
        if(finalpath[i] == 0)
        {
            for(int j =0; j < 11; j++)
            {
                (*picture)(x+j,y)->red = 255;
                (*picture)(x+j,y)->green = 0;
                (*picture)(x+j,y)->blue = 0;
            }
            
            x +=10;
        }
        else if(finalpath[i] ==1)
        {
            for(int j =0; j < 11; j++)
            {
                (*picture)(x,y+j)->red = 255;
                (*picture)(x,y+j)->green = 0;
                (*picture)(x,y+j)->blue = 0;
            }
            y+=10;
            
        }
        else if(finalpath[i] ==2)
        {
            for(int j =0; j < 11; j++)
            {
                (*picture)(x-j,y)->red = 255;
                (*picture)(x-j,y)->green = 0;
                (*picture)(x-j,y)->blue = 0;
            }
            
            x-=10;
        }
        else
        {
            for(int j =0; j < 11; j++)
            {
                (*picture)(x,y-j)->red = 255;
                (*picture)(x,y-j)->green = 0;
                (*picture)(x,y-j)->blue = 0;
            }
            
            y -=10;
        }
    }
    
    //exit
    // cell x
    int cellx = x/10;
    for(int j =1; j < 10; j++)
    {
        (*picture)(cellx*10+j,h*10)->red = 255;
        (*picture)(cellx*10+j,h*10)->green= 255;
        (*picture)(cellx*10+j,h*10)->blue= 255;

    }
    
    return picture;
}
