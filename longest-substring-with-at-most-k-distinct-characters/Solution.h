class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        
        int maxLength{0};
        
        if (!s.size() || !k) {
            return maxLength;
        }
        
        unordered_map<char, int> mapCharIdx; 
        
        // we use two pointers to form a window, and the window is 
        // sliding through the string
        int fast{0};
        int slow{0}; 
        
        while (fast < s.size()) {
            
            // checkout the current character in the string pointed by 
            char currChar{s[fast]}; 
            
            if (mapCharIdx.find(currChar) == mapCharIdx.end()) {
                // the letter has noot been seen before, create the new
                // entry of the map
                k--; 
                mapCharIdx.insert(make_pair(currChar, fast));                
            }
            
            // no matter if the letter has been seen before, let us record the latest
            // position of the letter, i.e. posted by fast
            mapCharIdx[currChar] = fast; 
            
            // move left pointer to shrink the window if there are more than k 
            // distinctive elements
            while (k < 0) {
                
                char leftChar = s[slow]; 
                int lastPosition{mapCharIdx[leftChar]}; 
                
                if (lastPosition == slow) {
                    mapCharIdx.erase(leftChar);    
                    k++;
                }                
                slow++; 
            }
            
            int currLength{fast - slow + 1};
            maxLength = max(maxLength, currLength); 
            fast++; 
        }
        
        
        return maxLength; 
    }
};