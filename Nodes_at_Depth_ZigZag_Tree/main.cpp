/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on August 29, 2013, 5:23 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 *  Given a binary tree, return the zigzag level order traversal of its 
 *  nodes' values. (ie, from left to right, then right to left for the 
 *  next level and alternate between).
 *  For example: Given binary tree {3,9,20,#,#,15,7},
 *  return its zigzag level order traversal as: [
 *  [3],
 *  [20,9],
 *  [15,7]
]
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
 
    
void zigzagTraverseTree(TreeNode *root, int level, vector<vector<int> > &array) {
    if(root != NULL) {
        int length = array.size();
            
        if(level == length) {
            vector<int> level_nodes;
            level_nodes.push_back(root->val);    
            array.push_back(level_nodes);
        }
        else{
            if((level % 2) == 0) {
                array[level].push_back(root->val);
            }
            else {
                vector<int>::iterator it;
                it = array[level].begin();
                array[level].insert(it, root->val);
            }
        }
    
        zigzagTraverseTree(root->left, level+1, array);
        zigzagTraverseTree(root->right, level+1, array);
    }
}
    
vector<vector<int> > zigzagLevelOrder(TreeNode *root) {

    vector<vector<int> > array;
    zigzagTraverseTree(root, 0, array);
    return array;        
}
    
int main(int argc, char** argv) {

    int elements[] = { 6, 5, 15, 20, 11, 12, 8, 9, 14 };
    
    TreeNode* root = NULL;
    int length = sizeof(elements)/sizeof(int);
    
    for (int i=0; i < length; i++) {
        root = insert_node(elements[i], root);
    }
    
    vector<vector<int> > level_nodes;
    level_nodes = zigzagLevelOrder(root);
    
    for(int i = 0; i < level_nodes.size(); i++) {
        cout << "level " << i << " nodes "; 
        for(int j = 0; j < level_nodes[i].size(); j++) {
            cout << level_nodes[i][j] << " ";
        }
        cout << endl;
    }
}

