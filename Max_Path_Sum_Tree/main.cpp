/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on August 29, 2013, 6:26 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *  Given a binary tree, find the maximum path sum. 
 *  The path may start and end at any node in the tree.
 *  For example: Given the below binary tree, {1, 2, 3}, return 6
 * 
 *  Solution: One needs to handle three cases:
 *  Left tree path plus the current root.
 *  Right tree path plus the current root. 
 *  The path passes through the root and hence one needs to consider 
 *  the left path + current root + right path.
 */

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};
 
TreeNode* insert_node(int data, TreeNode* root){
    
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = data;
    node->left = node->right = NULL;
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
        root = node;
    }
    else if(data < parent_node->val) {
        parent_node->left = node;
    }
    else {
        parent_node->right = node;
    }
    
    return root;
}


int max(int x, int y) {
    if(x > y)
        return x;
    else
        return y;
}
    
void findMaxPathSum(TreeNode *root, int &path_sum, int &max_sum) {
        
    if(root == NULL) {
        path_sum = 0;
        return;
    }
        
    int left_sum = 0, right_sum = 0;
    findMaxPathSum(root->left, left_sum, max_sum);
    findMaxPathSum(root->right, right_sum, max_sum);
        
    path_sum = max(root->val, max(root->val + left_sum, root->val + right_sum));
    max_sum = max(max_sum, max(path_sum, root->val + left_sum + right_sum));
        
}
    
int maxPathSum(TreeNode *root) {
    int path_sum = 0;
    int max_sum = -1;
        
    findMaxPathSum(root, path_sum, max_sum);
    return max_sum;
        
}
    
int main(int argc, char** argv) {

    int elements[] = { 6, 5, 15, 20, 11, 12, 8, 9, 14 };
    
    TreeNode* root = NULL;
    int length = sizeof(elements)/sizeof(int);
    
    for (int i=0; i < length; i++) {
        root = insert_node(elements[i], root);
    }
    
    cout << maxPathSum(root);
}

