/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on April 19, 2013, 11:22 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 *  Pros - Easy to code and clean
 *  Cons - The stack may overflow so use iterative. 
 *  Since the same number is calculated multiple twice, use dynamic programming
 */


// Recursive method
int fibonacci(int n, int store[]) {
    if(n == 0) {
        return 0;
    }
    else if(n == 1) {
        return 1;
    }
    
    if(store[n] != 0) { return store[n]; }
    
    store[n] = fibonacci(n-1, store) + fibonacci(n-2, store);
    
    return store[n];
}

// Iterative method
int fibonacci_iterative(int n) {
    int first = 0, second = 1, sum;
    if(n==0) {
        return 0;
    }
    else if(n == 1) {
        return 1;
    }
    else {
        for(int i=2; i<=n; i++) {
            sum = first + second;
            first = second;
            second = sum;
        }
    }
    return sum;
}

int main(int argc, char** argv) {

    int store[50] = {0};
    int fib = fibonacci(6, store);
    
    cout << "The Fibonacci value is " << fib;
}

