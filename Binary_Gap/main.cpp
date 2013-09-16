/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on September 6, 2013, 11:49 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *  A binary gap within a positive integer N is any maximal sequence of 
 *  consecutive zeros that is surrounded by ones at both ends in the binary representation of N.
 *  For example, number 9 has binary representation 1001 and contains a binary gap of length 2. 
 *  The number 529 has binary representation 1000010001) and contains two binary gaps: 
 *  one of length 4 and one of length 3. The number 20 has binary representation 10100 and 
 *  contains one binary gap of length 1. The number 15 has binary representation 1111 and has no binary gaps.
 *  Time Complexity: O(lg(n))
 *  Space Complexity: O(1)
 */

int binGap(int N) {
    
    int max = 0;
    int count = 0;
    bool one_flag = false;
    
    while(N) {
        if(N % 2 == 1) {
            one_flag = true;
            if(count > max)
                max = count;
            count = 0;
        }
        else {
            if(one_flag == true)
	        count++;
        }
        N /= 2;
    }
    return max;
}

int main(int argc, char** argv) {

    cout << binGap(2147483647);
}

