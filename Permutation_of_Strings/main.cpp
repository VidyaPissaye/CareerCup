/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on July 1, 2013, 5:31 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 *  Compute all permutations of a string. 
 */

void create_string(char letter, int pos, string &str) {
    string str1 = str.substr(0, pos);
    string str2 = str.substr(pos);
    str = str1 + letter + str2;
    
}

int permutation_str(int n, string str, string[] perm_str) {
    if(n == 0) {
        return 0;
    }
    else if(n == 1) {
        string s = str[n-1];
        strcpy(perm_str[0], s);
        return 1;
    }
    
    char a = str[n-1];
    permutation_str(n-1, str, perm_str);
    
    for(i=0; i < perm_str.length; i++) {
        for(int j=0; j <= perm_str[i].length; j++) {
            create_string(a, j, perm_str[i]);
        }
    }
}

int main(int argc, char** argv) {

    string array[];
}

