/* 
 * File:   TrieNode.h
 * Author: Vidya
 *
 * Created on September 14, 2013, 5:32 PM
 */

#ifndef TRIENODE_H
#define	TRIENODE_H

#include <iostream>
#include <vector>

using namespace std;

#define MAX_CHARS 26

struct TrieNode {
    vector<TrieNode*> child;
    unsigned int frequency;
    bool word_end;
    int min_heap_index;
};

TrieNode* newTrieNode() {
    TrieNode *trie = new TrieNode;
    trie->frequency = 0;
    trie->min_heap_index = -1;
    trie->word_end = false;
    
    for(int i = 0; i < MAX_CHARS; i++) {
        trie->child.push_back(NULL);
    }
    
    return trie;
}


#endif	/* TRIENODE_H */

