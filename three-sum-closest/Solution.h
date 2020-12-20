#include <vector>

using namespace std; 

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
                        
        int numsSize = nums.size();
        int minDelta{INT_MAX}, closestSum{INT_MAX};                
        sort(nums.begin(), nums.end());                 
        
        int i{0};         
        while (i < numsSize - 2) {
            // similar to two sum 
            int l{i + 1}, r{numsSize - 1};                 
            while (l < r) {
                int sum{nums[i] + nums[l] + nums[r]};   // define left and right pointer for the searching
                if (sum == target) {                        
                    return target;  // find an exact macth
                }
                
                int delta{abs(sum - target)};                     
                if (delta < minDelta) {
                    minDelta = delta; 
                    closestSum = sum; 
                }
                                
                if (sum < target) {
                    // skip the duplicated numbers for the l pointer
                    while (l < numsSize - 1 && nums[l] == nums[l + 1]) {
                        l++; 
                    }
                    l++;                             
                }
                else {
                    // skip the duplicated numbers for the r pointer
                    while (r > i && nums[r] == nums[r - 1]) {
                        r--;
                    }
                    r--; 
                }
            }
            
            // skip the duplicated numbers for i pointer
            while (i < numsSize - 2 && nums[i] == nums[i + 1]) {
                i++; 
            }
            i++;
            
        }
                
        return closestSum; 
        
    }
    
};