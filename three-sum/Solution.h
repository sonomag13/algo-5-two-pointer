//
// Created by strobe on 4/17/20.
//

#ifndef THREE_SUM_SOLUTION_H
#define THREE_SUM_SOLUTION_H

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @return: Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int>> threeSum(vector<int> &numbers) {
        // write your code here
        vector<vector<int>> resultVec;
        if (numbers.empty())
            return resultVec;

        // sort the array
        _mergeSorting(numbers, 0, numbers.size()-1);

        for (int i = 0; i < numbers.size() - 1; i++) {
            if (i > 0 && numbers[i] == numbers[i - 1])
               continue;
            int target = 0 - numbers[i];
            int start = i + 1, end = numbers.size() - 1;
            while (start < end) {
                if (start > i + 1 && numbers[start] == numbers[start - 1]) {
                    start++;
                }
                int sum2 = numbers[start] + numbers[end];
                if (sum2 == target) {
                    vector<int> tripplet;
                    tripplet.push_back(numbers[i]);
                    tripplet.push_back(numbers[start]);
                    tripplet.push_back(numbers[end]);
                    resultVec.push_back(tripplet);
                    start++;
                    end--;
                }
                else if (sum2 > target)
                    end--;
                else
                    start++;
            }
        }

        return resultVec;
    }

private:
    void _mergeSorting(vector<int>& numbers, int l, int r) {
        if (l >= r)
            return;
        int m = l + (r - l) / 2;
        _mergeSorting(numbers, l, m);
        _mergeSorting(numbers, m + 1, r);
        _merge(numbers, l, m, r);
    }

    void _merge(vector<int>& numbers, int l, int m, int r) {
        vector<int> temp;
        for (int i = l; i <= r; ++i) {
            temp.push_back(numbers[i]);
        }
        int l2 = l - l;
        int m2 = m - l;
        int r2 = r - l;
        int i = l2, j = m2 + 1;
        for (int k = l; k <= r; ++k) {
            if (i > m2) {
                numbers[k] = temp[j];
                j++;
            }
            else if (j > r2) {
                numbers[k] = temp[i];
                i++;
            }
            else if (temp[i] <= temp[j]) {
                numbers[k] = temp[i];
                i++;
            }
            else {
                numbers[k] = temp[j];
                j++;
            }
        }
    }

};

#endif  // THREE_SUM_SOLUTION_H
