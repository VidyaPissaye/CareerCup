/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on August 23, 2013, 6:30 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *  Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 *  An example is the root-to-leaf path 1->2->3 which represents the number 123.
 *  Find the total sum of all root-to-leaf numbers.
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* insert_node(int data, TreeNode* root) {
    
    TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
    new_node->val = data;
    new_node->left = new_node->right = NULL;
    TreeNode* ptr = root;
    TreeNode* parent_node = NULL;
    
    while(ptr != NULL) {
        parent_node = ptr;
        
        if(data < ptr->val) {
            ptr = ptr->left;
        }
        else {
            ptr = ptr->right;
        }
    }
    
    if(parent_node == NULL) {
        root = new_node;
    }
    else if(data < parent_node->val) {
        parent_node->left = new_node;
    }
    else {
        parent_node->right = new_node;
    }
    
    return root;
}

int sumAllPaths(TreeNode *root, int num) {
    if(root == NULL) 
        return 0;
            
    num = (num * 10) + root->val;
        
    if((root->left == NULL) && (root->right == NULL))
        return num;
            
    return( sumAllPaths(root->left, num) +
            sumAllPaths(root->right, num));        
}

int sumNumbers(TreeNode *root) {
    return(sumAllPaths(root, 0));
}
    
int main(int argc, char** argv) {

    int elements[] = { 5, 7, 3, 4, 2, 1, 6 };
     
    TreeNode* root = NULL;
    int length = sizeof(elements)/sizeof(int);
    
    for (int i=0; i < length; i++) {
        root = insert_node(elements[i], root);
    }
    
    cout << sumNumbers(root);
}

