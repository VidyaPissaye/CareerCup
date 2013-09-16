/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on September 13, 2013, 9:19 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 *  List all RHN numbers - scenarios where unique numbers who cube/square add up to the same number/1
 */

vector<int> RHN_Numbers(int num) {
    
    vector<int> rhn;
    
    for(int i = 1; i < num; i++) {
        int cube = i * i * i;
        int sum = 0;
        
        while(cube != 0) {
            sum += cube % 10;
            if(((cube / 10) == 0) && ((sum / 10) != 0)) {
                cube = sum;
                sum = 0;
            }
            else {
                cube = cube / 10;
            }
        }
        if(sum == i)
            rhn.push_back(i);
    }
    return rhn;
}

int main(int argc, char** argv) {

    vector<int> rhn = RHN_Numbers(10);
    
    for(int i = 0; i < rhn.size(); i++) {
        cout << rhn[i] << " ";
    }
}

