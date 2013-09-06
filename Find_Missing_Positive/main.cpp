/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on August 30, 2013, 3:57 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *  Given an unsorted integer array, find the first missing positive integer.
 *  For example,
 *  Given [1,2,0] return 3, 
 *  and [3,4,-1,1] return 2.
 *  Your algorithm should run in O(n) time and uses constant space.
 */

int firstMissingPositive(int A[], int n) {
        
    int i = 0;
     while (i < n)
     {
         if (A[i] != (i+1) && A[i] >= 1 && A[i] < n && A[A[i]-1] != A[i])
             swap(A[i], A[A[i]-1]);
         else
             i++;
     }
         
     for (i = 0; i < n; ++i)
         if (A[i] != (i+1))
             return i+1;
     return n+1;
}
    
int main(int argc, char** argv) {

    int arr[] = {3, 4, -1, 1};
    int size = sizeof(arr)/sizeof(int);
    
    cout << firstMissingPositive(arr, size);
}

