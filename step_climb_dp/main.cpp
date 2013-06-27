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

int staircase(int steps) {
    
    int stairs[100] = {0};
    
    stairs[1] = 1;
    stairs[2] = 2;
    stairs[3] = 4;
    
    for(int i=4; i <= steps; i++) {
        stairs[i] = stairs[i-1] + stairs[i-2] + stairs[i-3];
    }
    
    return stairs[steps];
}

int main(int argc, char** argv) {

    int possible_ways = staircase(5);
    
    cout << "Possible to climb the steps is " << possible_ways;
}

