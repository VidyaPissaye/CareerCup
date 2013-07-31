/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on July 23, 2013, 11:16 AM
 */

#include <cstdlib>
#include <iostream>
#include <stdint.h>

using namespace std;

/*
 *  A monochrome screen is stored as a single array of bytes, allowing 8 
 *  consecutive pixels to be stored in one byte. The screen has width w, where 
 *  w is divisible by 8 (ie., no byte is split across rows). The height of the
 *  screen is derived from the length of the array and the width. Draw a 
 *  horizontal line from (x1, y) to (x2, y).
 */

#define length 50

void Draw_Horizontal_Line(uint8_t (&screen)[length], int width, int x1, int x2, int y) {
    int start_byte = x1 / 8;
    int start_offset = x1 % 8;
    int end_byte = x2 / 8;
    int end_offset = x2 % 8;
    
    if(start_offset != 0) {
        start_byte++;
    }
    
    if(end_offset != 7) {
        end_byte--;
    }
    
    for(int byte = start_byte; byte < end_byte ; byte++) {
        screen[width/8 * y + byte] = (uint8_t) 0xFF;
    }
    
    uint8_t start_mask = (uint8_t) (0XFF >> start_offset);
    uint8_t end_mask = (uint8_t) (~(0XFF >> (end_offset + 1)));
    
    if((x1 / 8) == (x2 / 8)) {
        uint8_t mask = (uint8_t) (start_mask & end_mask);
        screen[(width/8) * y + (x1 / 8)] |= mask;
    }
    else {
        if(start_offset != 0) {
            int start_index = width/8 * y + start_byte - 1;
            screen[start_index] |= start_mask;
        }
        
        if(end_offset != 7) {
            int end_index = width/8 * y + end_byte + 1;
            screen[end_index] |= end_mask;
        }
    }
}

int main(int argc, char** argv) {

    uint8_t screen[length] = {0};
    int width = 16;
    Draw_Horizontal_Line(screen, width, 4, 11, 3);
    
    for(int i = 0; i < length; i++) {
        cout << (int)screen[i] << " ";
    }
}

