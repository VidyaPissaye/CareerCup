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

TreeNode *constructTree(vector<int> &preorder, vector<int> &inorder, int low, int high) {
    if(low > high)
        return NULL;

    TreeNode *newnode = (TreeNode *)malloc(sizeof(TreeNode));
    int newval = preorder.back();
    preorder.pop_back();
    newnode->val = newval;

    if(low == high) {
        newnode->left = NULL;
        newnode->right = NULL;
    }
    else {

        int mid = 0;
        while (inorder[mid] != newval) {
            mid++;
        }
        newnode->left = constructTree(preorder, inorder, low, mid - 1);
        newnode->right = constructTree(preorder, inorder, mid + 1, high);
    }

    return newnode;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return(constructTree(preorder, inorder, 0, (inorder.size() - 1)));
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

    i--;

    while(i >= 0) {
        preorder.push_back(preord[i]);
        i--;
    }

    TreeNode *root = buildTree(preorder, inorder);

    displayTree(root);
}

