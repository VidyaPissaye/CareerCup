/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on September 5, 2013, 4:31 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 *  Find an index in an array such that its prefix sum equals its suffix sum.
 *  Example: array: {-7, 1, 5, 2, -4, 3, 0}. Equilibrium index is 3 
 *  ( -7 + 1 + 5 = -4 + 3 )
 */

int find_equi(vector<int> array) {
    int right_sum = 0;
    
    for(int i = 0; i < array.size(); i++) {
        right_sum += array[i];
    }
    
    int left_sum = 0;
    
    for(int j = 0; j < array.size(); j++) {
        
        right_sum -= array[j];
        
        if(left_sum == right_sum)
            return j;
       
        left_sum += array[j];
    }
    
}

int main(int argc, char** argv) {

    int elements[] = {-7, 1, 5, 2, -4, 3, 0};
    int length = sizeof(elements)/sizeof(int);
    vector<int> arr;
    
    for(int i = 0; i < length; i++) {
        arr.push_back(elements[i]);
    }
    
    cout << find_equi(arr);
}

