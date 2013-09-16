/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on September 6, 2013, 3:38 PM
 */

#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

/*
 *  A non-empty zero-indexed array A consisting of N integers is given.
A permutation is a sequence containing each element from 1 to N once, and only once.
For example, array A such that:
    A[0] = 4
    A[1] = 1
    A[2] = 3
    A[3] = 2
is a permutation, but array A such that:
    A[0] = 4
    A[1] = 1
    A[2] = 3
is not a permutation.
The goal is to check whether array A is a permutation.
Write a function:
class Solution { public int solution(int[] A); }
that, given a zero-indexed array A, returns 1 if array A is a permutation and 0 if it is not.
For example, given array A such that:
   A[0] = 4
    A[1] = 1
    A[2] = 3
    A[3] = 2
the function should return 1.
Given array A such that:
    A[0] = 4
    A[1] = 1
    A[2] = 3
the function should return 0.
Assume that:
N is an integer within the range [1..100,000];
each element of array A is an integer within the range [1..1,000,000,000].
Complexity:
expected worst-case time complexity is O(N);
expected worst-case space complexity is O(N), 
 */

int permSeq(vector<int> A) {
    set<int> my_set;
    
    for(int i = 0; i < A.size(); i++) {
        if(A[i] > 0 && A[i] <= A.size())
            my_set.insert(A[i]);
    }
    
    if(A.size() == my_set.size())
        return 1;
    
    return 0;
}

int main(int argc, char** argv) {

    int elements[] = {5, 1, 2, 4, 3};
    int length = sizeof(elements)/sizeof(int);
    vector<int> arr;
    
    for(int i = 0; i < length; i++) {
        arr.push_back(elements[i]);
    }
    
    cout << permSeq(arr);
}

