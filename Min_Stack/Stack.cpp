
#include "Stack.h"

void Stack::push(int value) {
    if(top < (max-1)) {
        data[++top] = value;
        if(top == 0) {
            min[++min_index] = value;
        }
        
        if(value < min[min_index]) {
            min[++min_index] = value;
        }
    }
    else {
        cout << "StackOverflow!" << endl;
    }
}

int Stack::pop() {
    if(top != -1) {
        if(data[top] == min[min_index]) {
            min_index--;
        }
        return data[top--];
    }
    else {
        cout << "Stack Underflow!" << endl;
    }
}

int Stack::min_element() {
    return min[min_index];
}