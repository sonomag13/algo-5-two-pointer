// LeetCode 905. Sort Array By Parity
// Easy

$include <vector>

using namespace std; 

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int l = 0; 
        int r = nums.size() - 1; 
        
        while (l < r) {
            
            if (nums[l] % 2 == 0) {
                l++; 
            }
            else {
                swap(nums[l], nums[r]);
                r--; 
            }            
        }
        
        return nums; 
    }
};