/* 
 * File:   MinHeap.h
 * Author: Vidya
 *
 * Created on September 14, 2013, 5:24 PM
 */


#ifndef MINHEAP_H
#define	MINHEAP_H

#include <iostream>
#include <string>
#include "TrieNode.h"

using namespace std;

struct MinHeapNode {
    TrieNode *root;
    string word;
    unsigned int frequency;
};

class MinHeap {
    unsigned int capacity;
    int count;
    MinHeapNode *nodes;
    
public:
    
    MinHeap(int size) : capacity(size) {
        count = 0;
        nodes = new MinHeapNode[capacity];
    }
        
    void buildHeap();
    void minHeapify(int idx);
    void swap(MinHeapNode &a, MinHeapNode &b);
    MinHeapNode* getNodes();
    int getCount();
    int getCapacity();
    void setCount(int newcount);
};

#endif	/* MINHEAP_H */

