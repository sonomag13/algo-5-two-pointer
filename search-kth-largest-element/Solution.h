
#pragma once

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {

public:
    int findKthLargestElement (int k, vector<int>& vecIn) {
        return _searchByPQ(k, vecIn);
    }

private:
    int _searchByPQ(int k, vector<int>& vecIn) {
        priority_queue<int> myPQ;
        for (auto i : vecIn) {
            myPQ.push(i);
        }
        while (k > 1) {
            myPQ.pop();
            k--;
        }
        return myPQ.top();
    }


};