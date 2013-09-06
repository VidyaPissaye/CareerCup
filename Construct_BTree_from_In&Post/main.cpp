/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on August 30, 2013, 1:05 AM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 * 
 */

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
  
void displayTree(TreeNode *root) {
    if(root != NULL) {
        displayTree(root->left);
        cout << root->val << " ";
        displayTree(root->right);
    }
}

TreeNode *constructTree(vector<int> &inorder, int low, int high, vector<int> &postorder, int &root_index) {
    if(low <= high) {
        TreeNode *root_node = (TreeNode*)malloc(sizeof(TreeNode));
        root_node->val = postorder[root_index];
        int i = low;
        while((inorder[i] != postorder[root_index]) && (i <= high)) {
            i++;
        }
            
        root_index--;
            
        root_node->right = constructTree(inorder, i+1, high, postorder, root_index);
        root_node->left = constructTree(inorder, low, i-1, postorder, root_index);
            
        return root_node;
    }
        
    return NULL;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {

    int root_index = postorder.size() - 1;
    return(constructTree(inorder, 0, inorder.size() - 1, postorder, root_index));        
}

int main(int argc, char** argv) {
    int inord[] = {1, 3, 4, 5, 6, 10, 12, 15, 16, 18};
    int postord[] = {3, 1, 5, 4, 6, 12, 16, 18, 15, 10};

    vector<int> inorder;
    vector<int> postorder;

    int i = 0;
    while(i < 10) {
        inorder.push_back(inord[i]);
        i++;
    }

    i = 0;

    while(i < 10) {
        postorder.push_back(postord[i]);
        i++;
    }

    TreeNode *root = buildTree(inorder, postorder);

    displayTree(root);
}

