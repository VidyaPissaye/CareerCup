/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on July 21, 2013, 8:42 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *  Swap odd and even bits in an integer with as few instructions as possible.
 *  eg., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped.
 */

int swap_even_odd_bits(int num) {
    int even_mask = 0, odd_mask = 0XAA;
    
    even_mask = odd_mask >> 1;

    return (((num & odd_mask) >> 1) | ((num & even_mask) << 1));
}

int main(int argc, char** argv) {

    cout << swap_even_odd_bits(230);
}

