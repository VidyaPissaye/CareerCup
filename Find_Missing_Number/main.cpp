/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on September 6, 2013, 11:20 AM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 *  A zero-indexed array A consisting of N different integers is given. 
 *  The array contains integers in the range [1..(N + 1)], which means that exactly one element is missing. 
 *  Your goal is to find that missing element.
 *  Assume that:
 *  N is an integer within the range [0..100,000];
 *  the elements of A are all distinct;
 *  each element of array A is an integer within the range [1..(N + 1)].
 *  Complexity:
 *  expected worst-case time complexity is O(N);
 *  expected worst-case space complexity is O(1), beyond input storage (not counting the storage required for input arguments).
 *  Elements of input arrays can be modified.
 */ 

int findMissingNumber(vector<int> &A) {
    
    int sum = 0;
    
    for(int i = 0; i < A.size(); i++) {
    	sum += A[i];    
    }
    
    return(((A.size() + 1) * ((A.size() + 1) + 1) / 2) - sum);
}

int main(int argc, char** argv) {

    vector<int> A;
    
    cout << findMissingNumber(A);
}

