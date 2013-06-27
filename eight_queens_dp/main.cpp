/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on April 19, 2013, 1:09 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *  Eight Queens
 */

#define board_size 8

void display_board(int (&queen_pos)[board_size]) {
    static int solution = 1;
    cout << "Solution: " << solution << endl;
    
    for(int row=0; row < board_size; row++) {
        for(int col = 0; col < board_size; col++) {
            if(queen_pos[row] != col) {
                cout << "- ";
            }
            else {
                cout << "Q ";
            }
        }
        cout << endl;
    }
    solution++;
}

bool valid_pos(int row, int (&queen_pos)[board_size], int col) {
    int diag1 = col, diag2 = col;
    
    if(row > 0) {
        for(int i = row-1; i >= 0; i--) {
            if(queen_pos[i] != col) {
                if((--diag1) >= 0) {
                    if(queen_pos[i] == diag1) {
                        return false;
                    }
                }
                
                if((++diag2) < board_size) {
                    if(queen_pos[i] == diag2) {
                        return false;
                    }
                }

            }
            else {
                return false;
            }
        }
    }
    return true;
}

void n_queens(int row, int (&queen_pos)[board_size]) {
    if(row == board_size) {
        display_board(queen_pos);
    }
    else {
        int col = 0;
       /* if(queen_pos[row] != -1) {
            col = queen_pos[row] + 1;
            queen_pos[row] = -1;
        }*/
        
        while(col < board_size) {
            if(valid_pos(row, queen_pos, col)) {
                queen_pos[row] = col;
                n_queens(row+1, queen_pos);
                
            }
            col++;
        }
       /* if((col == board_size) && (queen_pos[row] == -1)) {
            n_queens(row-1, queen_pos);
        }
        n_queens(row+1, queen_pos); */
        
    }
}

void solve_n_queens() {
    
    int queens_board_position[board_size];
    
    for(int i; i < board_size; i++) {
        n_queens(i, queens_board_position);
    }
}

int main(int argc, char** argv) {

    int queens_board_position[board_size] = {-1, -1, -1, -1, -1, -1, -1, -1};
    n_queens(0, queens_board_position);
}

