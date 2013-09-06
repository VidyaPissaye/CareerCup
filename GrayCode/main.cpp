/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on September 3, 2013, 4:57 PM
 */

#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

/*
 *  The gray code is a binary numeral system where two successive values differ in only one bit.
 *  Given a non-negative integer n representing the total number of bits in the code, 
 *  print the sequence of gray code. A gray code sequence must begin with 0.
 *  For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
 *  00 - 0
 *  01 - 1
 *  11 - 3 
 *  10 - 2
 */

void genGrayCode(int n, vector<int> &code, int num) {
    if(n >= 0) {
        if(n == 0) {
            code.push_back(num);
        }
        else {
            int zero = num;
            zero = zero << 1;
            genGrayCode(n-1, code, zero);
                
            int one = num;
            one = ((one << 1) | 1);
            genGrayCode(n-1, code, one);
        }
    }
}

vector<int> grayCode(int n) {
        
    vector<int> code;
    genGrayCode(n, code, 0);
    return code;
}

int main(int argc, char** argv) {

    vector<int> gcode = grayCode(4);
    
    int n = 0;
    while(n < gcode.size()) {
        cout << gcode[n++] << " ";  
    }
}

