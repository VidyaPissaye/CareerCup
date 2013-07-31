
#include "HashTable.h"


int HashTable::get(char* key) {
   int index = hashcode(key);
   
   if(hash[index] != 0) {
      
   
   List* node = hash[index];
   while(node != NULL) {
       if(node->cell->key != key) {
           node = node->next;
       }
       else {
           return node->cell->value;
       }
   }
   }
   return -1;
}

void HashTable::put(char* key, int value) {
    
    List* head;
    int index = hashcode(key);
    if(hash[index] != NULL) {
        head = hash[index];
    }
    
    List* node = new (List);
    node->cell->key = key;
    node->cell->value = value;
    node->next = head;
    head = node;
    hash[index] = head;
}

int HashTable::hashcode(char* key) {
    return(strlen(key) % max);
}