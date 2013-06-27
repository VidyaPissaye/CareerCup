/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on April 20, 2013, 4:23 PM
 */

#include <cstdlib>
#include <iostream>
#include <tr1/unordered_map>

using namespace std;

/*
 *  Given a circular linked list, return the node at the beginning of the loop.
 */

struct llist{
    int data;
    llist* next;
};

// Technique 1
llist* is_loop(llist* start) {
    llist *fast = start;
    llist *slow = start;
    
    if(start != NULL) {
        while((fast != NULL) && (slow != NULL)) {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow)
                break;
        }
        
        if((fast == NULL) || (fast->next == NULL))
            return NULL;
        
        fast = start;
        
        while(fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return fast;
}

// Technique 2
llist* determine_loop(llist* start) {
    typedef tr1::unordered_map<llist*, bool> hash_map;
    hash_map hash;
    
    llist* ptr = start;
    
    while(ptr != NULL) {
        if(hash.count(ptr) <= 0) {
            hash.insert(make_pair(ptr, true));
            ptr = ptr->next;
        }
        else {
            return ptr;
        }
    }
}

llist* insert_end() {
    llist *head = NULL;
    llist* ptr;
    
    int n = 1;
    while(n<8) {
        llist *node = (llist*)malloc(sizeof(llist));
        cout << "Enter the element to insert into list: ";
        cin >> node->data;
        node->next = NULL;
        
        if(head != NULL) {
        
            llist* temp = head;
            while(temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = node;

            if(n == 3) {
                ptr = node;
            }
            if(n == 7) {
                node->next = ptr;
            }
        }
        else {
            head = node;
        }
        n++;
    }
    return head;
}

int main(int argc, char** argv) {

    llist *start = NULL;
    start = insert_end();
    //llist* node_loop = determine_loop(start);
    llist* node_loop = is_loop(start);
    cout << "Node at beginning of loop: " << node_loop->data;
    
}

