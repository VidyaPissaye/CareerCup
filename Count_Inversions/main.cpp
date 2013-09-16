/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on September 8, 2013, 4:50 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 *  A zero-indexed array A of N integers is given. 
 * An inversion is a pair of indexes (P, Q) such that P < Q and A[Q] < A[P].
 * Assume that:
N is an integer within the range [0..100,000];
each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].
For example, in the following array:
A[0] = -1 A[1] = 6 A[2] = 3
A[3] =  4 A[4] = 7 A[5] = 4
there are four inversions:
  (1,2)  (1,3)  (1,5)  (4,5)
so the function should return 4.
Complexity:
expected worst-case time complexity is O(N*log(N));
expected worst-case space complexity is O(N)
 */

int countInversions(vector<int> &A, int low, int mid, int high) {

    vector<int> left, right;
    int count = 0;

    for(int i = 0; i <= mid; i++) {
        left.push_back(A[i]);
    }

    for(int j = mid+1; j <= high; j++) {
        right.push_back(A[j]);
    }

    int l = 0, r = 0;

    while(l < left.size() || r < right.size()) {
        if(l == left.size()) {
            A[l+r] = right[r];
            r++;
        }
        else if (r == right.size()) {
            A[l+r] = left[l];
            l++;
        }
        else if (left[l] <= right[r]) {
            A[l+r] = left[l];
            l++;
        }
        else {
            A[l+r] = right[r];
            r++;
            count += left.size() - l;
        }
    }
    return count;
}

int getInversion(vector<int> &A, int low, int high) {

    if(low < high) {
        int mid = (low + high) / 2;
        return(getInversion(A, low, mid) + getInversion(A, mid+1, high) + countInversions(A, low, mid, high));
    }
    return 0;
}

int Inversions(const vector<int> &A) {

    vector<int> arr;

    for(int i = 0; i < A.size(); i++) {
        arr.push_back(A[i]);
    }

    return(getInversion(arr, 0, arr.size()-1));
}

// Alternate method

int bin_search(vector<int> arr, int x, int low, int high) {
    
    int mid; 
    
    while(low <= high) {
        mid = (low + high)/2;
        if(arr[mid] == x) {
            int i = mid - 1;
            while(i >= low && arr[i] == x) {
                i--;
            }
            i++;
            return i;
        }
        else if(arr[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }    
    
    return -1;
}

int countArrayInversions(const vector<int> &A) {
   
    vector<int> B;
    B = A;
    
    std::sort(B.begin(), B.end());
    
    int count = 0;
    
    for(int j = 0; j < A.size(); j++) {
        int index = bin_search(B, A[j], 0, B.size()-1);
        if(index > 0)
            count += index;
        
        B.erase(B.begin() + index);
    }
    
    return count;
}

int main(int argc, char** argv) {

    int elements[] = {-1, 6, 3, 4, 7, 4};
    
    int length = sizeof(elements)/sizeof(int);
    vector<int> arr;
    
    for(int i = 0; i < length; i++) {
        arr.push_back(elements[i]);
    }
    
    cout << countArrayInversions(arr);
}

