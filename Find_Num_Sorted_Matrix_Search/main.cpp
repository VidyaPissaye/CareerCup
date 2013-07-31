/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on July 23, 2013, 4:26 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *   Given an M x N matrix in which each row and each column is sorted in 
 *   ascending order. Write a method to find an element.
 */

#define row 5
#define col 5

int find_element_sorted_matrix(int matrix[row][col], int x) {
    
    int i = row - 1, j = col - 1;
    while((j >= 0 && matrix[row-1][j] >= x) && (i >= 0 && matrix[i][col-1] >= x )) {
        i--;
        j--;
    }
    
    if(matrix[row-1][j] == x) {
        return matrix[row-1][j];
    }
    else if(matrix[row-1][j] > x) {
        while(j >= 0 && matrix[row-1][j] >= x) {
            j--;
        }
    }
    
    if(matrix[i][col-1] == x) {
        return matrix[i][col-1];
    }
    else if(matrix[i][col-1] > x) {
        while(i >= 0 && matrix[i][col-1] >= x) {
            i--;
        }
    }
    
    i++;
    j++;
    
    if(matrix[i][j] == x) 
        return matrix[i][j];
    else {
        while((i < row) && matrix[i][j] != x) {
            i++;
        }
        
        if(matrix[i][j] == x) {
            return matrix[i][j];
        }
    
        else{
            while((j < col) && matrix[i][j] != x) {
                j++;
            }

            if(matrix[i][j] == x){
                return matrix[i][j];
            }
            else
                return 0;
        }
    }
}

// Alternate method

bool find_element(int matrix[row][col], int x) {
    int r = 0;
    int c = col-1;
    while (r < row && c >= 0) {
        if(matrix[r][c] == x) {
            return true;
        }
        else if(matrix[r][c] > x) {
            c--;
        }
        else {
            r++;
        }
    }
    
    return false;
}

int main(int argc, char** argv) {

    int matrix[row][col] = {{1, 2, 4, 6, 8}, {3, 10, 12, 14, 16}, {5, 11, 17, 20, 22},
    {7, 13, 18, 21, 23}, {9, 15, 19, 24, 25}}; 
    
    cout << find_element_sorted_matrix(matrix, 20) << endl;
    
    if(find_element(matrix, 6))
        cout << "Element found";
    else 
        cout << "Element not found";
}
