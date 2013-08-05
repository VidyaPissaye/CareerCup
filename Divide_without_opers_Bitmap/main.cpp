/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on August 1, 2013, 1:33 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * Divide two integers without using multiplication, division and mod operator.
 */

int divide(int dividend, int divisor) {
        
        if(dividend < divisor)
            return 0;
            
        int div = divisor;
        int q = 1;
        
        while((div << 1) <= dividend) {
            q = q << 1;
            div = div << 1;
        }
        
        return(q + ((div == dividend) ? 0 : divide(dividend - div, divisor)));
        
    }
    
int main(int argc, char** argv) {

    cout << divide(25, 4);
}

