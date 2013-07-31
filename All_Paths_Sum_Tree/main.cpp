/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on July 18, 2013, 10:49 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *   Print all the paths that sum up to the given value.
 */

struct Tree {
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

int Traverse_paths(Tree* root, int value, int sum) {
    if((root != NULL) && (root->data + sum <= value)) {
        sum += root->data;
        
        if(sum == value) {
            cout << "Sum is: " << root->data << endl;
            return root->data;
        }
        else {
            int left_val = Traverse_paths(root->left, value, sum);
                
            int right_val = Traverse_paths(root->right, value, sum);
            
            if((left_val != -1) || (right_val != -1)){
                cout << root->data << endl;
                return root->data;
            }
        }   
    }
    return -1;
}

void Traverse_all_paths(Tree* root, int value) {
    if(root != NULL) {
        Traverse_paths(root, value, 0);
        
        Traverse_all_paths(root->left, value);
        Traverse_all_paths(root->right, value);
    }
}

// Alternate method

void print_path(int path[], int start, int end) {
    for(int i = start; i <= end; i++) {
        cout << path[i] << " ";
    }
    cout << endl;
}

void print_all_sum_paths(Tree* root, int value, int path[], int level) {
    if(root != NULL) {
        path[level] = root->data;
        
        int sum = 0;
        for(int i = level; i >= 0; i--) {
            sum += path[i];
            if(sum == value)
                print_path(path, i, level);
        }
        
        print_all_sum_paths(root->left, value, path, level+1);
        print_all_sum_paths(root->right, value, path, level+1);
    }
}

int max(int x, int y) {
    if (x > y)
        return x;
    else 
        return y;
}

int tree_depth(Tree* root) {
    if(root == NULL) 
        return 0;
    else
        return (1 + max(tree_depth(root->left), tree_depth(root->right)));
}

void print_sum_paths(Tree* root, int value) {
    int depth = tree_depth(root);
    int path[depth];
    print_all_sum_paths(root, value, path, 0);
}

int main(int argc, char** argv) {

    int elements[] = { 5, 7, 3, 4, 2, 1, 6 };
     
    Tree* root = NULL;
    int length = sizeof(elements)/sizeof(int);
    
    for (int i=0; i < length; i++) {
        root = insert_node(elements[i], root);
    }
    
    //Traverse_all_paths(root, 12);
    
    print_sum_paths(root, 12);
}

