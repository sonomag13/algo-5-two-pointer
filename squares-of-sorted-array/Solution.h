/*
    977. Squares of a Sorted Array

    Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

    Example 1:

    Input: nums = [-4,-1,0,3,10]
    Output: [0,1,9,16,100]
    Explanation: After squaring, the array becomes [16,1,0,9,100].
    After sorting, it becomes [0,1,9,16,100].

    Example 2:
    Input: nums = [-7,-3,2,3,11]
    Output: [4,9,9,49,121]
 */

#include <vector>

using namespace std; 

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        vector<int> result; 
        
        int numSize = nums.size(); 
        
        int positiveIdx{0}, negativeIdx{0}; 

        /**
         * located the first non-zero element of the array
         * 
         * Special cases:
         * - All the numbers are negative, s.t. positiveIdx = numSize
         * - All the numbers are non-zero, s.t. positiveIdx = 0
         */ 
        while (positiveIdx < numSize && nums[positiveIdx] < 0) {
            positiveIdx++; 
        }        
        
        negativeIdx = positiveIdx - 1; 
        
        while (negativeIdx >= 0 || positiveIdx < numSize) {
            
            /**
             * initialize the square value of the positive and negative to
             * be maximum integer; if the pointer are point to a legitimate
             * position, i.e. [0, numSize), calculate the square value with 
             * the corresponding value in the vector
             **/ 
            int val1{INT_MAX}, val2{INT_MAX};
            if (negativeIdx >= 0) {
                val1 = nums[negativeIdx] * nums[negativeIdx]; 
            }
            
            if (positiveIdx < numSize) {
                val2 = nums[positiveIdx] * nums[positiveIdx]; 
            }
            
            /**
             * compare the squares yielded by the two pointers, append
             * the smaller one to the result, and move the pointers accordingly
             **/
            if (val1 < val2) {
                result.push_back(val1); 
                negativeIdx--; 
            }
            else {
                result.push_back(val2); 
                positiveIdx++; 
            }                                    
        }
        
        return result;     
        
    }
    
};