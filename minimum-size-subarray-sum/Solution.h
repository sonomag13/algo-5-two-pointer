#include <iostream>

using namespace std; 

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0; 
        int right = 0; 
        int sum = 0; 
        int minLength = INT_MAX; 

        while (right < nums.size()) {
            sum += nums[right];

            if (sum >= target) {
                while (sum - nums[left] >= target && left <= right) {
                    sum -= nums[left];
                    ++left; 
                }
                minLength = min(minLength, right - left + 1); 
            }
            
            ++right; 
        }

        if (minLength == INT_MAX) {
            return 0; 
        }

        return minLength; 
    }
};