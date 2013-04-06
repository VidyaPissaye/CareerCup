/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on April 1, 2013, 12:37 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *   Determine if a string is a permutation of other string
 */

bool permutation(char* str1, char* str2) {
    
    if(strlen(str1) != strlen(str2))
        return false;
    
    // Assumption: ASCII character set
    int letter[256] = {0};
    
    for(int j=0; j < strlen(str1); j++) {
        letter[str1[j]]++;
    }
    
    for(int i=0; i < strlen(str2); i++) {
        if((--letter[str2[i]]) < 0)
            return false;
    }
        
    return true;
    
}

int main(int argc, char** argv) {

    char string1[100] = "outlook";
    char string2[100] = "lookout";
    
    bool is_permuted = permutation(string1, string2);
    if(is_permuted)
        cout << "String 2 is a permutation of string 1" << endl;
    else
        cout << "String 2 is not a permutation of string 1" << endl;
}

