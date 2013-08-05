/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on August 2, 2013, 12:09 AM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 *  Given n non-negative integers a1, a2, ..., an, where each represents a 
 *  point at coordinate (i, ai). n vertical lines are drawn such that the 
 *  two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which 
 *  together with x-axis forms a container, such that the container contains
 *  the most water. 
 *  Note: You may not slant the container.
 */

#define size 4
    
int findMaxArea(vector<int> &height, int idx, int ht, vector<int> &max_area_array) {
    if(max_area_array[idx] != 0) {
        return max_area_array[idx];
    }
    
    int max_area_for_idx = 0;
    int line = 0;
    while(line < size) {
        if(idx != line) {
            int min_height, area;
            if(height[line] < ht) {
                min_height = height[line];
            }
            else {
                min_height = ht;
            }
                
            area = min_height * abs(idx - line);
            if ( area > max_area_for_idx) {
                max_area_for_idx = area;
            }
        }
        line++;
    }
    max_area_array[idx] = max_area_for_idx;
    return max_area_for_idx;
}


int maxArea(vector<int> &height) {
    vector<int> max_area_array(4, 0);
    int max_area = 0;

    int i = 0;
    while(i < size) {
        int area = findMaxArea(height, i, height[i], max_area_array);
        if(area > max_area) {
            max_area = area;
        }
        i++;
    }        
    return max_area;
}
    
int main(int argc, char** argv) {
    int height_array[] = {1, 2, 4, 3};
    
    vector<int> height;
    
    int i = 0;
    while(i < size) {
        height.push_back(height_array[i]);
        i++;
    }

    cout << maxArea(height);
    
}

