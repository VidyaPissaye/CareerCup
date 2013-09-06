/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on August 29, 2013, 4:24 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 * 
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
    
    int findDepth(TreeNode *root) {
        
        if(root == NULL)
            return 0;
        return(1 + max(findDepth(root->left), findDepth(root->right)));
        
    }
    
    void traverseBottom(TreeNode *root, int level, int depth, vector<vector<int> > &array) {
        if(root != NULL) {
            
            traverseBottom(root->left, level+1, depth, array);
            traverseBottom(root->right, level+1, depth, array);
            
            array[depth - level - 1].push_back(root->val);
        }
    }
    
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        
        int depth = findDepth(root);
        
        vector<vector<int> > level_nodes;
        for(int i = 0; i < depth; i++) {
            vector<int> level;
            level_nodes.push_back(level);
        }
        traverseBottom(root, 0, depth, level_nodes);
        return level_nodes;
        
    }
    
    
int main(int argc, char** argv) {

    int elements[] = { 6, 5, 10, 7, 12, 8, 9 };
    
    TreeNode* root = NULL;
    int length = sizeof(elements)/sizeof(int);
    
    for (int i=0; i < length; i++) {
        root = insert_node(elements[i], root);
    }
    
    vector<vector<int> > level_nodes;
    level_nodes = levelOrderBottom(root);
    
    for(int i = 0; i < level_nodes.size(); i++) {
        cout << "level " << i << " nodes "; 
        for(int j = 0; j < level_nodes[i].size(); j++) {
            cout << level_nodes[i][j] << " ";
        }
        cout << endl;
    }
}

