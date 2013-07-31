/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on June 12, 2013, 11:49 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *  Bubble Sort
 */

#define max 10

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void bubble_sort(int n, int (&array)[max]) {
    for(int i=0; i < n; i++) {
        for(int j=0; j < (n-i-1); j++) {
            if(array[j] > array[j+1]) {
                swap(array[j], array[j+1]);
            }
        }
    }
}

int main(int argc, char** argv) {

    int arr[max] = {5, 7, 8, 3, 1, 4, 12, 9, 0, 6};
    int length = sizeof(arr)/sizeof(int);
    bubble_sort(length, arr);
    
    cout << "The sorted array is: " << endl;
    for(int i=0; i < length; i++) {
        cout << arr[i] << " ";
    }
}

