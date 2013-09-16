/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on September 11, 2013, 4:56 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <tr1/unordered_map>

using namespace std;

/*
 *  A zero-indexed array A consisting of N integers is given. We visit the indexes of the array in the following way. 
 * In the first step we visit the index 0; in every subsequent step we move from the visited index K to the index:
  M = K + A[K]
provided M is within the array bounds. Otherwise, K is the last index visited.
Write a function:
int solution(const vector<int> &A);
that, given an array A, returns the number of indexes that cannot be visited by the described procedure.
For example, for the array:
  A[0] = 1    A[1] = 2    A[2] = 3

only index 2 cannot be visited, so the answer is 1.
For the array:
  A[0] = 3    A[1] = -5   A[2] = 0    A[3] = -1   A[4] = -3

indexes 1 and 4 cannot be visited, so the answer is 2.
Assume that:
N is an integer within the range [0..200,000];
each element of array A is an integer within the range [−1,000,000..1,000,000].
Complexity:
expected worst-case time complexity is O(N*log(N));
expected worst-case space complexity is O(N*log(N)), beyond input storage (not counting the storage required for input arguments).
 * 
 */

int indexJump(const vector<int> &A) {

    int count = 0;
    
    if(A.size() > 0) {
        int k = 0;
        tr1::unordered_map<int, bool> hash_map;

        int i = 0;

        while(hash_map.count(i) <= 0) {
            hash_map.insert(make_pair(i, true));
            k = i + A[i];

            if((k < 0) || k >= A.size()) {
                k = i;
            }

            i = k;
        }

        for(int i = 0; i < A.size(); i++) {
            if(hash_map.count(i) <= 0)
                count++;
        }      
    }
    return count;
}

int main(int argc, char** argv) {
    int elements[] = {3, -5, 0, -1, -3};
    
    int length = sizeof(elements)/sizeof(int);
    vector<int> arr;
    
    for(int i = 0; i < length; i++) {
        arr.push_back(elements[i]);
    }
    
    cout << indexJump(arr);
}

