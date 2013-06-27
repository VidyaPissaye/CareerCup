/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on April 20, 2013, 6:27 PM
 */

#include <cstdlib>
#include <iostream>
#include <stack>

using namespace std;

/*
 *  Determine if the linked list is a palindrome.
 */

struct llist{
    int data;
    llist* next;
};

// Technique 1
bool determine_palindrome(llist* head) {
    
    stack<llist*> my_stack;
    
    llist* fast = head;
    llist* slow = head;
    
    while((fast != NULL) && (fast->next != NULL)) {
        my_stack.push(slow);
        slow = slow->next;
        fast = fast->next->next;
    }
    
    if(fast != NULL) {
        slow = slow->next;
    }
    
    while(!my_stack.empty()) {
        llist* node = my_stack.top();
        if(slow->data != node->data) {
            return false;
        }
        slow = slow->next;
        my_stack.pop();
    }
    
    return true;
}

llist* copy_list(llist* head) {
    llist *ptr = head;
    llist* begin = NULL;
   
    while(ptr != NULL) {
        llist *node = (llist*)malloc(sizeof(llist));
        node->data = ptr->data;
        node->next = begin;
        begin = node;
        ptr = ptr->next;
    }
    return begin;
}

//Technique 2
bool is_palindrome(llist* start) {
    llist *list_copy = copy_list(start);
    
    while(start != NULL && list_copy != NULL) {
        if(start->data != list_copy->data) {
            return false;
        }
        start = start->next;
        list_copy = list_copy->next;
    }
    
    if(start != NULL || list_copy != NULL) {
        return false;
    }
    
    return true;
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
    
    if(determine_palindrome(head)) {
        cout << "The list is a palindrome" << endl;
    }
    else {
        cout << "The list is not a palindrome" << endl;
    }
    
    
}

