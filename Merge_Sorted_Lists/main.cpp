/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on August 31, 2013, 7:20 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *  Merge two sorted linked lists and return it as a new list. 
 *  The new list should be made by splicing together the nodes of the first two lists.
 */

struct ListNode {
    int val;
    ListNode *next;
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        
    ListNode *newlist = NULL;
    ListNode *ptr = newlist;
    
    if(l1 == NULL) {
        return l2;
    }
    if(l2 == NULL) {
        return l1;
    }
        
    while(l1 != NULL && l2 != NULL) {
            
        if(l1->val < l2->val) {
            if(newlist == NULL) {
                ptr = l1;
                newlist = ptr;
            }
            else {
                ptr->next = l1;
                ptr = ptr->next;
            }

            l1 = l1->next;
        }
        else {
            if(newlist == NULL) {
                ptr = l2;
                newlist = ptr;
            }
            else {
                ptr->next = l2;
                ptr = ptr->next;

            }
                
            l2 = l2->next;
        }
        ptr->next = NULL;
                        
    }
        
    if(l1 != NULL)
        ptr->next = l1;

    if(l2 != NULL)
        ptr->next = l2;
    
            
    return newlist;
        
}

int main(int argc, char** argv) {

    ListNode *head1 = NULL, *head2 = NULL;
    
    int elements1[] = {10, 7, 5, 4, 1};
    int size = sizeof(elements1)/sizeof(int);
    int n = 0;
    while(n < size) {
        ListNode *node = (ListNode*)malloc(sizeof(ListNode));
        node->val = elements1[n];
        node->next = head1;
        head1 = node;
        n++;
    }
    
    int elements2[] = {15, 6, 3, 2, 0};
    int size2 = sizeof(elements2)/sizeof(int);
    n = 0;
    while(n < size2) {
        ListNode *node = (ListNode*)malloc(sizeof(ListNode));
        node->val = elements2[n];
        node->next = head2;
        head2 = node;
        n++;
    }
    
    ListNode* merged_list = mergeTwoLists(head1, head2);
    
    while(merged_list != NULL) {
        cout << merged_list->val << "->";
        merged_list = merged_list->next;
    }
}

