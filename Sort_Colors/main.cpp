/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on August 26, 2013, 11:37 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *  Given an array with n objects colored red, white or blue, sort them so 
 *  that objects of the same color are adjacent, with the colors in the order 
 *  red, white and blue. 
 *  Here, we will use the integers 0, 1, and 2 to represent the color red, 
 *  white, and blue respectively.
 */

void display(int A[], int n) {
    for(int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
}

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}
    
 void sortColors(int A[], int n) {
        
    int color = 0;
    int ptr = 0;
        
    while((ptr < n - 1) && (color < 2)) {

        int track = ptr;
        while((track < n) && (A[track] != color)) {
            track++;
        }
            
        if(track != n) {
            swap(A[track], A[ptr]);
            track++;

            while( track < n) {
                if(A[ptr] == A[track]) {
                    ptr++;
                    swap(A[ptr], A[track]);
                }
                track++;
            }
            ptr++;
        }
        color++;     
    }
        
    display(A, n);
}
        
int main(int argc, char** argv) {

    int array[] = {1, 2, 0, 1, 0, 2, 2, 0, 1};
    int n = sizeof(array)/sizeof(int);
    sortColors(array, n);
}

