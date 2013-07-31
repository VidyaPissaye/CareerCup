/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on July 21, 2013, 1:23 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *  Determine the number of bits required to convert integer A to integer B.
 *  Eg: input: 31, 14
 *      output: 2
 */


int count_bits_to_convert_number(int num1, int num2) {
    int xornum = num1 ^ num2;
    int bit_count = 0;
    
    for(int i = 0; i < 32; i++) {
        if(xornum & (1 << i)) {
            bit_count += 1;
        }
    } 
    
   /* for(int j = xornum; j != 0; j = j >> 1) {
        bit_count += j & 1;
    } */
    
    return bit_count;
}

// Alternate method
// Flips LSB and count how long it takes c to become 0 (indicates the number of 1s).

int count_bits_to_convert_number_flip_LSB(int num1, int num2) {
    int bit_count = 0;
    
    for(int c = num1 ^ num2; c != 0; c = (c & (c-1))) {
        bit_count++;
    }
    
    return bit_count;
}

int main(int argc, char** argv) {

    int num1 = 31, num2 = 14;
    cout << "Number of bits to convert "<< num1 << " to " << num2 << " is: " << count_bits_to_convert_number(num1, num2);
}

