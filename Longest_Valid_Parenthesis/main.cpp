/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on September 3, 2013, 5:46 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

/*
 *  Given a string containing just the characters '(' and ')', 
 *  find the length of the longest valid (well-formed) parentheses substring. 
 *  For "(()", the longest valid parentheses substring is "()", which has length = 2.
 *  Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 */

int longestValidParentheses(string s) {
        
    stack<int> left_paren;
        
    int i = 0, last = -1, max_length = 0;
        
    while(i < s.length()) {
        if(s[i] == '(') {
            left_paren.push(i);        
        }
        else {
            if(left_paren.empty()) {
                last = i;
            }
            else {
                left_paren.pop();
                if(left_paren.empty()) {
                    max_length = max(max_length, i - last);
                }
                else 
                    max_length = max(max_length, i - left_paren.top());
            }
        }
        i++;
    }
        
    return max_length;
}

int main(int argc, char** argv) {

    string parenthesis = "())(())(";
    
    cout << longestValidParentheses(parenthesis);
}

