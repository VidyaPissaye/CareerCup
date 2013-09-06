/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on April 29, 2013, 1:20 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *  Implement a function to check if a binary tree is balanced.
 *  A balanced tree is a tree such that the heights of the two subtrees of 
 *  any node never differ by more than one. 
 */


struct Tree{
    int value;
    Tree* left;
    Tree* right;
};

int is_balanced(Tree* root) {
    if(root == NULL) {
        return 0;
    }
    
    int left_level = is_balanced(root->left);
    int right_level = is_balanced(root->right);
    
    if((left_level >= 0) && (right_level >= 0)) {
        if((left_level == right_level) || ((abs(left_level - right_level)) == 1)) {
            if(left_level > right_level) {
                return (left_level + 1);
            }
            else {
                return (right_level + 1);
            }
        }
    }   
    return -1;
}

// Alternate solution

bool isBalanced(Tree *root) {
        
    int level = 0;
    return(isBalTree(root, level));
        
}
    
bool isBalTree(Tree *root, int &level) {
    if(root != NULL) {
        level++;
        int left_level = level;
        int right_level = level;
        int left_tree = isBalTree(root->left, left_level);
        int right_tree = isBalTree(root->right, right_level);
        if(left_tree != false && right_tree != false &&
            (abs(left_level - right_level) <= 1)) {
            if(left_level == right_level) {
                level = left_level;

            }
            else 
                 level = (left_level > right_level ? left_level : right_level);
            return true;
        }
        else
            return false;

    }
    return true;
}

Tree* insert_node(int data, Tree* root){
    
    Tree* node = (Tree*)malloc(sizeof(Tree));
    node->value = data;
    node->left = node->right = NULL;
    Tree* ptr = root;
    Tree* parent_node = NULL;
    
    while(ptr != NULL) {
        parent_node = ptr;
        
        if(data < ptr->value) {
            ptr = ptr->left;
        }
        else {
            ptr = ptr->right;
        }
    }
    
    if(parent_node == NULL) {
        root = node;
    }
    else if(data < parent_node->value) {
        parent_node->left = node;
    }
    else {
        parent_node->right = node;
    }
    
    return root;
}

int main(int argc, char** argv) {

    int number, elem;
    Tree* root;
    cout << "Enter the number of elements" << endl;
    cin >> number;
    
    cout << "Enter the elements: " << endl;
    for (int i=0; i < number; i++) {
        cin >> elem;
        root = insert_node(elem, root);
    }
    
    if(is_balanced(root) < 0) {
        cout << "The Binary tree is not balanced!" << endl;
    }
    else {
        cout << "The Binary tree is balanced!" << endl;
    }
}

