/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on July 22, 2013, 10:26 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 *   Given an array of integers from 0 through n, except one integer, find the
 *   missing number. We cannot access an entire integer in the array with a 
 *   single operation. The elements of A are represented in binary, and the 
 *   only operation we can use to access them is "fetch the jth bit in A[i].
 *   Find the missing integer in O(n) time.
 */

int get_bit(int num, int column) {
    
    return(num & (1 << column));
}

int find_missing_number(vector<int> array, int column) {
    
    if(column >= sizeof(int)) {
        return 0;
    }
    
    vector<int> one_bits;
    vector<int> zero_bits;
    
    for(int i=0; i < array.size(); i++) {
        if(get_bit(array[i], column) == 0) {
            zero_bits.push_back(array[i]);
        }
        else {
            one_bits.push_back(array[i]);
        }
    }
    
    if(zero_bits.size() <= one_bits.size()) {
        int v = find_missing_number(zero_bits, column + 1);
        return (v << 1) | 0;
    }
    else {
        int v = find_missing_number(one_bits, column + 1);
        return (v << 1) | 1;
    }
}

int find_missing_num(vector<int> array) {
    return(find_missing_number(array, 0));
}


int main(int argc, char** argv) {

    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12 };
    vector<int> input (array, array + sizeof(array) / sizeof(int));

    cout << "Missing number is " << find_missing_num(input);
    
}

