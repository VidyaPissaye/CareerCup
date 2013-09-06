/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on August 31, 2013, 6:52 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *  Given an array and a value, remove all instances of that value in place and return the new length.
 *  The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 */

int swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = x;
}

int removeElement(int A[], int n, int elem) {

    int i = 0;
    int length = n;
        
    while(i < length) {
        if(A[i] == elem) {
            swap(A[i], A[length-1]);
            length -= 1;
        }
        else {
            i++;
        }
    }

    return length;
}

int main(int argc, char** argv) {

    int array[] = {0, 4, 4, 0, 4, 4, 4, 0, 2};
    int remove_element = 4;
    int length = sizeof(array)/sizeof(int);
    
    cout << removeElement(array, length, remove_element);
}

