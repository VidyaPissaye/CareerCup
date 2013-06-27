/* 
 * File:   List.h
 * Author: Vidya
 *
 * Created on April 9, 2013, 12:42 AM
 */

#ifndef LIST_H
#define	LIST_H


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class List {
    Node* head;
    

public:
    
    List() {
        head = NULL;
    }
    
    ~List() {
        delete_all_nodes();
    }
    
    void delete_all_nodes();
    void insert_begin(int data);
    void delete_begin();
    void delete_node(int data);
    void insert_after(int data, int after);
    void insert_before(int data, int before);
    bool is_empty();
    void display_nodes();
};


#endif	/* LIST_H */

