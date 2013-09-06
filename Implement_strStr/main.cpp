/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on September 4, 2013, 5:00 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 * 
 */

char *strStr(char *haystack, char *needle) {
        
    char *first = NULL;
        
    if(strlen(needle) <= strlen(haystack)) {
            
        vector<char*> first_idx;
        char *ih = haystack;
        char *n = needle;
            
        while(*ih) {
            
            while((*ih) && *ih != *n) { 
                ih++;
            }
                
            char *nj = needle;
            first = ih;
        
            while((*nj) && (*ih) && (*ih == *nj)) {
                ih++;
                nj++;
   
                if(*ih == *n) {
                    char *ptr = ih;
                    first_idx.insert(first_idx.begin(), ptr);
                }
            }

            if(!*nj) {
                return first;
            }
            else {
                if(!first_idx.empty()) {
                    ih = first_idx.back();
                    first_idx.pop_back();
                }
            }
        }
    }

    return first;
}

int main(int argc, char** argv) {

    char *haystack = "mississippi";
    char *needle = "a";
    
    char *substr = strStr(haystack, needle);
    while(*substr) {
        cout << *substr;
        substr++;
    }
}

