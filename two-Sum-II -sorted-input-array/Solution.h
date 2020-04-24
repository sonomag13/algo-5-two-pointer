/*
608. Two Sum II - Input array is sorted
中文English
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

Example
Example 1:

Input: nums = [2, 7, 11, 15], target = 9 
Output: [1, 2]
Example 2:

Input: nums = [2,3], target = 5
Output: [1, 2]
Notice
You may assume that each input would have exactly one solution.
 */

class Solution {
public:
    /**
     * @param nums: an array of Integer
     * @param target: target = nums[index1] + nums[index2]
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1; 
        int sum;
        vector<int> result;
        while (l < r) {
            sum = nums[l] + nums[r];
            if (sum == target) {
                result.push_back(l + 1);
                result.push_back(r + 1); 
                return result; 
            }
            if (sum < target) 
                l++;
            if (sum > target)
                r--;
        }
    }
};