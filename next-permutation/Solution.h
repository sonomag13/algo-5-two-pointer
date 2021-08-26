/*
    31. Next Permutation
    Medium

    Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

    If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

    The replacement must be in place and use only constant extra memory.

    Example 1:
    Input: nums = [1,2,3]
    Output: [1,3,2]


    Example 2:
    Input: nums = [3,2,1]
    Output: [1,2,3]


    Example 3:
    Input: nums = [1,1,5]
    Output: [1,5,1]


    Example 4:
    Input: nums = [1]
    Output: [1]
 */
#include <algorithm>
#include <limits.h>
#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
                
        // The goal is to reorder the vector, such that
        //  1. the number formed by the numbers in the reordered vector is greater 
        //     than the current number
        //  AND 
        //  2. while there might be multiple numbers formed by the reordered vectors
        //     is greater than the current number, we want the samllest
        
        // first traverse the vector from right to left for the first number who is 
        // less than the number on the right. 
        //  - if not found, this means that the current vector yeild the largest number, 
        //    we need to reverse the vector
        //  - if found, we mark it as left, let swap a greater number and left, such that 
        //    the number is larger, then just reorder [left + 1, right] in the vector to make 
        //    the samllest
        int left = -1, right = nums.size() - 1; 
        
        int idx = right; 
        while (idx > 0) {
            if (nums[idx - 1] < nums[idx]) {
                // a smaller number is found
                left = idx - 1; 
                break;
            }
            idx--; 
        }
        
        if (left == -1) {
            // the vector is in the descent order, meaning the number is the largest, then 
            // reverse the vector for the smallest
            reverse(nums.begin(), nums.end());
            return; 
        }
        
        int lowestVal{INT_MAX};
        int idxLowestVal{left}; 
        for (int i = left + 1; i <= right; ++i) {
            if (nums[i] > nums[left] && nums[i] < lowestVal) {
                lowestVal = nums[i];
                idxLowestVal = i; 
            }
        }
        
        // swap the left and the pointer that is just 1 position greater larger than left
        swap(nums[left], nums[idxLowestVal]);
        
        // sort the numbers in the range of [left + 1, right] to make it smallest
        sort(nums.begin() + left + 1, nums.end());         
        
    }
};