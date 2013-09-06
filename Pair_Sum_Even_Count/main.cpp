/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on September 5, 2013, 3:53 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 *  Lets say you have array A[0]=1 A[1]=-1 ....A[n]=x
 *  Then what would be the smartest way to find out the number of times when A[i]+A[j] is even where i < j
 *  So if we have {1,2,3,4,5} we have 1+3 1+5 2+4 3+5 = 4 pairs which are even
 */

int pair_sum_even_count(vector<int> array) {
    int even_count = 0, odd_count = 0;
    for(int i = 0; i < array.size(); i++) {
        if(array[i] % 2 == 0)
            even_count++;
        else
            odd_count++;
    }
    
    return(((even_count * (even_count - 1))/2) + ((odd_count * (odd_count - 1))/2));
}

// Alternate method

int pair_sum_even_count(vector<int> array) {
    int even_count = 0, odd_count = 0;
    int count = 0;
    
    for(int i = 0; i < array.size(); i++) {
        if(array[i] % 2 == 0) {
            count += even_count;
            even_count++;
        }
        else {
            count += odd_count;
            odd_count++;
        }
    }
}

int main(int argc, char** argv) {

    int elements[] = {1, 2, 3, 4, 5};
    int length = sizeof(elements)/sizeof(int);
    vector<int> arr;
    
    for(int i = 0; i < length; i++) {
        arr.push_back(elements[i]);
    }
    
    cout << pair_sum_even_count(arr);
}

