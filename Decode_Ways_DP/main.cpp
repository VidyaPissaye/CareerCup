/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on August 2, 2013, 10:56 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *  A message containing letters from A-Z is being encoded to numbers using the following mapping:
 * 'A' -> 1, 'B' -> 2  ... 'Z' -> 26
 *  Given an encoded message containing digits, determine the total number of ways to decode it.

 *  For example,
 *  Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 *  The number of ways decoding "12" is 2.
 */ 

int numDecodings(string s) {
        
    if (s.empty()) return 0;
    int len = s.size();
    if (len < 1) return 0;
    int numarray[len];
    int i = len - 1;
    if (s[i] > '9' || s[i] < '0') return 0;
    else {
        numarray[i] = (s[i] == '0') ? 0 : 1;
        i--;
    }
    
    if (i >= 0) {
        if (s[i] > '9' || s[i] < '0') return 0;
        if (s[i] == '0') numarray[i] = 0;
        else if (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))
            numarray[i] = numarray[i+1] + 1;
        else
            numarray[i] = numarray[i+1];
        i--;
    }
    while (i >= 0) {
        if (s[i] > '9' || s[i] < '0') return 0;
        if (s[i] == '0') numarray[i] = 0;
        else if (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))
            numarray[i] = numarray[i+1] + numarray[i+2];
        else
            numarray[i] = numarray[i+1];
        i--;
    }
    return numarray[0];
}
    
int main(int argc, char** argv) {

    cout << numDecodings("21");
}

