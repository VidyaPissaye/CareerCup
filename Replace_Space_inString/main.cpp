/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on April 1, 2013, 11:21 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *   Replace spaces in given string with '%20'
 *   Assumption: The string is large enough to take in the additional characters
 */

void replace_spaces(char* string) {
    int length = strlen(string);
    int addn_spaces_count = 0;
    int i = 0;
    
    while(i < length) {
        if(string[i] == ' ') {
            addn_spaces_count++;
        }
        i++;
    }
    
    int final_length = length + (addn_spaces_count * 2);
    string[final_length] = '\0';
    i = final_length-1;
    int j = length - 1;
    while(j >= 0) {
        if(string[j] != ' ') {
            string[i] = string[j];
        }
        else {
            string[i--] = '0';
            string[i--] = '2';
            string[i] = '%';
        }
        i--;
        j--;
    }
        
}

int main(int argc, char** argv) {

    char string[50] = " This is a good exercise!";
    
    replace_spaces(string);
    cout << string;
}

