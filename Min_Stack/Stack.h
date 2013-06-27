/* 
 * File:   Stack.h
 * Author: Vidya
 *
 * Created on April 21, 2013, 1:31 PM
 */

#ifndef STACK_H
#define	STACK_H

#include <iostream>
using namespace std;

#define max 100

class Stack {
    int top;
    int data[max];
    int min_index;
    int min[max];
    
public:
    Stack() { 
        top = -1; 
        min_index = -1;
    }
    ~Stack() {}
    
    void push(int value);
    int pop();
    int min_element();
};

#endif	/* STACK_H */

