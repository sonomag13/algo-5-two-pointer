/**
    LeetCode-18. 4Sum
    Medium

    Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

    Notice that the solution set must not contain duplicate quadruplets.

    Example 1:
    Input: nums = [1,0,-1,0,-2,2], target = 0
    Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
    
    Example 2:
    Input: nums = [], target = 0
    Output: []
    

    Constraints:

    0 <= nums.length <= 200
    -109 <= nums[i] <= 109
    -109 <= target <= 109

 **/

#include <vector>

using namespace std; 

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> result; 
        _target = target; 
        _numsSize = nums.size(); 
        
        // empty or insufficient input
        if (nums.empty() || nums.size() < 4) {
            return result; 
        }
        
        // sort the input array
        sort(nums.begin(), nums.end());        
        
        // let i, j point two first two numbers, and use l and r for two sum searching        
        
        for (int i = 0; i < nums.size() - 3; ++i) {            
            // skip the duplicated numbers of the i pointer
            if (i == 0 || nums[i] != nums[i - 1]) {                
                int j = i + 1;                 
                while (j < nums.size() - 2) {                    
                    _findTwoSum(nums, i, j, result);                                         
                    // skip the dublicpated number of the j pointer
                    while (j < _numsSize - 2 && nums[j + 1] == nums[j]) {
                        j++; 
                    }
                    j++;    // hereby j points to a different number
                }                
            }            
        }
        
        return result; 
        
    }

private: 
    
    int _target{0}; 
    int _numsSize{0}; 
    
    void _findTwoSum(const vector<int>& nums, int i, int j, vector<vector<int>>& result) {
        int l{j + 1};
        int r{_numsSize - 1}; 
        
        while (l < r) {
            int sum = nums[i] + nums[j] + nums[l] + nums[r]; 
        
            if (sum < _target) {
                while (l < _numsSize - 1 && nums[l] == nums[l + 1]) {
                    l++; 
                }
                l++; 
            }

            if (sum > _target) {
                while (r > j && nums[r] == nums[r - 1]) {
                    r--;         
                }
                r--; 
            }

            if (sum == _target) {                
                // find a solution
                result.push_back(vector<int>{nums[i], nums[j], nums[l], nums[r]});                 
                // skip the duplicated numbers on the left side by increasing l
                while (l < _numsSize - 1 && nums[l] == nums[l + 1]) {
                    l++; 
                }
                l++;                
                // skip the duplicated numbers on the right side by decreasing r
                while (r > j && nums[r] == nums[r - 1]) {
                    r--;         
                }
                r--; 
            }

        }        
    }        
    
};