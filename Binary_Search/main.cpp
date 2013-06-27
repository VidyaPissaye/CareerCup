/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on June 13, 2013, 1:50 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *   Binary Search
 */

int binary_search(int array[], int x, int low, int high) {
    
    int mid;
    
    while(low <= high) {
        mid = (low + high) / 2;
        if(array[mid] < x) {
            low = mid + 1;
        }
        else if(array[mid] > x) {
            high = mid - 1;
        }
        else {
            return mid;
        }
    }
    return -1;
    
}

int binary_search_recursive(int array[], int x, int low, int high) {
    if(low > high) {
        return -1;
    }
    
    int mid = (low + high) / 2;
        
    if(array[mid] < x) {
        return(binary_search_recursive(array, x, mid+1, high));
    }
    else if(array[mid] > x) {
        return(binary_search_recursive(array, x, low, mid-1));
    }
    else {
        return mid;
    }
}

int main(int argc, char** argv) {

    int arr[10] = {0, 1, 3, 4, 5, 6, 7, 8, 9, 12};
    int length = sizeof(arr)/sizeof(int);
    
    int x = 3;
    int index = binary_search(arr, x, 0, length-1);
    
    cout << "The element " << x << " is found at index: " << index << endl;
    
    x = 8;
    index = binary_search_recursive(arr, x, 0, length-1);
    cout << "The element " << x << " is found at index: " << index << endl;
}

