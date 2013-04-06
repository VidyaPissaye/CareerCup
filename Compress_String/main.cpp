/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on April 1, 2013, 12:47 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *   Basic string compression using counts of repeated characters.
 *   Example: abbbccaaa = a1b3c2a3.
 *   If compressed string is same length as original string, 
 *   return original string.
 */

int compression_count(char* string) {
    if(string == NULL || strlen(string) == 0) return 0;
    
    int i=0;
    char last = string[0];
    int count = 1;
    while(i < strlen(string)) {
        if(last != string[i]) {
            last = string[i];
            count++;
        }
        i++;
    }
    return (count*2);
}

void compress_string(char* string) {
 
    int size = compression_count(string);
    
    if(size < strlen(string)) {
        char* compressed_string = new char[size];

        int i = 1, j = 0, val = 1;
        compressed_string[0] = string[0];

        while(i < strlen(string)) {
            if(compressed_string[j] == string[i]) {
                val++;
            }
            else {
                compressed_string[++j] = val + '0';
                compressed_string[++j] = string[i];
                val = 1;
            }
            i++;
        }
        compressed_string[++j] = val + '0';
        strcpy(string, compressed_string);
        string[size] = '\0';
    }
}

int main(int argc, char** argv) {

    char string1[11] = "abbcccddd";
    compress_string(string1);
    cout << "Compressed string is: " << string1 << endl;
    
    char string2[11] = "abbcccdde";
    compress_string(string2);
    cout << "Compressed string is: " << string2;
}

