//
// Created by strobe on 4/11/20.
//

#pragma once

#include <iostream>
#include <vector>

using namespace std;

class SortingMethod {

public:
    void recursiveMergeSort(vector<int>& inputVec) {
        _recursiveMergeSort(inputVec, 0, inputVec.size() - 1);
    }

    void nonrecursiveMergeSort(vector<int>& inputVec) {
        _nonrecursiveMergeSort(inputVec, 0, inputVec.size() - 1);
    }


private:
    // the range is [l, r]
    void _recursiveMergeSort(vector<int>& inputVec, int l, int r) {
        if (l >= r)
            return;
        int mid = l + (r - l) / 2;
        _recursiveMergeSort(inputVec, l, mid);
        _recursiveMergeSort(inputVec, mid + 1, r);
        if (inputVec[mid] > inputVec[mid + 1])
            _merge(inputVec, l, mid, r);
    }

    // the interval is defined as [l, mid] and [mid+1, r]
    void _merge(vector<int>& inputVec, int l, int mid, int r) {
        vector<int> tempVec;
        for (int i = l; i <= r; ++i)
            tempVec.push_back(inputVec[i]);
        // i is defined in [0, mid-l], or [0, mid2]
        // j is defined in [mid-l+1, r-l], or [mid2+1, r2]
        int l2 = l - l, mid2 = mid - l, r2 = r - l;
        int i = l2, j = mid2 + 1;
        // replace the kth element in inputVec with the number from tempVec
        for (int k = l; k <= r; ++k) {
            if (i > mid2) {
                inputVec[k] = tempVec[j];
                j++;
            } else if (j > r2) {
                inputVec[k] = tempVec[i];
                i++;
            } else if (tempVec[i] <= tempVec[j]) {
                inputVec[k] = tempVec[i];
                i++;
            } else {
                inputVec[k] = tempVec[j];
                j++;
            }
        }
    }

    void _nonrecursiveMergeSort(vector<int>& inputVec, int l, int r) {
        int n = inputVec.size();
        for (int size = 1; size <= n; size += size) {
            // cout << "size = " << size << endl;
            // i+size < n ensures that the interval [i+size, i+2*size-1] is not empty
            for (int i = 0; i+size < n; i += 2 * size) {
                /*
                cout << "\ti = " << i;
                cout << "\t\tl = " << i;
                cout << " mid = " << i+size - 1;
                cout << " r = " << i + 2 * size - 1<< endl;
                 */
                // intervals to merge are [i, i+size-1] and [i+size, i+2*size-1]
                _merge(inputVec, i, i + size - 1, min(i + 2 * size - 1, n - 1));
            }
            // cout << "\n-----------------------\n" << endl;
        }
    }
};
