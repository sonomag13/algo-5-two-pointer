// LeetCode 485. Max Consecutive Ones
// Easy

#include <vector>

using namespace std; 

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int maxLen = 0;
        
        int l = 0; 
        
        while (l < nums.size()) {
            
            while (l < nums.size() && nums[l] == 0) {
                l++; 
            }
            
            int r = l; 
            
            while (r < nums.size() && nums[r] == 1) {
                r++; 
            }                        
            
            maxLen = max(maxLen, r - l); 
            
            l = r + 1; 
        }
        
        return maxLen; 
        
    }
};