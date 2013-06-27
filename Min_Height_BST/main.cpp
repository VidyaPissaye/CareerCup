/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on April 29, 2013, 11:31 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *  Create a binary search tree with minimum height from the given
 *  sorted array (increasing order) with unique integers.
 */

struct Tree{
    int value;
    Tree* left_node;
    Tree* right_node;
};

Tree* Min_Height_BST(int sorted_arr[], int low, int high) {
    
    if(low > high) {
        return NULL;
    }
    
    int mid = (low+high)/2;
    
    Tree* root = (Tree*)malloc(sizeof(Tree));
    root->value = sorted_arr[mid];

    root->left_node = Min_Height_BST(sorted_arr, low, mid-1);
    root->right_node = Min_Height_BST(sorted_arr, mid+1, high);
    
    return root;
}

Tree* Minimum_Height_BST(int sorted_arr[], int length) {  
    return (Min_Height_BST(sorted_arr, 0, length-1));
}

void inorder_traversal(Tree* root) {
    if(root != NULL) {
        inorder_traversal(root->left_node);
        cout << root->value << "->";
        inorder_traversal(root->right_node);
    }
}

int main(int argc, char** argv) {   
    int sorted_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int length = sizeof(sorted_array)/sizeof(int);
    Tree* BST = Minimum_Height_BST(sorted_array, length);
    inorder_traversal(BST);    
}

