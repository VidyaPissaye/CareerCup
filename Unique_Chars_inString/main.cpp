/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on March 31, 2013, 7:31 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 * Implement an algorithm to determine if a string has all unique characters.
 * What if you cannot use additional datastructures.
 * 
 */

// Time Complexity: O(n^2)
bool Unique_Chars(char* string) {
    
    for(int i=0; i < (strlen(string)-1); i++) {
        for(int j=i+1; j < strlen(string); j++) {
            if(string[i] == string[j])
                return false;
        }
    }
    return true;
}

// If we can add datastructures then the solution will be of O(n)
// There are 256 characters (A, a ..)

bool Unique_Chars_ascii(char* string) {
    bool ascii[256] = {false};
    
    for(int i=0; i < strlen(string); i++) {
        int ascii_val = (int)string[i];
        if(ascii[ascii_val]) {
            return false;
        }
        ascii[ascii_val] = true;
    }
    return true;
}

int main(int argc, char** argv) {

    char string[10] = "Hello";
    bool unique = true;
    
    unique = Unique_Chars_ascii(string);
    
    if(unique)
        cout << "The string has unique characters" << endl;
    else
        cout << "The string doesn't have unique characters" << endl;
    
}

