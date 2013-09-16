
#include "MinHeap.h"

void MinHeap::swap(MinHeapNode &a, MinHeapNode &b) {
    MinHeapNode temp = a;
    a = b;
    b = temp;
}

void MinHeap::minHeapify(int idx) {
    int left = 2 * idx;
    int right = (2 * idx) + 1;
    int smallest = idx;
    
    if(left < count && nodes[left].frequency < nodes[idx].frequency) {
        smallest = left;
    }
    
    if(right < count && nodes[right].frequency < nodes[idx].frequency) {
        smallest = right;
    }
    
    if(smallest != idx) {
        nodes[smallest].root->min_heap_index = idx;
        nodes[idx].root->min_heap_index = smallest;
        swap(nodes[smallest], nodes[idx]);
        minHeapify(smallest);
    }
}

void MinHeap::buildHeap() {
    for(int i = (count-1)/2; i >= 0; i--) {
        minHeapify(i);
    }
}

MinHeapNode* MinHeap::getNodes() {
    return nodes;
}

int MinHeap::getCount() {
    return count;
}

void MinHeap::setCount(int newcount) {
    count = newcount;
}

int MinHeap::getCapacity() {
    return capacity;
}