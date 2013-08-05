/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on April 19, 2013, 12:34 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *  A child is running up a staircase with n steps, and can hop either 1 step, 
 *  2 steps, or 3 steps at a time. Implement a method to count 
 *  how many possible ways the child can run up the stairs.
 */

#define max 10

int staircase(int steps, int (&stairs)[max]) {
    
    if(steps < 0) {
        return 0;
    }
    else if(steps == 0) {
        return 1;
    }
    else if(stairs[steps] > -1) {
        return stairs[steps];
    }
    else {       
        stairs[steps] = staircase(steps-1, stairs) + staircase(steps-2, stairs) + staircase(steps-3, stairs);
    }
    
    return stairs[steps];
}

int main(int argc, char** argv) {

    int stair_array[max] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    
    int possible_ways = staircase(5, stair_array);
    
    cout << "Possible to climb the steps is " << possible_ways;
}

