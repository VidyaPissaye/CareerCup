/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on September 7, 2013, 5:03 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 *  write an algorithm that finds the subsequence with 
 *  largest sum of elements in an array. The elements in the array can be negative. 
 *  Time Complexity = O(n)
 *  Space Complexity = O(1)
 *  (Similar ti max stock profit DP solution.)
 */

int findMaxSubsequence(vector<int> A, int &low, int &high) {
    int idx_low = 0;
    int max_sum = 0, sum = 0;
    
    for(int i = 0; i < A.size(); i++) {
        sum += A[i];
        
        if(sum > max_sum) {
            max_sum = sum;
            
            if(idx_low != low) {
                low = idx_low;
                high = low + 1;
            }
            else {
                high = i + 1;
            }
            
        }
        
        if(sum < 0) {
            sum = 0;
            idx_low = i + 1;
        }
    }
    
    return max_sum;
}

int main(int argc, char** argv) {

    int elements[] = {1, 3, -4, -2, 3, 5, 4};
    
    int length = sizeof(elements)/sizeof(int);
    vector<int> arr;
    
    for(int i = 0; i < length; i++) {
        arr.push_back(elements[i]);
    }
    
    int low = 0, high = 0;
    
    cout << findMaxSubsequence(arr, low, high);
}

