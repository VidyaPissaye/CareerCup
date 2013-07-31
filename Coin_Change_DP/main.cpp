/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on June 29, 2013, 1:06 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *  Calculate number of ways of representing n cents given Quarter (25 cents),
 *  Dime (10 cents), Nickel (5 cents) and Cent (1 cent) denomination coins.
 */

int coin_changer(int n, int denom){
    
    int next_denom, ways = 0;
    
    switch(denom) {
        case 25:
            next_denom = 10;
            break;
        case 10:
            next_denom = 5;
            break;
        case 5:
            next_denom = 1;
            break;
        case 1:
            return 1;
    }
    
    for(int i = 0; i * denom <= n; i++) {
        ways += coin_changer(n - (i * denom), next_denom);
    }
    
    return ways;
}

int main(int argc, char** argv) {

    int number = 100;
    
    cout << "Number of ways of representing " << number << " is "<< coin_changer(number, 25);
}

