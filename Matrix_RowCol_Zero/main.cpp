/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on April 1, 2013, 3:40 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 *   If an element in an MxN matrix is 0, the entire row and column is made 0.
 */

struct element {
    int row;
    int col;
};

const int rows=4;
const int cols=5;
typedef int Mymatrix[rows][cols];

void matrix_zero(Mymatrix matrix) {
    vector<element> elements;
    element elem;
    
    for(int i=0; i < rows; i++) {
        for(int j=0; j<cols; j++){
            if(matrix[i][j] == 0) {
                elem.row = i;
                elem.col = j;
                elements.push_back(elem);
            }
        }
    }
    
    for(int i=0; i < elements.size(); i++) {
        for(int j=0; j < cols; j++)
            matrix[elements[i].row][j] = 0;
        
        for(int k=0; k < rows; k++)
            matrix[k][elements[i].col] = 0;
    }
}

int main(int argc, char** argv) {
    
    Mymatrix matrix = {{1,2,3,4,5}, {5,0,6,7,8}, {8,9,0,11,12}, {10,12,13,14,15}};
    
    matrix_zero(matrix);
    
    for(int i=0; i<4; i++) {
        for(int j=0; j<5; j++){
            cout << matrix[i][j] << "|";
        }
        cout<<endl;
    }
}

