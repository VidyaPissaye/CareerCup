/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on July 23, 2013, 8:38 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 * 
 */

#define size 10

struct stats {
    int height;
    int weight;
};

void merge(stats (&array)[10], int p, int m, int q) {
    
    int n1 = (m-p)+1;
    int n2 = (q-m);
    
    stats a[n1], b[n2];

    for(int i=0; i < n1; i++){
        a[i] = array[p+i];
    }
    
    for(int j=0; j < n2; j++){
        b[j] = array[m+j+1];
    }
    
    int i=0;
    int j=0;
    
    for(int x = p; x <= q; x++) {
        
        if(i < n1 && j < n2){
            if(a[i].height <= b[j].height){
                array[x] = a[i++];
            }
            else{
                array[x] = b[j++];
            }
        }
        else if(i == n1){
            array[x] = b[j++];
        }
        else{
            array[x] = a[i++];
        }
    }

}

void merge_sort(stats (&array)[10], int p, int q) {
    
    if(p < q){
        int mid = (p + q)/2;
        
        merge_sort(array, p, mid);
        merge_sort(array, mid+1, q);
        merge(array, p, mid, q);
    }
}

bool is_less_than(stats left, stats right) {
    if((left.height < right.height) && (left.weight < right.weight))
        return true;
    else
        return false;
}

void find_best_sequence(stats sequence[], stats best_tower[]) {
    int size1 = sizeof(sequence)/sizeof(stats);
    int size2 = sizeof(best_tower)/sizeof(stats);
    if(size1 < size2) {
        for(int i = 0; i < size2; i++) {
            sequence[i] = best_tower[i];
        }
    }
}

void longest_tower(stats array[], stats best_tower_sequences[][10], int index ) {
    
    if(!(index > (sizeof(array)/sizeof(stats)) || index < 0)) {
    
        stats best_sequence[size];
        for(int i = 0; i < index; i++) {
            if(is_less_than(array[i], array[index])) {
                find_best_sequence(best_sequence, best_tower_sequences[i]);
            }
        }

        int length = sizeof(best_sequence)/sizeof(stats);
        //if(length != 0) {
            best_sequence[length] = array[index];
       // }

        for(int j = 0; j < (length+1); j++) {
            best_tower_sequences[index][j] = best_sequence[j];
        }

        longest_tower(array, best_tower_sequences, index+1);
    }
}

void circus_tower(stats (&array)[10], stats (&best_tower)[10]) {
    int length = sizeof(array)/sizeof(stats);
    merge_sort(array, 0, length-1);
    
    for(int k = 0; k < size; k++) {
        cout << array[k].height << " ";
    }
    
    stats best_tower_sequences[size][size];
    longest_tower(array, best_tower_sequences, 0);
    
    for(int i = 0; i < size; i++) {
        find_best_sequence(best_tower, best_tower_sequences[i]);
    }
}

int main(int argc, char** argv) {

    stats array[size] = {{112, 60}, {115, 55}, {120, 65}, {114, 70}, {122, 70}, {118, 58}, {130, 75}, {125, 80}, {110, 50}, {125, 90}};
    stats tower[size];
    
    circus_tower(array, tower);
    for(int i = 0; i < size; i++) {
        cout << tower[i].height << " : " << tower[i].weight << endl;
    }
    
}

