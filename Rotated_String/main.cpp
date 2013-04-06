/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on April 1, 2013, 5:30 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

/*
 *   Given 2 strings s1 and s2, check if s2 is a rotation of s1 using only
 *   one call to isSubstring (method that checks if one word is a 
 *   substring of another.)
 */

// Technique 1: 
bool rotated_string(char* str1, char* str2) {

    if(strlen(str1) == strlen(str2)) {
        
        char second_str[strlen(str1)];
        char first_str[strlen(str1)];
       
        int i = 0, j = 0;
        while(j < strlen(str2)) {

            int x=0;
            while(str2[j] != str1[i]) { i++; }
            
            while((str2[j] == str1[i]) && str1[i]) {
                second_str[x++] = str1[i];
                i++;
                j++;
            }
            second_str[x] = '\0';
            
            if(str1[i]) {
                j = 0;
            }
            else {
                int k = 0;
                while(str2[j]) {
                    first_str[k] = str2[j];
                    k++;
                    j++;
                }
                first_str[k] = '\0';
            }
        }
        char str[strlen(str1)];
        strcat(str, first_str);
        strcat(str, second_str);
        
        char* ptr = strstr(str1, str);
        
        if(ptr) 
            return true;
        else
            return false;
        
    }    
}

// Technique 2: 
// Rotated string should be substring of original string repeated twice
bool is_rotation(string s1, string s2) {
    int length = s1.length();
    
    if((length == s2.length()) && length > 0) {
        string s = s1 + s1;
        unsigned found = s.find(s2);
        if(found != std::string::npos) 
            return true;
        else
            return false;
        
    }
}

int main(int argc, char** argv) {

    char string1[12] = "waterbottle";
    char string2[12] = "ttlewaterbo";
    
    bool is_rotated = rotated_string(string1, string2);
    
    if(is_rotated)
        cout << string2 << " is rotated string of " << string1 << endl;
    else
        cout << string2 << " is not a rotated string of " << string1 << endl;
    
    string s1 = "waterbottle";
    string s2 = "erbottlewat";
    
    is_rotated = is_rotation(s1, s2);
    
    if(is_rotated)
        cout << s2 << " is rotated string of " << s1 << endl;
    else
        cout << s2 << " is not a rotated string of " << s1 << endl;
}

