/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on September 11, 2013, 3:50 PM
 */

#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

/*
 *  A zero-indexed array A consisting of N integers is given. 
 * The dominator of array A is the value that occurs in more than half of the elements of A.
For example, consider array A such that
A[0] = 3    A[1] = 4    A[2] =  3
A[3] = 2    A[4] = 3    A[5] = -1
A[6] = 3    A[7] = 3
The dominator of A is 3 because it occurs in 5 out of 8 elements of A 
 * (namely in those with indices 0, 2, 4, 6 and 7) and 5 is more than a half of 8.
 * The function should return −1 if array A does not have a dominator.
Assume that:
N is an integer within the range [0..1,000,000];
each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].
For example, given array A such that
A[0] = 3    A[1] = 4    A[2] =  3
A[3] = 2    A[4] = 3    A[5] = -1
A[6] = 3    A[7] = 3
the function may return 0, 2, 4, 6 or 7, as explained above.
Complexity:
expected worst-case time complexity is O(N);
expected worst-case space complexity is O(1), beyond input storage (not counting the storage required for input arguments).
 */

int findDominant(vector<int> A) {
    int count = 0;
    int dominant;
    
    for(int i = 0; i < A.size(); i++) {
        if(count == 0) {
            dominant = A[i];
            count++;
        }
        else if(A[i] == dominant) {
            count++;
        }
        else 
            count--;
    }
    return dominant;
}

int main(int argc, char** argv) {

    int elements[] = {3, 4, 3, 2, 3, -1, 3, 3};
    
    int length = sizeof(elements)/sizeof(int);
    vector<int> arr;
    
    for(int i = 0; i < length; i++) {
        arr.push_back(elements[i]);
    }
    
    cout << findDominant(arr);
}

