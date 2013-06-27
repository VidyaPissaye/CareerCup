/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on April 22, 2013, 12:09 AM
 */

#include <cstdlib>
#include <iostream>
#include "Queue2Stacks.h"

using namespace std;

/*
 *  Implement a queue using two stacks.
 */


int main(int argc, char** argv) {
    Queue2Stacks queue;
    int elem, n; 
    
    cout << "Enter number of elements to be pushed onto stack" << endl;
    cin >> n;
    cout << "Enter the elements:" << endl;
    for(int i=0; i<n; i++) {
        cin >> elem;
        queue.enqueue(elem);
    }
    
    while(!queue.empty()) {
        cout << queue.dequeue();
    }
}

