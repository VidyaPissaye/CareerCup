/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on April 21, 2013, 3:57 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

#include "SetofStacks.h"

/*
 *  Implement a data structure SetofStacks where a new stack is started when
 *  the previous stack exceeds threshold. SetofStacks should be composed of 
 *  several stacks and should create a new stack once the previous one exceeds
 *  capacity. SetofStacks.push() and SetofStacks.pop() should behave identical
 *  to a single stack.
 *  Also, implement a function popAt(int index) which performs a pop operation
 *  on a specific sub-stack.
 */


int main(int argc, char** argv) {

    SetofStacks stack;
    int elem, n; 
    
    cout << "Enter number of elements to be pushed onto stack" << endl;
    cin >> n;
    cout << "Enter the elements:" << endl;
    for(int i=0; i<n; i++) {
        cin >> elem;
        stack.push(elem);
    }
    
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    
    cout << "Stack: 0" << endl;
    cout << stack.popAt(0) << endl;
}

