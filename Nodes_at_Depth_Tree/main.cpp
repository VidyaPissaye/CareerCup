/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on July 10, 2013, 10:54 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 *   Create linked list of nodes at each depth of a binary tree.
 */

#define max 50

struct Tree{
    int data;
    Tree* left;
    Tree* right;
};

struct llist {
    Tree* data;
    llist* next;
};

Tree* insert_node(int data, Tree* root){
    
    Tree* node = (Tree*)malloc(sizeof(Tree));
    node->data = data;
    node->left = node->right = NULL;
    Tree* ptr = root;
    Tree* parent_node = NULL;
    
    while(ptr != NULL) {
        parent_node = ptr;
        
        if(data < ptr->data) {
            ptr = ptr->left;
        }
        else {
            ptr = ptr->right;
        }
    }
    
    if(parent_node == NULL) {
        root = node;
    }
    else if(data < parent_node->data) {
        parent_node->left = node;
    }
    else {
        parent_node->right = node;
    }
    
    return root;
}


int create_list_at_level(Tree* tree_node, llist* result[], int &length, int level) {
    
    if(tree_node == NULL) return 0;
    
    llist* new_level_list;
    llist* new_node = NULL;
    
    if(length == level) {
        new_level_list = NULL;
        length++;
    }
    else {
        new_level_list = result[level];
    }
    
    new_node = (llist*)malloc(sizeof(llist));
    new_node->data = tree_node;
    new_node->next = new_level_list;
    new_level_list = new_node; 
    
    result[level] = new_level_list;
    
    create_list_at_level(tree_node->left, result, length, level+1);
    create_list_at_level(tree_node->right, result, length, level+1);
    
}

int main(int argc, char** argv) {
    
    llist* array_of_lists[max];
    int elements[] = { 5, 7, 3, 4, 2, 1, 6 };
    
    Tree* root;
    int length = sizeof(elements)/sizeof(int);
    
    for (int i=0; i < length; i++) {
        root = insert_node(elements[i], root);
    }
    
    int size = 0;
    create_list_at_level(root, array_of_lists, size, 0);
    
    for(int j = 0; j < size; j++) {
        llist* level_list = array_of_lists[j];
        llist* it = level_list;
        while(it != NULL) {
            cout << it->data->data << " ";
            it = it->next;
        }
        
    }
    
}

