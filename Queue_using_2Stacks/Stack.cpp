

#include "Stack.h"

void Stack::push(int data) {
    if(top < (max-1)) {
        arr[++top] = data;
    }
    else {
        cout << "Stack overflow!" << endl;
    }
}

int Stack::pop() {
    if(top != -1) {
        return (arr[top--]);
    }
    else {
        cout << "Stack underflow!" << endl;
    }
}

bool Stack::empty() {
    if(top == -1) {
        return true;
    }
    else {
        return false;
    }
}

int Stack::peek() {
    if(top > -1) {
        return (arr[top]);
    }
    else {
        cout << "Empty Stack!" << endl;
    }
}



