//
// Created by luther on 12/20/20.
//

#pragma once

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static int lengthOfLongestSubstring(const string& s) {

        // a technique so called sliding window is used for this problem

        int slow{0};
        int longestSize{0};

        /**
         * hash map is used to check if a character has been visited
         * - kay: character
         * - val: the last index points to the character
         */
        unordered_map<char, int> mapCharIdx;

        for (int fast = 0; fast < s.size(); ++fast) {

            char curChar = s[fast];

            // check if the fast pointer points to an already visited character
            if (mapCharIdx.find(curChar) == mapCharIdx.end()) {

                // the character has not been visited
                mapCharIdx.insert(make_pair<char, int>(reinterpret_cast<char &&>(curChar),
                                                       reinterpret_cast<int &&>(fast)));
                int currSize = fast - slow + 1;
                // update the longest size
                if (currSize > longestSize) {
                    longestSize = currSize;
                }
            }
            else {
                slow = fast;
                mapCharIdx[curChar] = fast;
            }

        }

        return longestSize;

    }
};