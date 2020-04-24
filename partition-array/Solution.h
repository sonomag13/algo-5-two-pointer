
/*
    31. Partition Array
    Given an array nums of integers and an int k, partition the array (i.e move the elements in "nums") such that:

    All elements < k are moved to the left
    All elements >= k are moved to the right
    Return the partitioning index, i.e the first index i nums[i] >= k.

    Example
    Example 1:

    Input:
    [],9
    Output:
    0

    Example 2:

    Input:
    [3,2,2,1],2
    Output:1
    Explanation:
    the real array is[1,2,2,3].So return 1
    Challenge
    Can you partition the array in-place and in O(n)?

    Notice
    You should do really partition in array nums instead of just counting the numbers of integers smaller than k.

    If all elements in nums are smaller than k, then return nums.length
 */

/*
    this problem is similar to 3-way quick sorting
 */

class Solution {
public:
    /**
     * @param nums: The integer array you should partition
     * @param k: An integer
     * @return: The index after partition
     */
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        if (!nums.size()) 
            return 0; 
        int lt = -1, gt = nums.size(); 
        int i = 0; 
        while (i < gt) {
            int val = nums[i]; 
            if (val >= k) {
                swap(nums[gt - 1], nums[i]);
                gt--; 
            }
            else {
                i++;
                lt++;
            }
        }
        return gt; 
    }
};