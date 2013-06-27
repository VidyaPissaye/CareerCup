/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on June 16, 2013, 6:55 PM
 */

#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;

/*
 *  Given sorted array of strings interspersed with empty strings,
 *  find the location of given string.
 */

int search_string(string (&string_arr)[13], int low, int high, string str) {
    
    int mid = (low + high) / 2;
    
    if(low > high) return -1;
    
    if(str.compare(string_arr[mid]) == 0) {
        return mid;
    }
    else {
        int i = mid - 1; 
        int j = mid + 1;
        
        while((i >=0) && (j < high) && 
              ((string_arr[i] == "") && string_arr[j] == "")) {
            i--;
            j++;
        }
        
        if((string_arr[i] != "") && (string_arr[j] != "")) {
            if(str.compare(string_arr[i]) == 0) {
                return i;
            }
            else if(str.compare(string_arr[j]) == 0) {
                return j;
            }
            else {
                if((tolower(str[0]) - tolower(string_arr[i][0])) < 0) {
                    return(search_string(string_arr, low, i-1, str));
                }
                else {
                    return(search_string(string_arr, j+1, high, str));
                }
            }
        }
        else if(string_arr[i] != "") {
            if(str.compare(string_arr[i]) == 0) {
                return i;
            }
            else if((tolower(str[0]) - tolower(string_arr[i][0])) > 0) {
                return(search_string(string_arr, j+1, high, str));
            }
            else {
                return(search_string(string_arr, low, i-1, str));
            }
        }
        else if(string_arr[j] != "") {
            if(str.compare(string_arr[j]) == 0) {
                return j;
            }
            else if((tolower(str[0]) - tolower(string_arr[j][0])) < 0) {
                return(search_string(string_arr, low, i-1, str));
            }
            else {
                return(search_string(string_arr, j+1, high, str));
            }
        }
    }
    
}

int main(int argc, char** argv) {

    string array[13] = {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", "tree"};   
    
    int arr_len = sizeof(array)/sizeof(array[0]);
    string str = "dad";
    
    int index = search_string(array, 0, arr_len-1, str);
    
    cout << "The string is found at: " << index << endl;
}

