/* 
 * File:   Queue2Stacks.h
 * Author: Vidya
 *
 * Created on April 22, 2013, 12:13 AM
 */

#ifndef QUEUE2STACKS_H
#define	QUEUE2STACKS_H

#include "Stack.h"

class Queue2Stacks {
    Stack stacknewest, stackoldest;
    
public:
    void enqueue(int value);
    int dequeue();
    int peek();
    void move_elements(int to_oldstack);
    bool empty();
};

#endif	/* QUEUE2STACKS_H */

