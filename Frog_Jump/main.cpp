/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on September 6, 2013, 10:47 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *  A small frog wants to get to the other side of the road. 
 *  The frog is currently located at position X and wants to get to a position 
 *  greater than or equal to Y. The small frog always jumps a fixed distance, D.
 *  Count the minimal number of jumps that the small frog must perform to reach its target.
 *  Assume that: X, Y and D are integers within the range [1..1,000,000,000].
 *  Time and Space Complexity = O(1)
 */

int frogJump(int X, int Y, int D) {
    if((Y - X) % D == 0)
        return ((Y - X)/D);
    else
        return (((Y - X)/D) + 1);
}

int main(int argc, char** argv) {

    int X = 10, Y = 85, D = 30;
    
    cout << frogJump(X, Y, D);
}

