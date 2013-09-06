/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on June 7, 2013, 2:41 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

/*
 *   Print all valid combinations of n-pairs of parenthesis
 */

#define max 50

char* append_parenthesis_before(char* pair) {
    char* new_pair = new char[max];
    int i = 0, j = 0;
    new_pair[i++] = '(';
    new_pair[i++] = ')';
    while(j < strlen(pair)) {
        new_pair[i++] = pair[j++];
    }
    new_pair[i] = '\0';
   
    return new_pair;
}

char* append_parenthesis_after(char* pair) {
    char* new_pair = new char[max];
    int i = 0, j = 0;
    
    while(j < strlen(pair)) {
        new_pair[i++] = pair[j++];
    }
    
    new_pair[i++] = '(';
    new_pair[i++] = ')';
    new_pair[i] = '\0';
    
    return new_pair;
}

char* append_parenthesis_around(char* pair) {
    char* new_pair = new char[max];
    int i = 0, j = 0;
    
    new_pair[i++] = '(';
    
    while(j < strlen(pair)) {
        new_pair[i++] = pair[j++];
    }
    
    new_pair[i++] = ')';
    new_pair[i] = '\0';
     
    return new_pair;
}

void n_pair_parenthesis(int n, vector<char*>& parenthesis) {
    
    if(n == 1) {
        char* pair = "()";
        parenthesis.push_back(pair);
    }
    else {
        n_pair_parenthesis(n-1, parenthesis);
        
        vector<char*> temp;
        int length = parenthesis.size();
        int i = 0;
        while(i < length) {
            char* pair = parenthesis.back();
            parenthesis.pop_back();
            
            parenthesis.insert(parenthesis.begin(), append_parenthesis_before(pair));
            parenthesis.insert(parenthesis.begin(), append_parenthesis_after(pair));
            parenthesis.insert(parenthesis.begin(), append_parenthesis_around(pair));
            i++;
        }
        
    }
}

void print_parenthesis(vector<string> parenthesis) {
    while(!parenthesis.empty()) {
        string str = parenthesis.back();
        cout << str << "  ";
        parenthesis.pop_back();
    }
}

void print_n_pair_parenthesis(int n) {
    vector<char*> parenthesis;
    n_pair_parenthesis(n, parenthesis);
   // print_parenthesis(parenthesis);
}

// Alternate method

void add_parens(vector<string> & parens, int left_parens, int right_parens, char* str, int count) {
    if((left_parens >= 0) && (right_parens >= left_parens)) {
        if((left_parens == 0) && (right_parens == 0)) {
          /*  char* temp_str = new char[count];
            strcpy(temp_str, str);
            temp_str[strlen(str)] = '\0';
            parens.push_back(temp_str); */
            std::stringstream ss;
            ss << str;
            parens.push_back(ss.str());
        }
        else {
            if(left_parens > 0) {
                str[count] = '(';
                add_parens(parens, left_parens-1, right_parens, str, count+1);
            }
            
            if(right_parens > left_parens) {
                str[count] = ')';
                add_parens(parens, left_parens, right_parens-1, str, count+1);
            }
        }
    }
}

void generate_parens(int n) {
    vector<string> parenthesis;
    char* str = new char[n*2];
    add_parens(parenthesis, n, n, str, 0);
    print_parenthesis(parenthesis);
}

int main(int argc, char** argv) {

    //print_n_pair_parenthesis(3);
    generate_parens(3);
}

