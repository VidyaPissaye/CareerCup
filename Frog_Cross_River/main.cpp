/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on September 6, 2013, 4:21 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <tr1/unordered_map>

using namespace std;

/*
 *  A small frog wants to get to the other side of a river. 
 * The frog is currently located at position 0, and wants to get to position X. 
 * Leaves fall from a tree onto the surface of the river.
You are given a non-empty zero-indexed array A representing the falling leaves. 
 * A[K] represents the position where one leaf falls at time K, measured in minutes.
The goal is to find the earliest time when the frog can jump to the other side of the river. 
 * The frog can cross only when leaves appear at every position across the river from 1 to X.
For example, you are given integer X = 5 and array A such that:
  A[0] = 1
  A[1] = 3
  A[2] = 1
  A[3] = 4
  A[4] = 2
  A[5] = 3
  A[6] = 5
  A[7] = 4
In minute 6, a leaf falls into position 5. This is the earliest time when leaves 
 * appear in every position across the river.
 * If the frog is never able to jump to the other side of the river, the function should return −1.
 */

int max(int x, int y) {
    if(x > y)
        return x;
    else
        return y;
}

int frogCrossingRiver(int X, vector<int> &A) {

    tr1::unordered_map<int, int> hash_map;

    if(X > A.size())
        return -1;
    
    for(int i = 0; i < A.size(); i++) {
        if(hash_map.count(A[i]) <= 0) {
           hash_map.insert(make_pair(A[i], i));
        }
    }

    int j = 1, crossing_minute = 0;

    while((j <= X) && (hash_map.count(j) > 0)) {
        crossing_minute = max(crossing_minute, hash_map[j]);
        j++;
    }

    return(j <= X ? -1 : crossing_minute);

}
int main(int argc, char** argv) {

    int elements[] = {1, 3, 1, 4, 2, 3, 5, 4};
    
    int length = sizeof(elements)/sizeof(int);
    vector<int> arr;
    
    for(int i = 0; i < length; i++) {
        arr.push_back(elements[i]);
    }
    
    int X = 6;
    
    cout << frogCrossingRiver(X, arr);
}

