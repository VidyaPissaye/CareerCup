/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on April 1, 2013, 12:15 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *   Reverse a null terminated string
 */

void swap(char &x, char &y) {
    char temp;
    temp = x;
    x = y;
    y = temp;
}

void reverse(char* string) {
    
    int length = strlen(string);
    
    for(int i=0, j=(length-1); i <= length/2; i++, j--) {
        swap(string[i], string[j]);
    }
}

int main(int argc, char** argv) {

    char string[100];
    
    cout << "Enter a string to be reversed" << endl;
    cin >> string;
    
    reverse(string);
    cout << "The reversed string is: " << endl;
    cout << string;
}

