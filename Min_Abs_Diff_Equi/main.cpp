/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on September 6, 2013, 12:04 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 *  A non-empty zero-indexed array A consisting of N integers is given. Array A represents numbers on a tape.
 *  Any integer P, such that 0 < P < N, splits this tape into two non−empty parts: 
 *  A[0], A[1], ..., A[P − 1] and A[P], A[P + 1], ..., A[N − 1].
 *  The difference between the two parts is the value of: 
 *  |(A[0] + A[1] + ... + A[P − 1]) − (A[P] + A[P + 1] + ... + A[N − 1])|
 *  In other words, it is the absolute difference between the sum of the first part and the sum of the second part.
 *  For example, consider array A such that:
 * A[0] = 3
 * A[1] = 1
 * A[2] = 2
 * A[3] = 4
 * A[4] = 3
 *  We can split this tape in four places:
 *  P = 1, difference = |3 − 10| = 7 
 *  P = 2, difference = |4 − 9| = 5 
 *  P = 3, difference = |6 − 7| = 1 
 *  P = 4, difference = |10 − 3| = 7 
 *  the function should return 1, as explained above.
Assume that:
N is an integer within the range [2..100,000];
each element of array A is an integer within the range [−1,000..1,000].
Complexity:
expected worst-case time complexity is O(N);
expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
 */

int min(int x, int y ){
    if(x < y)
        return x;
    else
        return y;
}

int minAbsDiff(vector<int> &A) {
    
    int right_part = 0;
    for(int i = 0; i < A.size(); i++) {
        right_part += A[i];
    }
    
    int left_part = 0;
    int min_diff = abs((right_part - A[0]) - A[0]);
    
    for(int j = 1; j < A.size(); j++) {
        left_part += A[j-1];
        right_part -= A[j-1];
        min_diff = min(min_diff, abs(left_part - right_part));
    }
    
    return min_diff;
}

int main(int argc, char** argv) {

    int elements[] = {3, 1, 2, 4, 3};
    int length = sizeof(elements)/sizeof(int);
    vector<int> arr;
    
    for(int i = 0; i < length; i++) {
        arr.push_back(elements[i]);
    }
    
    cout << minAbsDiff(arr);
}

