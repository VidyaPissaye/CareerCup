/* 
 * File:   Stack.h
 * Author: Vidya
 *
 * Created on April 22, 2013, 6:42 PM
 */

#ifndef STACK_H
#define	STACK_H

#include <iostream>
using namespace std;

#define max 100

class Stack {
    int arr[max];
    int top;
    
public: 
    Stack() {
        top = -1;
    }
    
    void push(int data);
    int pop();
    bool empty();
    int peek();
};

#endif	/* STACK_H */

