/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on September 6, 2013, 6:19 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 *   You are given N counters, initially set to 0, and you have two possible operations on them:
increase(X) − counter X is increased by 1,
max_counter − all counters are set to the maximum value of any counter.
A non-empty zero-indexed array A of M integers is given. This array represents consecutive operations:
if A[K] = X, such that 1 ≤ X ≤ N, then operation K is increase(X),
if A[K] = N + 1 then operation K is max_counter.
For example, given integer N = 5 and array A such that:
    A[0] = 3
    A[1] = 4
    A[2] = 4
    A[3] = 6
    A[4] = 1
    A[5] = 4
    A[6] = 4
the values of the counters after each consecutive operation will be:
    (0, 0, 1, 0, 0)
    (0, 0, 1, 1, 0)
    (0, 0, 1, 2, 0)
    (2, 2, 2, 2, 2)
    (3, 2, 2, 2, 2)
    (3, 2, 2, 3, 2)
    (3, 2, 2, 4, 2)
The goal is to calculate the value of every counter after all operations.
 * 
 * the function should return [3, 2, 2, 4, 2], as explained above.
Assume that:
N and M are integers within the range [1..100,000];
each element of array A is an integer within the range [1..N + 1].
 * 
 * Complexity:
expected worst-case time complexity is O(N+M);
expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
 */

vector<int> incrementCounters(int N, vector<int> &A) {
 
    vector<int> counters(N);
    
    int max_counter_val = 0; 
    int reset_counters = 0;
    
    for(int i = 0; i < A.size(); i++) {
    
        if(A[i] == (N + 1)) {
            reset_counters = max_counter_val;    
        }
        else {
            if(counters[A[i]-1] < reset_counters)
                counters[A[i]-1] = reset_counters + 1;
            else
	        counters[A[i]-1]++;
            
            if(counters[A[i]-1] > max_counter_val)        
            	max_counter_val = counters[A[i]-1];
        }
    
    }
    
    for(int j = 0; j < N; j++) {
        if(counters[j] < reset_counters)
            counters[j] = reset_counters;
    }
    
    return counters;
}

int main(int argc, char** argv) {

    int elements[] = {3, 4, 4, 6, 1, 4, 4};
    
    int length = sizeof(elements)/sizeof(int);
    vector<int> arr;
    
    for(int i = 0; i < length; i++) {
        arr.push_back(elements[i]);
    }
    
    int N = 5;
    
    vector<int> counters =  incrementCounters(N, arr);
    
    for(int i = 0; i < N; i++) {
        cout << counters[i] << " ";
    }
}

