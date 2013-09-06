/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on September 3, 2013, 11:49 PM
 */

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
 *   Given a collection of intervals, merge all overlapping intervals.
 *   For example,
 *   Given [1,3],[2,6],[8,10],[15,18],
 *   return [1,6],[8,10],[15,18].
 */

struct Interval {
    int start;
    int end;
};

bool mysort(Interval a, Interval b) {
    return(a.start < b.start);
}

vector<Interval> merge(vector<Interval> &intervals) {
    vector<Interval> res;
    
    if(!intervals.empty()) {
        
        std::sort(intervals.begin(), intervals.end(), mysort);        
        res.push_back(intervals[0]);

        int i = 1;
        while(i < intervals.size()) {
            if(intervals[i].start <= res.back().end) {
                res.back().end = max(intervals[i].end, res.back().end);
            }
            else {    
                res.push_back(intervals[i]);
            }
            i++;
        }
    }
        
    return res;
}

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {

    vector<Interval> res;

    int i = 0;
    while((i < intervals.size()) && (intervals[i].start < newInterval.start)) {
        res.push_back(intervals[i]);
        i++;
    }

    if(newInterval.start <= res.back().end) {
        res.back().end = max(res.back().end, newInterval.end);
    }
    else {
        res.push_back(intervals[i]);
    }

    while(i < intervals.size()) {
        if(intervals[i].start <= res.back().end) {
            res.back().end = max(res.back().end, intervals[i].end);
        }
        else {
            res.push_back(intervals[i]);
        }
        i++;
    }

    return res;
}        

int main(int argc, char** argv) {

    Interval val = {1, 4};
    vector<Interval> input;
    input.push_back(val);
    val.start = 0;
    val.end = 2;
    input.push_back(val);
    val.start = 3;
    val.end = 5;
    input.push_back(val);
    
    vector<Interval> res = merge(input);
    
    int i = 0;
    while(i < res.size()) {
        cout << "[" << res[i].start << "," << res[i].end << "]" << endl;
        i++;
    }  
    
    vector<Interval> insert_input;
    val.start = 1;
    val.end = 2;
    insert_input.push_back(val);
    val.start = 3;
    val.end = 5;
    insert_input.push_back(val);
    val.start = 6;
    val.end = 7;
    insert_input.push_back(val);
    val.start = 8;
    val.end = 10;
    insert_input.push_back(val);
    val.start = 12;
    val.end = 16;
    insert_input.push_back(val);
    val.start = 4;
    val.end = 9;
    
    res = insert(insert_input, val);
    
    i = 0;
    while(i < res.size()) {
        cout << "[" << res[i].start << "," << res[i].end << "]";
        i++;
    } 
}

