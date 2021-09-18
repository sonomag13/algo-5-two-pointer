// LeetCode 941. Valid Mountain Array
// Easy

#include <vector>

using namespace std; 

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        
        int l = 0; 
        int r = arr.size() - 1;
        
        while (l < arr.size() - 1) {
            if (arr[l] == arr[l + 1]) {
                return false; 
            }
            
            if (arr[l] > arr[l + 1]) {
                break; 
            }                            
            l++;
        }
        
        if (l == 0) {
            return false; 
        }
        
        while (0 < r) {
            if (arr[r - 1] == arr[r]) {
                return false;
            }
            if (arr[r - 1] < arr[r]) {
                break;
            }
            r--; 
        }
        
        if (r == arr.size() - 1) {
            return false; 
        }
        
        return l == r; 
        
    }
};