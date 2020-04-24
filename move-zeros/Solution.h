/*
539. Move Zeroes
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example
Example 1:

Input: nums = [0, 1, 0, 3, 12],
Output: [1, 3, 12, 0, 0].
Example 2:

Input: nums = [0, 0, 0, 3, 1],
Output: [3, 1, 0, 0, 0].
Notice
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
 */

/*
    two pointers: a fast one and slow one
    the fast pointer 
        - points to each value of the array
        - fast++ unconditionally
    the slow pointer 
        - points to the index where a nonzero element should be inserted
        - slow++ only if a nonzero element is inserted
 */

class Solution {
public:
    /**
     * @param nums: an integer array
     * @return: nothing
     */
    void moveZeroes(vector<int> &nums) {
        // write your code here
        int slow = 0; 
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != 0) {
                nums[slow] = nums[fast];
                slow++; 
            }
        }
        for (int fast = slow; fast < nums.size(); fast++) {
            nums[fast] = 0; 
        }
    }
};