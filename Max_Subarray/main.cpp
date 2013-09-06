/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on August 27, 2013, 6:50 PM
 */

#include <cstdlib>

using namespace std;

/*
 *  Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 *  For example, given the array [−2,1,−3,4,−1,2,1,−5,4], 
 *  the contiguous subarray [4,−1,2,1] has the largest sum = 6.
 */

int maxSubArray(int A[], int n) {
        
    int max_sum = -12323234, max_st_idx = 0, max_end_idx = 0, sum = 0;
        
    if(n == 1)
        max_sum = A[0];
        
    for(int i = 0; i < n ; i++) {
        sum = 0;
            
        for(int j = i; j < n; j++) {
            sum += A[j];
                           
            if(sum > max_sum) {
                max_sum = sum;
                max_st_idx = i;
                max_end_idx = j;
            }
        }
    }
    return max_sum;
}

int main(int argc, char** argv) {

    return 0;
}

