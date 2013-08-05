/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on July 15, 2013, 12:41 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *   Given two nodes in a tree, find their common ancestor.
 */

struct node{
    int data;
    node* left;
    node* right;
    node* parent;
};

bool compare_nodes(node* node1, node* node2) {
    if(node1->data == node2->data)
        return true;
    else
        return false;
}

bool search_node(node* node, node* root) {
    if(root != NULL) {
        if(compare_nodes(node, root)) {
            return true;
        }
        else {
            if(!search_node(node, root->left)) {
                return(search_node(node, root->right));
            }
            return true;
        }
    }
    return false;
}

node* find_common_ancestor(node* root, node* node1, node* node2) {
    if (root == NULL) {
        return NULL;
    }
    else if(compare_nodes(root, node1) || compare_nodes(root, node2)) {
        return root;
    }
    else {
        bool is_node1_on_left = search_node(node1, root->left);
        bool is_node2_on_left = search_node(node2, root->left);
        
        if(is_node1_on_left != is_node2_on_left) {
            return root;
        }
        
        if(is_node1_on_left) {
            return(find_common_ancestor(root->left, node1, node2));
        }    
        else {
            return(find_common_ancestor(root->right, node1, node2));
        }
    }
}

// Common ancestor with access to parent

node* find_common_ancestor_parent(node* root, node* node1, node* node2) {
    bool success = search_node(node1, root);
    
    if(success) {
        success = false;
        
        if(search_node(node2, node1)) {
            return ((node1->parent) ? node1->parent : node1);
        }
        else {
            node* parent = node1;

            while((parent->parent != NULL) && !success ) {
                root = parent;
                parent = parent->parent;
                
                if(compare_nodes(parent, node2)) {
                    return ((parent->parent) ? parent->parent : parent);
                }
                else {
                    if(root == parent->left) {
                        root = parent->right;
                    }
                    else {
                        root = parent->left;
                    }
                    success = search_node(node2, root);
                }
            }
            if(success)
                return parent;
        }
    }
    return NULL;
}

node* insert_node(int data, node* root) {
    
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = new_node->right = new_node->parent = NULL;
    node* ptr = root;
    node* parent_node = NULL;
    
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
        new_node->parent = parent_node;
    }
    else {
        parent_node->right = new_node;
        new_node->parent = parent_node;
    }
    
    return root;
}

node* search(int data, node* root) {
    node* ptr = root;
    
    while((ptr != NULL) && (data != ptr->data)) {
        if(data < ptr->data){
            ptr = ptr->left;
        }
        else {
            ptr = ptr->right;
        }
    }
    return ptr;
}

int main(int argc, char** argv) {

    int elements[] = { 5, 7, 3, 4, 2, 1, 6 };
    
    node* root = NULL;
    int length = sizeof(elements)/sizeof(int);
    node *node1, *node2;
    
    for (int i=0; i < length; i++) {
        root = insert_node(elements[i], root);
    }
    
    node1 = search(1, root);
    node2 = search(6, root);
    
    node* ancestor = find_common_ancestor(root, node1, node2);
    cout << "Common ancestor is " << ancestor->data;
    
}

