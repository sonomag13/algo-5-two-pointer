#include <iostream>

#include "Solution.h"

using namespace std;

int main() {
    string testStr{"dvdf"};   //{"abcabcbb"};

    int longestSize{Solution::lengthOfLongestSubstring(testStr)};

    cout << "longest substring without repeating character = " << longestSize << endl;

    return 0;
}
