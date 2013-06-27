/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on April 19, 2013, 12:42 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *  Add two numbers represented as linked list where each node contains a digit.
 *  Write a function to add the two numbers if
 *  1. the digits are stored in reverse order
 *  2. the digits are stored in forward order
 * 
 */

struct llist{
    int data;
    llist* next;
};

llist* add_reverse(llist* num1, llist* num2) {
    
    int carry = 0;
    llist* sum = NULL;
    llist* ptr = sum;
    int total = 0;
    
    while(num1 != NULL || num2 != NULL) {
        if(num1 != NULL && num2 != NULL) {
            total = num1->data + num2->data + carry;
        }
        else if(num1 != NULL) {
            total = num1->data + carry;
        }
        else {
            total = num2->data + carry;
        }
        carry = 0;
        
        if(total >= 10) {
            carry = total / 10;
            total %= 10;
        }
        llist* new_node = (llist*)malloc(sizeof(llist));
        new_node->data = total;
        new_node->next = NULL;

        if(sum == NULL) {
            sum = new_node;
            ptr = sum;
        }
        else {
            ptr->next = new_node;
            ptr = ptr->next;
        }
        
        if(num1 != NULL)
            num1 = num1->next;
        if(num2 != NULL)
            num2 = num2->next;
    }
    
    return sum;
}

llist* reverse_list(llist* list) {
    llist* head = NULL;
    llist* ptr = NULL;
    
    while(list != NULL) {
        ptr = list;
        list = list->next;
        ptr->next = head;
        head = ptr;
    }
    return head;
}

llist* add_forward(llist* num1, llist* num2) {
    llist* n1 = reverse_list(num1);
    llist* n2 = reverse_list(num2);
    
    llist* reverse_sum = add_reverse(n1, n2);
    return(reverse_list(reverse_sum));
}

void display(llist *start) {
    llist *ptr = start;
    if(start == NULL) {
        cout << "Empty list" << endl;
    }
    else {
        while(ptr != NULL) {
            cout << ptr->data << "->";
            ptr = ptr->next;
        }
        cout << endl;
    }
}

int main(int argc, char** argv) {

    llist *number1 = NULL;
    llist *number2 = NULL;
    
    int n = 0;
    while(n<3) {
        llist *node = (llist*)malloc(sizeof(llist));
        cout << "Enter the digit to insert into list1: ";
        cin >> node->data;
        node->next = number1;
        number1 = node;
        n++;
    }
    
    n=0;
    while(n<3) {
        llist *node = (llist*)malloc(sizeof(llist));
        cout << "Enter the digit to insert into list2: ";
        cin >> node->data;
        node->next = number2;
        number2 = node;
        n++;
    }
    
    llist* sum = add_forward(number1, number2);
    display(sum);
}

