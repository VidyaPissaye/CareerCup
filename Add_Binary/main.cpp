/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on August 29, 2013, 1:03 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/*
 * 
 */

string addBinary(string a, string b) {

    int sizea = a.size() - 1;
    int sizeb = b.size() - 1;
    int i = sizea, j = sizeb;
    int carry = 0;
    long sum = 0;
    long denom = 1;
        
    while(i >= 0 || j >= 0) {
        int ia = 0, jb = 0;
            
        ia = (i >= 0 ? a[i] - '0' : 0);
        jb = (j >= 0 ? b[j] - '0' : 0);
                
        int num = ia + jb + carry;
        carry = 0;
            
        if(num > 1) {
            carry = num / 2;
            num %= 2;
        }
           
        sum = (num * denom) + sum;
        denom *= 10;
            
        i--;
        j--;
    }
        
    if((i <= 0) && (j <= 0) && (carry != 0)) {
        sum = (carry * denom) + sum;
    }
        
    std::stringstream ss;
    ss << sum;
    std::string str = ss.str();

    return(str);

    //return(to_string(sum));

}

// Alternate method of create the result string

string addBinary(string a, string b) {
        
    string res;

    int sizea = a.size() - 1;
    int sizeb = b.size() - 1;
    int i = sizea, j = sizeb;
    int carry = 0;
        
    while(i >= 0 || j >= 0) {
        int ia = 0, jb = 0;
        if(i >= 0)
            ia = a[i] - '0';
        if(j >= 0)
            jb = b[j] - '0';
                
        int num = ia + jb + carry;
        carry = 0;

        if(num > 1) {
            carry = num / 2;
            num %= 2;
        }
            
        res.insert(0, 1, num + '0');
            
        i = (i >= 0 ? -- i : i);
        j = (j >= 0 ? -- j : j);
    }

    if((i <= 0) && (j <= 0) && (carry != 0)) {
        res.insert(0, 1, carry + '0');
    }

    return res;        
}

int main(int argc, char** argv) {

    string s1 = "1110110101";
    string s2 = "1110111011";
    cout << addBinary(s1, s2);
}

