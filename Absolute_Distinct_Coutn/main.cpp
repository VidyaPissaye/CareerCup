/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on September 5, 2013, 11:28 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

/*
 *  Count the number of elements in an array a which are absolute distinct, 
 *  what it means is if an array had -3 and 3 in it these numbers are not 
 *  distinct because|-3|=|3|. 
 *  For example: a={-5,-3,0,1,-3} the result would be 4 because there are 4 absolute distinct elements in this array.
 *  a.length would be <=10000, assume that the array is sorted in ascending order
 */

int distinct_count(vector<int> arr) {
    set<int> myset;
    
    for(int i = 0; i < arr.size(); i++) {
        myset.insert(abs(arr[i]));
    }
    
    return myset.size();
}

int main(int argc, char** argv) {

    int elements[] = {-7, 1, 5, 2, -4, 3, 0, -3, -1};
    int length = sizeof(elements)/sizeof(int);
    vector<int> arr;
    
    for(int i = 0; i < length; i++) {
        arr.push_back(elements[i]);
    }
    
    cout << distinct_count(arr);
}

