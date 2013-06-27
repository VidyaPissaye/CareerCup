/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on April 8, 2013, 11:23 PM
 */

#include <cstdlib>
#include <iostream>
#include <tr1/unordered_map>


using namespace std;

/*
 *   Remove duplicates from an unsorted linked list
 *   without using temporary buffer.
 */

struct llist {
    int data;
    llist *next;
};

// Using temporary buffer - hash O(N)
void remove_dups_hash(llist *start) {
    
    typedef tr1::unordered_map<int, bool> hash_map;
    
    hash_map hash;
    
    llist *ptr = start;
    llist *prev = NULL;
    
    while(ptr != NULL) {
        if(hash.count(ptr->data) <= 0) {
            hash.insert(make_pair(ptr->data, true));
            prev = ptr;
        }
        else {
            llist *delete_node = ptr;
            prev->next = ptr->next;
            delete delete_node;
            ptr = prev;
        }
        ptr = ptr->next;
    }
}

// Without using temporary buffer - O(N2)
void remove_duplicates(llist *start) {
    llist *ptr = start;
    llist *temp;
    
    while(ptr != NULL && ptr->next != NULL) {
        temp = ptr;
        while(temp->next != NULL) {
            if(ptr->data == temp->next->data) {
                llist *delete_node = temp->next;
                temp->next = temp->next->next;
                delete delete_node;
            }
            else
                temp = temp->next;
        }
        ptr = ptr->next;
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
    }
}

int main(int argc, char** argv) {
    llist *head = NULL;
    
    int n = 1;
    while(n<8) {
        llist *node = (llist*)malloc(sizeof(llist));
        cout << "Enter the element to insert into list: ";
        cin >> node->data;
        node->next = head;
        head = node;
        n++;
    }
    
    remove_duplicates(head);
    display(head);
    
    n = 1;
    head = NULL;
    while(n<8) {
        llist *node = (llist*)malloc(sizeof(llist));
        cout << "Enter the element to insert into list: ";
        cin >> node->data;
        node->next = head;
        head = node;
        n++;
    }
    
    remove_dups_hash(head);
    display(head);
    
}

