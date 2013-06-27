
#include "SetofStacks.h"

void SetofStacks::push(int value) {
    if(stack < set) {
        if(top[stack] >= (max-1)) {
            stack++;
        }
        top[stack] += 1;
        data[stack][top[stack]] = value;
    }
    else {
        cout << "Stack Overflow!" << endl;
    }
}

int SetofStacks::pop() {
    
    if(stack >= 0) {
        if(top[stack] == -1) {
            stack--;
        }
        int value = data[stack][top[stack]];
        top[stack] -= 1;
        cout << "Stack: " << stack << endl;
        return value;
    }
    else {
        cout << "Stack Underflow!" << endl;
    }
}

int SetofStacks::popAt(int index) {
    if(top[index] != -1) {
        int value = data[index][top[index]];
        top[index] -= 1;
        return value;
    }
    else {
        cout << "Stack empty!" << endl;
    }
}
