/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on August 2, 2013, 1:23 PM
 */

#include <cstdlib>
#include <iostream>
#include <sstream>


using namespace std;

/*
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 * 
* 1 is read off as "one 1" or 11.
* 11 is read off as "two 1s" or 21.
* 21 is read off as "one 2, then one 1" or 1211.
* Given an integer n, generate the nth sequence.
*/
  
string countAndSay(int n) {

    if(n == 1) {
        return "1";
    }
    
    string sequence = "1";
    
    for(int i = 1; i < n; i++) {
        int count = 1;
        char num = sequence[0];
        string tmp = "";
        int pos = 1;
        
        while(pos < sequence.size()) {
            if(sequence[pos] == num) {
                count++;
            }
            else {
                stringstream ss;
                ss << count;
                tmp += ss.str() + num;
                num = sequence[pos];
                count = 1;
            }
            pos++;
        }
        stringstream ss;
        ss << count;
        tmp += ss.str() + num;
        sequence = tmp;
    }

    return sequence;
}
    
int main(int argc, char** argv) {

    cout << countAndSay(4);
}

