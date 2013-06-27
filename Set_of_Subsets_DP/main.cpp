/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on June 6, 2013, 11:51 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 *   Return a set of subsets
 */

int subsets(int n, int set[], vector<vector<int> > & array) {
    
    if(n == 0) {
        return 0;
    }
    if(n == 1) {
        vector<int> n_val;
        n_val.push_back(set[n-1]);
        array.push_back(n_val);
        return 1;
    }
    
    subsets(n-1, set, array);
    
    int array_size = array.size();
    vector<int> n_value;
    n_value.push_back(set[n-1]);
    array.push_back(n_value);
    
    for(int i=0; i < array_size; i++) {
        vector<int> temp;
        for(int j=0; j < array[i].size(); j++) {
            temp.push_back(array[i][j]);
        }
        temp.push_back(set[n-1]);
        array.push_back(temp);
    }    
    
    return 1;
}

int main(int argc, char** argv) {

    vector<vector<int> > arr;
    int set[] = {5, 7, 3, 8};
    
    int length = sizeof(set)/sizeof(int);
    subsets(length, set, arr);
    
    for(int i = 0; i < arr.size(); i++) {
        cout << "{";
        for(int j=0; j < arr[i].size(); j++) {
            cout << arr[i][j] << ", ";
        }
        cout << "} ";
    }
    
}

