// Author: Li Miao
// December 8, 2015

#ifndef MAZE_H
#define MAZE_H

#include<iostream>
#include<string>
#include<vector>
#include"dsets.h"
#include"png.h"
#include"rgbapixel.h"
#include <time.h> 
#include <stdlib.h>
#include <stdio.h> 

using namespace std;

class SquareMaze
{
public:
    SquareMaze();
    void makeMaze(int width, int height);
    bool canTravel(int x, int y, int dir) const;
    void setWall(int x, int y, int dir, bool exists);
    vector<int> solveMaze();
    PNG* drawMaze() const;
    PNG* drawMazeWithSolution();

private:
    PNG p;
    DisjointSets cells;
    int w,h;
    vector<bool> down;
    vector<bool> right;
    
    vector<int> solveMaze_helper(int x, int y, int wherefrom);

};




#endif /* MAZE_H */
