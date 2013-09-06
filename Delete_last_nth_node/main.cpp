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
    
    if(head != NULL) {
            ListNode *ptr = head;
            ListNode *delete_prev = head;
            ListNode *delete_node = head;
            int count = 1;
            int list_length = 1;
            
            
            while(ptr->next != NULL) {
                if(count != n) {
                    count++;
                }
                else{
                    delete_prev = delete_node;
                    delete_node = delete_node->next;
                }
                list_length++;
                ptr = ptr->next;
            }
            
            if(list_length == n) {
                if(head->next == NULL) {
                    head = NULL;
                }
                else {
                    head = head->next;
                }
                    
            }
            else {
                delete_prev->next = delete_prev->next->next;    
            }
            
            
            delete delete_node;
            
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
    
    int elements[] = {3};
    int size = sizeof(elements)/sizeof(int);
    int n = 0;
    while(n < size) {
        ListNode *node = (ListNode*)malloc(sizeof(ListNode));
        node->data = elements[n];
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

