// LeetCode 11. Container With Most Water
// Medium

#include <vector>

using namespace std; 

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int maxVol = 0;
        
        int l = 0; 
        int r = height.size() - 1; 
        
        while (l < r) {
            
            int curVol = min(height[r], height[l]) * (r - l);            
            maxVol = max(maxVol, curVol);
            
            if (height[l] < height[r]) {
                // currently l is shorter, such that it only makes sense
                // to try out l + 1
                l++;
            }
            else {
                r--;
            }
        }
                
        return maxVol;
        
    }
};