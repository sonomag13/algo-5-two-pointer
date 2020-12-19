//
// Created by strobe on 4/17/20.
//

#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        // the key issue here is how to garantee the uniqueness of each vector
        vector<vector<int>> result; 
        
        if (nums.empty()) {
            return result; 
        }
        
        sort(nums.begin(), nums.end()); 
        
        for (int i = 0; i < nums.size() - 1; ++i) {
            
            if (nums[i] > 0) {
                /*
                 * The private funcion sum 2 only checks the element behind the ith element, 
                 * i.e. the interval of [i + 1, size), implying that all the elements are greater 
                 * than ith element. That said, if the ith element is already greater than 0, 
                 * there will be no way to find two numbers from [i + 1, size) to make the three
                 * sum be zero
                 */ 
                break; 
            }

            if (i == 0 || nums[i] != nums[i - 1]) {
                /*
                 * - i == 0 is spcified since index -1 does not exist
                 * - Traverse to the number that does not duplicate the previous number. 
                 *   > If the number is visited for the first time, call two sum; 
                 *   > Otherwise, keep skipping the numbers until we see the first different number
                 */
                _twoSum(nums, i, result); 
            }
        }
        
        return result; 
    
    }
    
private: 
    void _twoSum(vector<int>& nums, int i, vector<vector<int>>& result) {
        
        int l = i + 1, r = nums.size() - 1; 
        
        while (l < r) {            
            // calculate 3 sum
            int sum = nums[i] + nums[l] + nums[r];                         
            
            if (sum > 0) {
                r--; 
            } 
            else if (sum < 0) {
                l++;
            }
            else {                
                /** 
                 * Since 3 sum == 0, record the result                 
                 **/
                result.push_back(vector<int> {nums[i], nums[l], nums[r]}); 
                
                /**
                 * To avoid duplicated result, we need to skip the duplicated value in front of
                 * the left pointer and behind the right pointer; otherwise, there will be 
                 * duplicated results
                 **/

                /**
                 * decrease the r pointer
                 **/
                // step 1: decrease r value to the last value that is equal to its original value
                while (l < r && nums[r] == nums[r - 1]) {                    
                    r--; 
                }
                // step 2: decrease r value by 1 such that it points to the first differet value
                r--; 
                
                /**
                 * increase the l pointer
                 **/
                // step 1: increase l value to the last value that is equal to its original value
                while (l < r && nums[l] == nums[l + 1]) {
                    l++;                     
                }
                // step 2: increase value by 1 such that it points to the first differet value
                l++; 
            }
        }        
    }

};