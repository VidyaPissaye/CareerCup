/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on September 14, 2013, 10:51 AM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

#include "MinHeap.h"

using namespace std;

/*
 *  Return K most frequent words in a string delimited by space
 */


void insertInMinHeap(string word, MinHeap *heap, TrieNode *root) {
    
    // If word is already present in heap  
    if(root->min_heap_index != -1) {
        (heap->getNodes())[root->min_heap_index].frequency++;
        heap->minHeapify(root->min_heap_index);
    }
    // Word is not in heap and the heap is not full
    else if(heap->getCount() < heap->getCapacity()) {
        int count = heap->getCount();
        heap->getNodes()[count].frequency = root->frequency;
        heap->getNodes()[count].root = root;
        heap->getNodes()[count].word = word;
        
        root->min_heap_index = count;
        heap->setCount(count++);
        heap->buildHeap();
    }
    // Word is not in heap and heap is full and
    // frequency of the word is more than the heap's root. 
    // Since heap's root is the least frequent word in the heap, replace it with the new word
    else if(root->frequency > heap->getNodes()[0].frequency) {
        heap->getNodes()[0].root = root;
        heap->getNodes()[0].root->min_heap_index = 0;
        heap->getNodes()[0].word = word;
        heap->getNodes()[0].frequency = root->frequency;
        
        heap->minHeapify(0);
    }
}

void insertTrieandHeap(string word, string::const_iterator it,  MinHeap *heap, TrieNode *root) {
    
    if(root == NULL) {
        root = newTrieNode();
    }
    
    if(it != word.end()) {
        insertTrieandHeap(word, it++, heap, root->child[tolower(*it) - 'a']);
    }
    else {
        if(root->word_end != false) {
            root->frequency++;
        }
        else {
            root->word_end = true;
            root->frequency = 1;
        }
        
        insertInMinHeap(word, heap, root);
    }
    
}

vector<string> getMostFrequentWords(MinHeap *heap) {
    vector<string> frequent_words;
    
    for(int i = 0; i < heap->getCount(); i++) {
        frequent_words.push_back(heap->getNodes()[i].word);
    }
    
    return frequent_words;
}

vector<string> kFrequentWords(string str, int k) {
    
    MinHeap *heap = new MinHeap(k);
    TrieNode *root = NULL;
    
    string word;
    int i = 0;
    
    while(i < str.size()) {
        while(str[i] != ' ') {
            word.push_back(str[i]);
            i++;
        }
        insertTrieandHeap(word, word.begin(), heap, root);
    }    
    
    return(getMostFrequentWords(heap));
}

int main(int argc, char** argv) {

    string input_string = "This is an amazing problem with a complex and interesting solution It is a tricky and lengthy solution";
    
    vector<string> most_frequent_words = kFrequentWords(input_string, 3);
    
    for(int i = 0; i < most_frequent_words.size(); i++) {
        cout << most_frequent_words[i];
    }
}

