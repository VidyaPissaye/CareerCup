/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on July 17, 2013, 11:06 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *   Find out if a tree2 is a subtree of tree1
 */

struct Tree{
    int data;
    Tree* left;
    Tree* right;
};

Tree* insert_node(int data, Tree* root) {
    
    Tree* new_node = (Tree*)malloc(sizeof(Tree));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
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
        root = new_node;
    }
    else if(data < parent_node->data) {
        parent_node->left = new_node;
    }
    else {
        parent_node->right = new_node;
    }
    
    return root;
}

bool compare_nodes(Tree* node1, Tree* node2) {
    if(node1->data == node2->data)
        return true;
    else
        return false;
}

Tree* search_node(Tree* root, Tree* node) {
    if(root == NULL) 
        return NULL;
    
    if(compare_nodes(root, node)) {
            return root;
    }
    
    Tree* subroot = search_node(root->left, node);
    if(subroot != NULL)
        return subroot;
    else
        return search_node(root->right, node);
}

bool traverse_tree(Tree* t1, Tree* t2) {
    if ((t1 == NULL) && (t2 == NULL))
        return true;
    
    if((t1 != NULL) && (t2 != NULL)) {
        if(compare_nodes(t1, t2)) {
            return(traverse_tree(t1->left, t2->left) && 
                    traverse_tree(t1->right, t2->right));
        }
        
    }
    return false;
}

bool is_sub_tree(Tree* t1, Tree* t2) {
    Tree* sub_root = search_node(t1, t2);
    
    if(sub_root) {
        return(traverse_tree(sub_root, t2));
    }
    
    return false;
}

int main(int argc, char** argv) {

    int elements[] = { 5, 7, 3, 4, 2, 1, 6 };
    int elements2[] = {3, 4, 2, 1};
    
    Tree* tree1 = NULL;
    Tree* tree2 = NULL;
    int length1 = sizeof(elements)/sizeof(int);
    int length2 = sizeof(elements2)/sizeof(int);
    
    for (int i=0; i < length1; i++) {
        tree1 = insert_node(elements[i], tree1);
    }
    
    for (int j=0; j < length2; j++) {
        tree2 = insert_node(elements2[j], tree2);
    }
    
    if(is_sub_tree(tree1, tree2)) 
        cout << "Tree2 is a subtree of Tree1";
    else
        cout << "Tree2 is not a subtree of Tree1";
}

