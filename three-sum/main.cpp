/*
  Description
    Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all
    unique triplets in the array which gives the sum of zero.

    Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)

    The solution set must not contain duplicate triplets.

    Example
    Example 1:

    Input:[2,7,11,15]
    Output:[]
    Example 2:

    Input:[-1,0,1,2,-1,-4]
    Output:	[[-1, 0, 1],[-1, -1, 2]]
 */

#include "Solution.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {

    /*
     The array is given by
     {-2, -3, -4, -5, -100, 99, 1, 4, 4, 4, 5, 1, 0, -1, 2, 3, 4, 5}
     and the answer is
     [[-100,1,99],[-5,0,5],[-5,1,4],[-5,2,3],[-4,-1,5],[-4,0,4],[-4,1,3],[-3,-2,5],[-3,-1,4],
      [-3,0,3],[-3,1,2],[-2,-1,3],[-2,0,2],[-2,1,1],[-1,0,1]]
     */
    vector<int> inputVec {-2, -3, -4, -5, -100, 99, 1, 4, 4, 4, 5, 1, 0, -1, 2, 3, 4, 5};
    Solution find3Sum;
    vector<vector<int>> resultVec = find3Sum.threeSum(inputVec);
    for (auto i : inputVec) {
        cout << i << " <> ";
    }
    cout << endl;

    for (auto i : resultVec) {
        for (auto j : i) {
            cout << j << " => ";
        }
        cout << endl;
    }

    return EXIT_SUCCESS;

}
