/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on August 27, 2013, 1:12 AM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 *  Given a number represented as an array of digits, plus one to the number.
 */

vector<int> plusOne(vector<int> &digits) {
        
    int digit = digits.size() - 1;
        
    int carry = 1;
        
    while((digit >= 0) && (carry != 0)) {
        int num = digits[digit] + carry;
        digits[digit] = num % 10;
        carry = num / 10;
        digit--;
    }
        
    if(carry > 0) {
        std::vector<int>::iterator it;
        it = digits.begin();
        digits.insert(it, carry);    
    }
        
    return digits;
        
}
    
int main(int argc, char** argv) {

    vector<int> digits;
    int elements[] = {9, 9, 9};
    int size = sizeof(elements)/sizeof(int);
    
    for(int i = 0; i < size; i++) {
        digits.push_back(elements[i]);
    }
    
    vector<int> result;
    result = plusOne(digits);
    
    for(int i = 0; i < result.size(); i++) {
        cout << result[i];
    }
}

