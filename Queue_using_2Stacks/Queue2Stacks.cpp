
#include "Queue2Stacks.h"

bool Queue2Stacks::empty() {
    if(stackoldest.empty() && stacknewest.empty()) 
        return true;
    else
        return false;
}

void Queue2Stacks::enqueue(int value) {
    move_elements(false);
    stacknewest.push(value);
}

void Queue2Stacks::move_elements(int to_oldstack){
    if(to_oldstack) {
        if(stackoldest.empty()) {
            while(!stacknewest.empty()) {
                stackoldest.push(stacknewest.pop());
            }
        }
    }
    else {
        if(stacknewest.empty()) {
            while(!stackoldest.empty()) {
                stacknewest.push(stackoldest.pop());
            }
        }
    }
    
}

int Queue2Stacks::dequeue() {
    move_elements(true);
    return stackoldest.pop();
}

int Queue2Stacks::peek() {
    move_elements(true);
    return stackoldest.peek();
}