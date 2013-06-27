/* 
 * File:   SetofStacks.h
 * Author: Vidya
 *
 * Created on April 21, 2013, 4:02 PM
 */

#ifndef SETOFSTACKS_H
#define	SETOFSTACKS_H

#include <iostream>

using namespace std;

#define max 5
#define set 10

class SetofStacks {
    int data[set][max];
    int top[set];
    int stack;
    
public:
    SetofStacks() {
        for(int i=0; i<set; i++) {
            top[i] = -1;
        }
        stack = 0;
    }
    
    void push(int value);
    int pop();
    int popAt(int index);
};

#endif	/* SETOFSTACKS_H */

