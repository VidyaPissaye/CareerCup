/*
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on August 1, 2013, 2:28 PM
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

TreeNode *constructTree(vector<int> &preorder, int &root_index, vector<int> &inorder, int low, int high) {
    if(low <= high) {
            TreeNode *root = (TreeNode*)malloc(sizeof(TreeNode));
            root->val = preorder[root_index];
            
    
            int i = low;
            
            while((inorder[i] != preorder[root_index]) && (i <= high)) {
                i++;
            }
            
            root_index++;
            
            root->left = constructTree(preorder, root_index, inorder, low, i-1);
            root->right = constructTree(preorder, root_index, inorder, i+1, high);
            return root;
        }
        
        return NULL;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int root_index = 0;
    return(constructTree(preorder, root_index, inorder, 0, (inorder.size() - 1)));
}

void displayTree(TreeNode *root) {
    if(root != NULL) {
        displayTree(root->left);
        cout << root->val << " ";
        displayTree(root->right);
    }
}

int main(int argc, char** argv) {
    int inord[] = {1, 3, 4, 5, 6, 10, 12, 15, 16, 18};
    int preord[] = {10, 6, 4, 1, 3, 5, 15, 12, 18, 16};

    vector<int> inorder;
    vector<int> preorder;

    int i = 0;
    while(i < 10) {
        inorder.push_back(inord[i]);
        i++;
    }

    i = 0;

    while(i < 10) {
        preorder.push_back(preord[i]);
        i++;
    }

    TreeNode *root = buildTree(preorder, inorder);

    displayTree(root);
}

