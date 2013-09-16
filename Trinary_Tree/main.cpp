/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on September 10, 2013, 9:30 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *  Implement insert and delete in a tri-nary tree. A tri-nary tree is much like a binary 
tree but with three child nodes for each parent instead of two -- with the left node being values 
less than the parent, the right node values greater than the parent, and the middle nodes values 
equal to the parent.
 */

struct tree {
    int val;
    tree *parent;
    tree *left, *right, *mid;
};

tree* insert_node(tree *root, int value) {
    tree *newnode = (tree*)malloc(sizeof(tree));
    newnode->val = value;
    newnode->left = newnode->right = newnode->mid = NULL;
    
    tree *ptr = root;
    tree *parent = NULL;
    
    while((ptr != NULL) && (ptr->val != value)) {
        parent = ptr;
        
        if(value < ptr->val) {
            ptr = ptr->left;
        }
        else {
            ptr = ptr->right;
        }
    }
    
    if((ptr != NULL) && ptr->val == value) {
        newnode->mid = ptr->mid;
        if(ptr->mid != NULL)
            ptr->mid->parent = newnode;
        
        newnode->parent = ptr;
        ptr->mid = newnode;
    }
    else if(parent == NULL) {
        root = newnode;
    }
    else if(newnode->val < parent->val) {
        parent->left = newnode;
        newnode->parent = parent;
    }
    else {
        parent->right = newnode;
        newnode->parent = parent;
    }
    
    return root;
}

tree* find_node(tree *root, int value) {
    tree *ptr = root;
    
    while((ptr != NULL) && (ptr->val != value)) {
        if(value < ptr->val)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    
    return ptr;
}

void replace_node(tree *root, tree *a, tree *b) {
    if((a == NULL) || (a->parent == NULL)) {
        root = b;
    }
    else {
        if(a->parent->left == a) {
            a->parent->left = b;
        }
        else {
            a->parent->right = b;
        }
    }
    if(b != NULL) {
        b->parent = a->parent;
    }
}

tree* minimum(tree *root) {
    while(root->left != NULL) {
        root = root->left;
    }
    
    return root;
}

// Replace the node with its duplicate, if exists
// Otherwise, replace it with its successor
tree* delete_node(tree *root, int value) {
    tree *node = find_node(root, value);
    
    if(node != NULL) {
        if(node->mid != NULL) {
            replace_node(root, node, node->mid);
            node->mid->left = node->left;
            
            if(node->left != NULL)
                node->left->parent = node->mid;
            
            node->mid->right = node->right;
            
            if(node->right != NULL)
                node->right->parent = node->mid;
            
            node->mid = NULL;
        }
        else {
            if(node->left == NULL) {
                replace_node(root, node, node->right);
            }
            else if(node->right == NULL) {
                replace_node(root, node, node->left);
            }
            else {
                tree *min = minimum(node->right);

                if(min->parent != node) {
                    replace_node(root, min, min->right);
                    min->right = node->right;
                    node->right->parent = min;
                }

                replace_node(root, node, min);
                min->left = node->left;
                node->left->parent = min;
            }
        }
        delete(node);
    }
    return root;
}

// Delete all occurrences of value
tree* delete_node_all(tree *root, int value) {
    tree *node = find_node(root, value);
    
    if(node != NULL) {
        if(node->left == NULL) {
            replace_node(root, node, node->right);
        }
        else if(node->right == NULL) {
            replace_node(root, node, node->left);
        }
        else {
            tree *min = minimum(node->right);

            if(min->parent != node) {
                replace_node(root, min, min->right);
                min->right = node->right;
                node->right->parent = min;
            }

            replace_node(root, node, min);
            min->left = node->left;
            node->left->parent = min;
        }

        delete(node);

    }
    return root;
}

void inorder_traversal(tree* node) {
  
    if(node != NULL) {
        inorder_traversal(node->left);
        cout << node->val << " ";
        tree *ptr = node->mid;
        while(ptr != NULL) {
            cout << ptr->val << " ";
            ptr = ptr->mid;
        }
        inorder_traversal(node->right);
    }
    
}

int main(int argc, char** argv) {

    int elements[] = {5, 4, 9, 4, 5, 7, 2, 2};
    int length = sizeof(elements)/sizeof(int);
    
    int i = 0;
    tree *root = NULL;
    
    while(i < length) {
        root = insert_node(root, elements[i]);
        i++;
    }
    
    inorder_traversal(root);
    cout << endl;
    
    root = delete_node(root, 7);
    
    inorder_traversal(root);
}

