/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on June 22, 2013, 1:08 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *   Insert a 32-bit number, M, into another 32-bit number, N, such that M 
 *   starts at bit j and ends at bit i.
 *   Eg: N = 10000000000, M = 10011, i = 2, j = 6
 *   Result: N = 10001001100
 */

bool getbit(int num, int i) {
    return((num & (1 << i)) != 0);
}

int setbit(int num, int i) {
    return((num | (1 << i)));
}

int clearbit(int num, int i) {
    return(num & (~(1 << 1)));
}

int clearMSB_to_i(int num, int i) {
    int mask = (1 << 1) - 1;
    return (num & mask);
}

int clearbits_to0(int num, int i) {
    int mask = ~((1 << (i+1)) - 1);
    return (num & mask);
}

int updatebit(int num, int i, bool v) {
    int mask = ~(1 << i);
    return ((num & mask) | (v << i));
}

int insert_num(int num1, int num2, int i, int j) {
    int newnum2 = num2 << i;
    
    for(int bit = i; bit <= j; bit++) {
        num1 = updatebit(num1, bit, getbit(newnum2, bit));
    }
    return num1;
}

int main(int argc, char** argv) {

    cout << insert_num(10, 20, 2, 6);
}

