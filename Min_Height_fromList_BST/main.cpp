/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on August 30, 2013, 10:32 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *  Given a singly linked list where elements are sorted in ascending order, 
 *  convert it to a height balanced BST.
 */

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

struct ListNode {
    int val;
    ListNode *next;
};


void inorder_traversal(TreeNode* root) {
    if(root != NULL) {
        inorder_traversal(root->left);
        cout << root->val << "->";
        inorder_traversal(root->right);
    }
}


TreeNode *sortedListToBST(ListNode *head) {
    if(head != NULL) {
        TreeNode *root = (TreeNode*)malloc(sizeof(TreeNode));
            
        ListNode *slow = head, *fast = head, *prev = NULL;
            
        while((fast->next != NULL) && (fast->next->next != NULL)) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
            
        root->val = slow->val;    
            
        if(slow == head) {
            head = NULL;
        }
        else {
            prev->next = NULL;
        }
            
        ListNode *right_head = slow->next;
        delete(slow);
    
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(right_head);

        return root;
    }    
    return NULL;
}
        
int main(int argc, char** argv) {

    int sorted_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int length = sizeof(sorted_array)/sizeof(int);
    
    ListNode *head = NULL;
    for(int i = length-1; i >= 0; i--) {
        ListNode *newnode = (ListNode*)malloc(sizeof(ListNode));
        newnode->val = sorted_array[i];
        newnode->next = head;
        head = newnode;
    }
    
    TreeNode *BST = sortedListToBST(head);
    inorder_traversal(BST);  
}

