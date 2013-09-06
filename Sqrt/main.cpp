/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on August 26, 2013, 12:35 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *  Implement int sqrt(int x).
 */

double sqrt(int x) {
    
    if(x<=1) return x;

    float left=0, right=x, mid;

    while( (left+(right-left)/2) >= 1 )
    {
        mid = left + (float)(right-left)/2;

        if(mid == (float)x/mid)
            return mid;
        else if((float)x/mid < mid)
            right=mid;
        else
            left=mid;
    }

    return left;
}
    
int main(int argc, char** argv) {

    cout << sqrt(2);
}

