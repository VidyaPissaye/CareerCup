/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on February 15, 2013, 11:19 AM
 */

#include <cstdlib>
#include <iostream>
#include <list>

using namespace std;

/*
 *   Delete the nth element from the end of a singly linked list.
 */

  struct ListNode {
      int data;
      ListNode *next; 
  };

ListNode* removeNthFromEnd(ListNode *head, int n) {
    
    ListNode *current, *next, *ptr;
    current = head;
    
    if((head->next == NULL) && (n==1)) {
        head = NULL;
    }
    else{
                
        int x = 1, list_length = 1;
        next = current;
        ptr = current;
        while (next->next != NULL){
            next = next->next;
            list_length++;
            if(x!=n) {
                x++;    
            }
            else {
                current = ptr;
                ptr = ptr->next;
            }
        }

        if(list_length == n) {
            ListNode *first_node = head;
            head = head->next;
            delete first_node;
        }
        else {
            current->next = ptr->next;
            delete ptr;
        }
    }    
    return head;
}

void display(ListNode *start) {
    ListNode *ptr = start;
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
    ListNode *head = NULL;
    
    int n = 0;
    while(n<8) {
        ListNode *node = (ListNode*)malloc(sizeof(ListNode));
        cout << "Enter the element to insert into list: ";
        cin >> node->data;
        node->next = head;
        head = node;
        n++;
    }
    
    // Execute these tests independent of each other
   // ListNode *start = removeNthFromEnd(head, 5);
   // display(start);
   // ListNode *first = removeNthFromEnd(head, 8);
   // display(first);
    ListNode *st = removeNthFromEnd(head, 1);
    display(st);
}

