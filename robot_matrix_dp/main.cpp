/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on April 19, 2013, 12:38 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 *  Imagine a robot sitting on the upper left corner of an X by Y grid. 
 *  The robot can only move in two directions: right and down. 
 *  How many possible paths are there for the robot to go from (0,0) to (X, Y)?
 */

struct point {
    int x;
    int y;
};

bool robot_move_reverse(int x, int y, vector<point*> &path) {
    point *p = (point*)malloc(sizeof(point));
    p->x = x;
    p->y = y;
    
   // path.push_back(p);
    
    if(x == 0 && y == 0) {
        return true;
    }
    
    bool success = false;
    
    if(x >= 1) {
        success = robot_move_reverse(x-1, y, path);
    }
    
    if(!success && y >= 1) {
        success = robot_move_reverse(x, y-1, path);
    }
    
    if(success) {
        path.push_back(p);
    }
    
    return success;
}

int robot_move(int x, int y) {
    int grid[x+1][y+1];
    
    for(int i=0; i<=x; i++) {
        grid[0][i] = 1;
    }
    
    for(int j=0; j<=y; j++) {
        grid[j][0] = 1;
    }   
    
    for(int i=1; i<=x; i++) {
        for(int j=1; j<=y; j++) {
            grid[i][j] = grid[i-1][j] + grid[i][j-1];
        }
    }
    return grid[x][y];
}



int main(int argc, char** argv) {

    int possible_moves = robot_move(6, 5);
    cout << "The robot can reach (X, Y) is " << possible_moves << endl;
    
    vector<point*> paths;
    
    int moves = robot_move_reverse(6, 5, paths);
    cout << "The robot can reach (X, Y) is " << paths.size();
    
}

