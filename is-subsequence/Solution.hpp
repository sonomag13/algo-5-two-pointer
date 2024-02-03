#include <iostream>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {

        if (s == "") {
            return true; 
        }
        
        int ps = 0; 
        int pt = 0; 

        while(ps < s.length() && pt < t.length()) {
            if (ps == s.length() - 1 && s[ps] == t[pt]) {
                return true; 
            }

            if (s[ps] == t[pt]) {
                ++ps; 
                ++pt; 
            }
            else {
                ++pt;
            }
        } 

        return false; 
    }
};