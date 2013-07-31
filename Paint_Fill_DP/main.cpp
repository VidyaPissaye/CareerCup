/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on July 19, 2013, 12:59 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 *  Given a screen, a point, and a new colour, fill in the surrounding area
 *  until the colour changes from the original colour.
 */

#define max 6

enum colour { green, blue, red, pink, yellow };

bool paint_fill(int screen[][max], int x, int y, int ocolour, int ncolour) {
    int screen_length = sizeof(screen[0])/sizeof(int);
    if(x < 0 || x >= screen_length || y < 0 || y >= screen_length) {
        return false;
    }
    
    if(screen[y][x] == ocolour) {
        screen[y][x] = ncolour;
        paint_fill(screen, x-1, y, ocolour, ncolour);
        paint_fill(screen, x+1, y, ocolour, ncolour);
        paint_fill(screen, x, y-1, ocolour, ncolour);
        paint_fill(screen, x, y+1, ocolour, ncolour);
    }
    return true;
}

int main(int argc, char** argv) {

    int colour = blue;
    int screen[max][max];
    
    for(int i = 0; i < max; i++) {
        for(int j = 0; j < max; j++) {
            screen[i][j] = colour;
        }
    }
    
    paint_fill(screen, 2, 3, blue, red);
    
    for(int i = 0; i < max; i++) {
        for(int j = 0; j < max; j++) {
            cout << screen[i][j] << " ";
        }
        cout << endl;
    }
    
}

