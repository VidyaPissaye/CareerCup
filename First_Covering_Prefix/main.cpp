/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on September 7, 2013, 5:41 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

/*
 *  en. The first covering prefix of array A is the smallest integer P such that
 *  0≤P<N and such that every value that occurs in array A also occurs in sequence A[0], A[1], ..., A[P].
 *  For example, the first covering prefix of the following 5−element array A:
 *  A[0] = 2  A[1] = 2  A[2] = 1
 *  A[3] = 0  A[4] = 1
 *  is 3, because sequence [ A[0], A[1], A[2], A[3] ] equal to [2, 2, 1, 0], 
 *  contains all values that occur in array A.
 */


int firstCoveringPrefix(const vector<int> &A) {

    set<int> my_set;
    int first_covering_prefix = -1;
    
    for(int i = 0; i < A.size(); i++) {
        if(my_set.count(A[i]) == 0) {
            my_set.insert(A[i]);
            first_covering_prefix = i;
        }
    }
    
    return first_covering_prefix;
}

int main(int argc, char** argv) {

    int elements[] = {2, 2, 1, 0, 1};
    
    int length = sizeof(elements)/sizeof(int);
    vector<int> arr;
    
    for(int i = 0; i < length; i++) {
        arr.push_back(elements[i]);
    }
    
    cout << firstCoveringPrefix(arr);
}

