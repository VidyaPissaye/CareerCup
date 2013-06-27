/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on April 21, 2013, 1:31 PM
 */

#include <cstdlib>
#include <iostream>

#include "Stack.h"

using namespace std;

/*
 *   Design a stack which, in addition to push and pop, also has a function min
 *   which returns the minimum element. Push, pop and min should all operate
 *   in O(1) time.
 */

int main(int argc, char** argv) {

    Stack stack;
    int elem, n; 
    
    cout << "Enter number of elements to be pushed onto stack" << endl;
    cin >> n;
    cout << "Enter the elements:" << endl;
    for(int i=0; i<n; i++) {
        cin >> elem;
        stack.push(elem);
    }
    
    int min = stack.min_element();
    cout << "The min element is: " << min << endl;
    
    stack.pop();
    
    min = stack.min_element();
    cout << "The min element is: " << min << endl;
    
    stack.pop();
    
    min = stack.min_element();
    cout << "The min element is: " << min << endl;
}

