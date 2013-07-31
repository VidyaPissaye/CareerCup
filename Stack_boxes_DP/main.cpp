/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on July 19, 2013, 10:41 AM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 *  Given a stack of n boxes with widths w, heights h, and depths d, stack 
 *  the boxes such that each is larger than the box above it in w, h, and d.
 *  Find the height of the stack (sum of the heights of each box).
 */

typedef tr1::unordered_map<box, vector<box> > hash_map;

struct box {
    int width;
    int height;
    int depth;
};

bool compare_greater(box boxA, box boxB) {
    return ((boxA.depth > boxB.depth) && (boxA.height > boxB.height) 
            && (boxA.width > boxB.width)); 
}

bool compare_smaller(box boxA, box boxB) {
    return ((boxA.depth < boxB.depth) && (boxA.height < boxB.height) 
            && (boxA.width < boxB.width)); 
}

int stack_boxes(vector<box> input_stack, int n, vector<box> & stack, int max_height) {
    if(n == 1) {
        stack.push_back(input_stack[n-1]);
        return (max_height + input_stack[n-1].height);
    }
    else {
        
        max_height = stack_boxes(input_stack, n-1, stack, max_height);
        
        int i = 0;
        
        while(i < stack.size() && input_stack[n-1].height < stack[i].height) {
            i++;
        }
        
        bool is_greater = true;
        if(i < stack.size()) {
            is_greater = compare_greater(input_stack[n-1], stack[i]);
        }
        
        if(is_greater && compare_smaller(input_stack[n-1], stack[i-1])) {
            stack.insert(stack.begin() + i, input_stack[n-1]);
            return(max_height + input_stack[n-1].height);
        }
        
        return max_height;
    }
}

// Alternate method

bool canbeabove(box boxA, box boxB) {
    return ((boxA.depth < boxB.depth) && (boxA.height < boxB.height) 
            && (boxA.width < boxB.width)); 
}

int create_stack_boxes(vector<box> boxes, box bottom, vector<box> & stack, hash_map stack_map) {
    if(bottom != NULL && stack_map.count(bottom) > 0) {
        stack = stack_map[bottom];
    }
    
    int max_height = 0;
    vector<box> max_stack;
    
    for(int i = 0; i < boxes.size(); i++) {
        if(canbeabove(boxes[i], bottom)) {
            vector<box> new_stack;
            int stack_height = create_stack_boxes(boxes, boxes[i], new_stack, stack_map);
            if(stack_height > max_height) {
                max_height = stack_height;
                max_stack = new_stack;
            }
        }
    }
    
    if(bottom != NULL) {
        max_stack[0] = bottom;
    }
    stack_map[bottom] = max_stack;
}

int main(int argc, char** argv) {

    vector<box> input_stack, stack;
    box box1, box2, box3;
    box1.width = 2;
    box1.height = 3;
    box1.depth = 4;
    input_stack.push_back(box1);
    
    box2.width = 1;
    box2.height = 2;
    box2.depth = 3;
    input_stack.push_back(box2);
    
    box3.width = 3;
    box3.height = 1;
    box3.depth = 5;
    input_stack.push_back(box3);
    
    cout << stack_boxes(input_stack, 3, stack, 0);
    
}

