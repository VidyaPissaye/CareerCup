/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on August 1, 2013, 7:38 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *  Given a binary tree, flatten it to a linked list in-place.
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    
TreeNode* flatten_tree(TreeNode *root) {
if(root != NULL) {
    TreeNode *left = flatten_tree(root->left);
    TreeNode *right = flatten_tree(root->right);

    root->left = NULL;
        root->right = left;

        left = root;
        while(left->right != NULL) {
            left = left->right;
        }

        if(left->right == NULL) {
            left->right = right;
        }

        return root;
    } 

    return NULL;
}

void flatten(TreeNode *root) {
    root = flatten_tree(root);
}
 
int main(int argc, char** argv) {

    int elements[] = { 5, 7, 3, 4, 2, 1, 6 };
    
    TreeNode* root = NULL;
    int length = sizeof(elements)/sizeof(int);
    
    for (int i=0; i < length; i++) {
        root = insert_node(elements[i], root);
    }
    
    flatten(root);
    
    while(root != NULL) {
        cout << root->val << "->";
        root = root->right;
    }
}

