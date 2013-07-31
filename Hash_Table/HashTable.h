/* 
 * File:   HashTable.h
 * Author: Vidya
 *
 * Created on July 28, 2013, 12:05 AM
 */

#ifndef HASHTABLE_H
#define	HASHTABLE_H

#include <iostream>

#define max 10

struct Cell {
    int key;
    int value;
};

struct List {
    Cell* cell;
    List* next;
};

class HashTable {
    List* hash;
    
    int get(char* key);
    void put(char* key, int value);
    int hashcode(char* key);
};


#endif	/* HASHTABLE_H */

