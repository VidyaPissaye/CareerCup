/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on April 22, 2013, 6:29 PM
 */

#include <cstdlib>
#include <iostream>

#include "Stack.h"

using namespace std;

/*
 *   Sort a stack in ascending order (with biggest items on top). 
 *   An additional stack may be used to hold items.
 */


// Technique 1
void Sort_stack(Stack &stack) {
    Stack temp_stack;
    int temp = stack.pop();
    
    int i = 0;
    
    while(i < 2) {
        while(!stack.empty()) {
            if(stack.peek() > temp) {
                temp_stack.push(stack.pop());
            }
            else {
                temp_stack.push(temp);
                temp = stack.pop();
            }
        }

        while(!temp_stack.empty()) {
            if(temp_stack.peek() < temp) {
                stack.push(temp_stack.pop());
            }
            else {
                stack.push(temp);
                temp = temp_stack.pop();
            }
        }
        i++;
    }
    stack.push(temp);
}

// Technique 2
Stack sort_stack(Stack stack) {
    
    Stack temp_stack;
    int temp;
    
    while(!stack.empty()) {
        temp = stack.pop();
        while(!temp_stack.empty() && temp_stack.peek() > temp) {
            stack.push(temp_stack.pop());
        }
        temp_stack.push(temp);
    }
    
    return temp_stack;
}

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
    
  //  Sort_stack(stack);
    Stack sorted_stack = sort_stack(stack);
    
    while(!sorted_stack.empty()) {
        cout << sorted_stack.pop() << " : ";
    }
}

