/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on August 31, 2013, 12:11 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *  Given a binary tree, find its maximum depth.
 *  The maximum depth is the number of nodes along the longest path from 
 *  the root node down to the farthest leaf node.
 * 
 *  Given a binary tree, find its minimum depth.
 *  The minimum depth is the number of nodes along the shortest path from 
 *  the root node down to the nearest leaf node.
 */

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};
    
int max(int x, int y) {
    if(x > y)
        return x;
    else
        return y;
}

int maxDepth(TreeNode *root) {
        
    if(root == NULL)
        return 0;
        
    return (1 + (max(maxDepth(root->left), maxDepth(root->right))));
}

int findMinDepth(TreeNode *root, int depth) {
    if(root == NULL)
        return (depth - 1);
    
    int left_depth = findMinDepth(root->left, depth + 1);
    int right_depth = findMinDepth(root->right, depth + 1);
    
    if(left_depth == depth)
        return right_depth;
    if(right_depth == depth)
        return left_depth;
    
    return(left_depth < right_depth ? left_depth : right_depth);
}

int minDepth(TreeNode *root) {
    if(root == NULL)
        return 0;
    
    return(findMinDepth(root, 1));
}
    
int main(int argc, char** argv) {

    return 0;
}

