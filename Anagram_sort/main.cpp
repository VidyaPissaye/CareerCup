/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on June 16, 2013, 12:03 AM
 */

#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;

/*
 *   Sort an array of strings so that all anagrams are next to each other.
 */

bool is_anagram(string str1, string str2) {
    
    if(str1.length() != str2.length())
        return false;
    
    // Assumption: ASCII character set
    int letter[256] = {0};
    
    for(int j=0; j < str1.length(); j++) {
        letter[str1[j]]++;
    }
    
    for(int i=0; i < str2.length(); i++) {
        if((--letter[str2[i]]) < 0)
            return false;
    }
        
    return true;
    
}

void swap_str(string &str1, string &str2) {
    str1.swap(str2);
}

void sort_anagrams(string (&anagram_arr)[6]) {
    int arr_len = sizeof(anagram_arr)/sizeof(string);
    
    for(int i=0; i < arr_len-1; i++) {
        int j = i+1;
        while((j < arr_len) && (i < arr_len-1)) {
            if(is_anagram(anagram_arr[i], anagram_arr[j])) {
                swap_str(anagram_arr[i+1], anagram_arr[j]);
                i++;
            }
            else {
                j++;
            }        
        }
    }
}

int main(int argc, char** argv) {

    string array[6] = {"god", "eat", "pale", "dog", "leap", "tea"};   
    
    sort_anagrams(array);
    
    int arr_len = sizeof(array)/sizeof(array[0]);
    
    cout << "Sorted anagram array is: " << endl;
    for(int i=0; i < arr_len; i++) {

        cout << "'" << array[i] << "', ";
    }
}

