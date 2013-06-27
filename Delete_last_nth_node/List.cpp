
#include "List.h"


void List::delete_all_nodes() {    
    Node *temp;
    
    while(head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

bool List::is_empty() {
    if(head == NULL) {
        return true;
    }
    else {
        return false;
    }
}

void List::display_nodes() {
    Node *ptr = head;
    
    if(ptr != NULL) {
        while(ptr != NULL) {
            cout << ptr->data << "->";
            ptr = ptr->next;
        }
        cout << "NULL" << endl;
    }
}

void List::insert_begin(int data) {
    Node *new_node = new Node;
    new_node->data = data;
    
    new_node->next = head;
    head = new_node;
}

void List::delete_begin() {
   
    Node *temp;
    if(head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void List::delete_node(int data) {
    
    if(head != NULL) {

        if(head->data == data) {
            delete_begin();
        }
        else {
            Node *ptr;
            ptr = head;
            Node *temp = ptr->next;
            while ((temp != NULL) && (temp->data != data)) {
                temp = temp->next;
                ptr = ptr->next;
            }
            
            if(temp == NULL) {
                cout << "Element not found!" << endl;
            }
            else {
                ptr->next = temp->next;
                delete temp;
            }
            
        }
        
    }
}

void List::insert_after(int data, int after) {
    
    if(head != NULL) {
        Node *ptr;
        
        Node *temp = new Node;
        temp->data = data;
        temp->next = NULL;
        
        ptr = head;
        
        while ((ptr != NULL) && (ptr->data != after)) {
            ptr = ptr->next;
        }
        
        if(temp == NULL) {
            cout << "Element not found!" << endl;
        }
        else {
            temp->next = ptr->next;
            ptr->next = temp;
        }
    }
}

void List::insert_before(int data, int before) {
    
    if(head != NULL) {
        Node *ptr = head;
        Node *temp = new Node;
        temp->data = data;
        temp->next = NULL;
        
        if(head->data == before) {
            temp->next = head;
            head = temp;
        }
        else{
            while((ptr->next != NULL) && (ptr->next->data != before)){
                ptr = ptr->next;
            }
            
            if(temp == NULL) {
                cout << "Element not found!" << endl;
            }
            else {
                temp->next = ptr->next;
                ptr->next = temp;
            }
        }
    }
}





