#include <vector>

class Solution {
public:
    void sortColors(vector<int>& nums) {

        /**
         * define of the intervals for 1, 2 and 3
         * - [0, idx0): 0
         * - [idx0, idx1): 1
         * - [idx1, idx2): unsorted region
         * - [idx2, nums.size()): 2          
         **/

        int idx0 = 0; 
        int idx1 = 0; 
        int idx2 = nums.size();                 
        
        while (idx1 < idx2) {            
            switch (nums[idx1]) {
                case 0:
                    /**
                     * swap the current number and the first number
                     * in the section of 2. 
                     **/ 
                    swap(nums[idx1], nums[idx0]); 
                    idx0++; 
                    idx1++;
                    break;                     
                case 1:
                    /**                     
                     * increase idx2 by 1 since the current number
                     * happens to be 2, so no swap is needed
                     **/
                    idx1++;    
                    break;                                 
                case 2:
                    /**
                     * swap the current number and the number right 
                     * before section of 3                 
                     * 
                     * Notice that idx1 does not increase for this time
                     * since we do not know the new value at nums[idx1],
                     * which could be either 0 or 1
                     **/
                    swap(nums[idx1], nums[idx2 - 1]);
                    idx2--;  
                    break;                    
            }
        }
    }

};
