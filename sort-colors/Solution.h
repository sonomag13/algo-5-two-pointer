/**
    75. Sort Colors
    Medium

    Given an array nums with n objects colored red, white, or blue, sort them in-place 
    so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

    We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

    You must solve this problem without using the library's sort function.

    Example 1:

    Input: nums = [2,0,2,1,1,0]
    Output: [0,0,1,1,2,2]
    Example 2:

    Input: nums = [2,0,1]
    Output: [0,1,2]
    Example 3:

    Input: nums = [0]
    Output: [0]
    Example 4:

    Input: nums = [1]
    Output: [1]

    Constraints:

    n == nums.length
    1 <= n <= 300
    nums[i] is 0, 1, or 2.
 **/

#include <vector>

using namespace std; 

class Solution {
public:
    void sortColors(vector<int>& nums) {
        
         /**        
          * points the next position to accommondate 0
          * interestingly, once having left the initial position, it always points to 1        
          **/ 
         int p0 = 0;             
        
         /**        
          * points the next position to accommondate 2. 
          * p2 + 1 always points to an element 2
          **/
        int p2 = nums.size() - 1;
        
        int k = 0;      // traverse through the array 
        
        while (k <= p2) {
            
            switch(nums[k]) {
                case 0:
                    swap(nums[k], nums[p0]);
                    p0++;
                    k++;    
                    break;
                case 1:
                    k++;
                    break;
                case 2:
                    swap(nums[k], nums[p2]);
                    p2--;
                    break;                    
            }
        }        
    }
};