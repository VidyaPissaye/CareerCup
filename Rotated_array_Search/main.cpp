/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on June 16, 2013, 4:11 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *  Given a rotated sorted array of integers, search for a given element.
 */

int search_rotated_array(int array[], int low, int high, int key) {
    
    if(low > high) return -1;
    
    int mid = (low + high) / 2;
    
    if(key == array[mid]) {
        return mid;
    }
    else if(array[low] > array[mid]) {
        if((key >= array[low]) || (key < array[mid])) {
            return(search_rotated_array(array, low, mid-1, key));
        }
        else {
            return(search_rotated_array(array, mid+1, high, key));
        }
    }
    else {
        if((key > array[mid]) || (key <= array[high])) {
            return(search_rotated_array(array, mid+1, high, key));
        }
        else {
            return(search_rotated_array(array, low, mid-1, key));
        }
    }
}

int main(int argc, char** argv) {

    int arr[6] = {2, 2, 2, 3, 4, 2};
    int length = sizeof(arr)/sizeof(int);
    
    int x = 2;
    int index = search_rotated_array(arr, 0, length-1, x);
    
    cout << "The element " << x << " is found at index: " << index << endl;

}

