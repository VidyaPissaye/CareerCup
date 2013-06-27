/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on April 9, 2013, 8:34 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *   Delete a node in the middle of a singly linked list, 
 *   given only access to the node.
 *   Example: Input node is c from the linked list a->b->c->d->e
 *   Output list should be a->b->d->e
 */


struct llist {
    int data;
    llist* next;
};

void delete_node(llist* node) {
    
    if((node != NULL) && (node->next != NULL)) {
        llist* ptr = node->next;
        node->data = node->next->data;
        node->next = ptr->next;
        delete ptr;
    }
}

void display(llist *start) {
    llist *ptr = start;
    if(start == NULL) {
        cout << "Empty list" << endl;
    }
    else {
        while(ptr != NULL) {
            cout << ptr->data << "->";
            ptr = ptr->next;
        }
        cout << endl;
    }
}

int main(int argc, char** argv) {

    llist *head = NULL;
    
    int n = 0;
    while(n<8) {
        llist *node = (llist*)malloc(sizeof(llist));
        cout << "Enter the element to insert into list: ";
        cin >> node->data;
        node->next = head;
        head = node;
        n++;
    }
    
    llist *node = head;
    n = 3;
    while(n>0) {
        node = node->next;
        n--;
    }
    
    delete_node(node);
    display(head);
}

