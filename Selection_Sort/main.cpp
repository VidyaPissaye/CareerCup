/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on June 13, 2013, 12:34 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *  Selection Sort
 */

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void selection_sort(int n, int (&array)[10]) {
    for(int i=0; i < (n-1); i++) {
        for(int j=(i+1); j < n; j++) {
            if(array[i] > array[j]) {
                swap(array[i], array[j]);
            }
        }
    }
}

int main(int argc, char** argv) {

    int arr[10] = {5, 7, 8, 3, 1, 4, 12, 9, 0, 6};
    int length = sizeof(arr)/sizeof(int);
    selection_sort(length, arr);
    
    cout << "The sorted array is: " << endl;
    for(int i=0; i < length; i++) {
        cout << arr[i] << " ";
    }
}

