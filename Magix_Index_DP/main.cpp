/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on May 28, 2013, 11:43 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *  A magic index in an array A[0 ... n-1] is defined to be an index such that
 *  A[i] = i. Given a sorted array of distinct integers, write a method to find
 *  a magic index, if one exists.
 * 
 *  What if the values are not distinct.
 */

// Brute-force
int find_magic_index_brute(int array[]) {
    int size = sizeof(array);
    for(int i = 0; i < size; i++) {
        if(i == array[i]) {
            return i;
        }
    }
    return -1;
}

int find_magic_index_distinct(int array[], int low, int high) {
    
    if(high < low) {
        return -1;
    }
    
    int mid = (low+high)/2;
    
    if(array[mid] == mid) {
        return mid;
    }
    else if (array[mid] > mid) {
        return(find_magic_index_distinct(array, low, mid-1));
    }
    else {
        return(find_magic_index_distinct(array, mid+1, high));
    }
}

int min_element(int x, int y) {
    if(x < y)
        return x;
    else
        return y;
}

int find_magic_index(int array[], int low, int high) {
    if(low > high) {
        return -1;
    }
    
    int mid = (low+high)/2;
    
    if(array[mid] = mid) {
        return mid;
    }
    
    int left_high = min(mid-1, array[mid]);
    
    int left = find_magic_index(array, low, left_high);
    if(left >= 0) 
        return left;
    
    int right = find_magic_index(array, mid+1, high);
    if(right >= 0)
        return right;
}

int main(int argc, char** argv) {

    //int arr[11] = {-40, -20, -1, 1, 2, 3, 5, 7, 9, 12, 13};
    int array[11] = {-10, -5, 2, 2, 3, 4, 5, 7, 9, 12, 13};
    
   // int magic_index = find_magic_index_distinct(arr, 0, 10);
   // cout << "The magic index with distinct elements in array is: " << magic_index << endl;
    
    int magic_idx = find_magic_index(array, 0, 10);
    cout << "The magic index is: " << magic_idx;
}

