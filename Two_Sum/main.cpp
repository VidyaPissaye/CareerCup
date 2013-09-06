/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on August 31, 2013, 5:55 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 *  Given an array of integers, find two numbers such that they add up to a specific target number.
 *  The function twoSum should return indices of the two numbers such that they 
 *  add up to the target, where index1 must be less than index2. 
 *  Please note that your returned answers (both index1 and index2) are not zero-based. 
 *  You may assume that each input would have exactly one solution.
 *  Input: numbers={2, 7, 11, 15}, target=9 
 *  Output: index1=1, index2=2
 */

vector<int> twoSum(vector<int> &numbers, int target) {
        
    //sort(numbers.begin(), numbers.end());
    vector<int> indices;
        
    int i = 0, j = 0;
    while(i < numbers.size()) {
        j = i + 1;
        while(j < numbers.size()) {
            if(numbers[i] < target && numbers[j] < target) {
                if((numbers[i] + numbers[j]) == target) {
                    indices.push_back(i+1);
                    indices.push_back(j+1);
                    return indices;
                }
            }
            j++;
        }
        i++;
    }

    return indices;
}

//Alternate solution O(n)

vector<int> twoSum(vector<int> &numbers, int target) {
        
    vector<int> indices;
    tr1::unordered_map<int, int> hash_map;        
        
    int i = 0;
    while(i < numbers.size()) {
        if(hash_map.count(numbers[i]) > 0) {
            tr1::unordered_map<int, int>::iterator it = hash_map.find(numbers[i]);
            if(it->second < i) {
                indices.push_back(it->second + 1);
                indices.push_back(i + 1);
                break;
            }
        }
        else {
            hash_map.insert(make_pair(target - numbers[i], i));
        }

        i++;
    }
        
    return indices;
}

int main(int argc, char** argv) {

    int nums[] = {150, 24, 79, 50, 88, 345, 3};
    int size = sizeof(nums)/sizeof(int);
    vector<int> numbers;
    int target = 200;
    
    for(int i = 0; i < size; i++) {
        numbers.push_back(nums[i]);
    }
    
    vector<int> sum = twoSum(numbers, target);
    cout << sum[0] << " : ";
    cout << sum[1];
}

