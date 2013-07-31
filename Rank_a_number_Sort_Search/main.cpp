/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on July 27, 2013, 12:58 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */

struct Tree {
    int value;
    Tree* left;
    Tree* right;
};

bool get_rank_of_number(Tree* root, int num, int &rank) {
    if(root == NULL) {
        rank = 0;
        return false;
    }
    
    bool found = get_rank_of_number(root->left, num, rank);
    if(!found) {
        if(root->value != num) {

            int right_rank;
            found = get_rank_of_number(root->right, num, right_rank);
            rank = rank + right_rank + 1;
        }
        else {
            found = true;
        }
    }
    
    return found;
}

Tree* insert_num(Tree* root, int num) {
    
    Tree* node = NULL;
    Tree* ptr = root;
    Tree* new_node = new (Tree);
    new_node->value = num;
    new_node->left = new_node->right = NULL;
    
    while(ptr != NULL) {
        node = ptr;
        if(num <= ptr->value) {
            ptr = ptr->left;
        }
        else {
            ptr = ptr->right;
        }
    }
    
    if(root == NULL) {
        root = new_node;
    }
    else {   
        if(num <= node->value) {
            node->left = new_node;
        }
        else {
            node->right = new_node;
        }   
    }
    return root;
}

Tree* track(Tree* root, int x) {
    return (insert_num(root, x));
}


int main(int argc, char** argv) {

    int array[] = { 10, 6, 15, 4, 18, 5, 12, 1, 3, 16 };
    Tree* root = NULL;
    
    for(int i = 0; i < 10; i++) {
        root = track(root, array[i]);
    }
    
    int num = 16;
    int rank = 0;
    get_rank_of_number(root, num, rank);
    
    cout << rank;
    
}

