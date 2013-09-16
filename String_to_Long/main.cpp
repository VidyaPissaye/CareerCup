/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on September 10, 2013, 11:38 AM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <limits>

using namespace std;

/*
 *  Given a string, write a routine that converts the string to a long, 
 *  without using the built in functions that would do this.
 */

long stringToLong(string s) {
    const long min_long = numeric_limits<long>::min();
    const long max_long = numeric_limits<long>::max();
    
    long value = 0;
    
    if(s != "") {
        int i = 1;
        int denom = 10;
        
        bool negative_number = (s[0] == '-') ? true : false;
       
        if(negative_number) {
            value = 0 - (s[1] - '0');
            i++;
        }
        else {
            value = s[0] - '0';
        }
        
        while(i < s.size()) {
            
            if(negative_number) {
                if(value < (min_long/denom) || (value == (min_long/denom)) && (-(s[i] - '0') < min_long % denom))
                    return -1;
                
                value = (value * denom) - (s[i]-'0');
            }
            else {
                if(value > (max_long/denom) || (value == (max_long/denom) && ((s[i] - '0') > max_long % denom)))
                    return -1;
                
                value = (value * denom) + (s[i] - '0');
            }
            i++;
        }
        return value;
    }
    return -1;
}

int main(int argc, char** argv) {

    string str = "-9223372036854775807";
    
    cout << stringToLong(str);
}

