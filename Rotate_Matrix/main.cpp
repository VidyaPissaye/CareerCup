/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on September 13, 2013, 10:16 AM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 *  Rotate nxn matrix clock-wise.
 *  Time complexity is O(n2)
 */

void rotateMatrix(vector<vector<int> > &matrix) {
    if((matrix.size() != 0 ) && (matrix.size() == matrix[0].size())) {
        int n = matrix.size();
        for(int i = 0; i < n/2; i++) {
            for(int j = i; j < n-i-1; j++) {
                int x = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                matrix[j][n-i-1] = x;
            }
        }
    }
}

int main(int argc, char** argv) {

    int elements[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    
    int length = sizeof(elements)/sizeof(int)/4;
    vector<vector<int> > mat;
    
    int k = 0;
    for(int i = 0; i < length; i++) {
        vector<int> arr;
        mat.push_back(arr);
        for(int j = 0; j < length; j++) {
            mat[i].push_back(elements[k++]);
        }
    }
    
    rotateMatrix(mat);
    
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

