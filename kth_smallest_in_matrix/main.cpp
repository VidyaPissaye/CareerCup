/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on September 15, 2013, 1:54 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 *  Given a matrix sorted in rows and columns, find the kth smallest element
 */

void minHeapify(vector<int> &elements, int &index) {
    int left = 2 * index;
    int right = (2 * index) + 1;
    int smallest = index;
    
    if(left < elements.size() && elements[left] < elements[index])
        smallest = left;
    
    if(right < elements.size() && elements[right] < elements[index])
        smallest = right;
    
    if(smallest != index) {
        swap(elements[index], elements[smallest]);
        minHeapify(elements, smallest);
        index = smallest;
    }
}

        
int buildHeap(vector<int> &elements) {
    int length = elements.size() - 1;
    
    for(int i = (length - 1) / 2; i >= 0; i--) {
        minHeapify(elements, i);
    }
}

int kSmallestElement(vector<vector<int> > matrix, int k) {
    
    if(k <= (matrix.size() * matrix[0].size())) {
        vector<int> heap;
        vector<int> indices;
        
        // Get first column elements and create a heap
        for(int i = 0; i < matrix.size(); i++) {
            heap.push_back(matrix[i][0]);
            indices.push_back(0);
        }

        buildHeap(heap);
                
        int j = 1;
        int row = 0;
        
        while(j < k) {
            heap[0] = matrix[row][++indices[row]];
            row = 0;
            minHeapify(heap, row);
            j++;
        }
        
        return heap[0];
    }
    
    return -1;
}

int main(int argc, char** argv) {

    int elements[] = {1, 3, 5, 2, 4, 6, 7, 8, 9};
    
    vector<vector<int> > matrix;
    int max_row = 3, max_col = 3;
    int p = 0;
    
    for(int i = 0; i < max_row; i++) {
        vector<int> row_elem;
        
        for(int j = 0; j < max_col; j++) {
            row_elem.push_back(elements[p++]);
        }
        matrix.push_back(row_elem);
    }
    
    int k = 9;
    cout << kSmallestElement(matrix, k);   
}

