/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on April 29, 2013, 8:05 PM
 */

#include <cstdlib>
#include <iostream>
#include <limits>

using namespace std;

/*
 *   Check if a binary tree is binary search tree.
 */

struct Tree{
    int value;
    Tree* leftnode;
    Tree* rightnode;
}; 

bool CheckBST(Tree* root, int min, int max) {
    if(root == NULL) return true;
    
    if((root->value < min) || (root->value >= max)) {
        return false;
    }
    
    if((!CheckBST(root->leftnode, min, root->value)) || 
       (!CheckBST(root->rightnode, root->value, max))) {
        return false;
    }
    
    return true;
}

bool is_BST(Tree* root) {
    int min = std::numeric_limits<int>::min(); // minimum value
    int max = std::numeric_limits<int>::max();
    return(CheckBST(root, min, max));
}

Tree* insert_node(int data, Tree* root){
    
    Tree* node = (Tree*)malloc(sizeof(Tree));
    node->value = data;
    node->leftnode = node->rightnode = NULL;
    Tree* ptr = root;
    Tree* parent_node = NULL;
    
    while(ptr != NULL) {
        parent_node = ptr;
        
        if(data < ptr->value) {
            ptr = ptr->leftnode;
        }
        else {
            ptr = ptr->rightnode;
        }
    }
    
    if(parent_node == NULL) {
        root = node;
    }
    else if(data < parent_node->value) {
        parent_node->leftnode = node;
    }
    else {
        parent_node->rightnode = node;
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
    
    if(is_BST(root)) {
        cout << "Binary tree is Binary Search Tree" << endl;
    }
}

