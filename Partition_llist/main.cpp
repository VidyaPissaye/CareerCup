/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on April 9, 2013, 8:38 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *   Partition a linked list around a value x, such that all nodes less than x
 *   come before all nodes greater than x or equal to x.
 */

struct llist {
    int data;
    llist* next;
};

llist* search_node(llist* head, int x) {
    llist *node = head;
    while(node != NULL && node->data != x) {
        node = node->next;
    }
    return node;
}

llist* partition_list(llist *head, int x) {
    
    llist *node = search_node(head, x);
    
    llist *ptr1 = head;
    llist *ptr2 = node;
    llist* head_node = NULL;
    
    if(head->data > x) {
        head_node = head;
        head = head->next;
    }
    
    while(ptr2->next != NULL) {
        if(ptr2->next->data < x) {
            llist* new_node = ptr2->next;
            ptr2->next = ptr2->next->next;
            new_node->next = head;
            head = new_node;
        }
        else {
            ptr2 = ptr2->next;
        }
    }
    
    while(ptr1->next != node) {
        if(ptr1->next->data > x) {
            llist* new_node = ptr1->next;
            ptr1->next = ptr1->next->next;
            ptr2->next = new_node;
            new_node->next = NULL;
            ptr2 = ptr2->next;
        }
        else {
            ptr1 = ptr1->next;
        }
    }
    
    if(head_node) {
        ptr2->next = head_node;
        head_node->next = NULL;
    }
    
    return head;
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
    
    int x;
    cout << "Enter the element to partition at: ";
    cin >> x;
    
    llist* start = partition_list(head, x);
    display(start);
}

