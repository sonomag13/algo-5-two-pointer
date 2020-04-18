//
// Created by strobe on 4/11/20.
//

#pragma once

#include "InsertSorting.h"

#include <ctime>
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

    void primitiveQuickSort(vector<int>& inputVec) {
        _quickSort(inputVec, 0, inputVec.size() - 1);
    }

    void optimizedQuickSort(vector<int>& inputVec) {
        srand(time(NULL));
        _optimizedQuickSort(inputVec, 0, inputVec.size() - 1);
    }

    void quickSort2(vector<int>& inputVec) {
        srand(time(NULL));
        _quickSort2(inputVec, 0, inputVec.size() - 1);
    }

    void quickSort3(vector<int>& inputVec) {
        srand(time(NULL));
        _quickSort3(inputVec, 0, inputVec.size() - 1);
    }

private:
    void _recursiveMergeSort(vector<int>& inputVec, int l, int r) {
        // the range is [l, r]
        if (l >= r)
            return;
        int mid = l + (r - l) / 2;
        _recursiveMergeSort(inputVec, l, mid);
        _recursiveMergeSort(inputVec, mid + 1, r);
        if (inputVec[mid] > inputVec[mid + 1])
            _merge(inputVec, l, mid, r);
    }

    void _merge(vector<int>& inputVec, int l, int mid, int r) {
        // the interval is defined as [l, mid] and [mid+1, r]
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
            for (int i = 0; i + size < n; i += 2 * size) {
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

    void _quickSort(vector<int>& inputVec, int l, int r) {
        if (l >= r) {
            return;
        }
        // arr[l - p-1] < arr[p] and arr[p+1, r] > arr[p]
        int p = _partition(inputVec, l, r);
        _quickSort(inputVec, l, p - 1);
        _quickSort(inputVec, p + 1, r);
    }

    int _partition(vector<int>& inputVec, int l, int r) {
        /*
         the interval of sorting is [l, r]
         return p where arr[l - p-1] < arr[p] and arr[p+1, r] >= arr[p]

         In case of the input vector is nearly ordered (that result in O(n^2) complexity), we should
         void directly using l, but randomly select a number from the vector, and swap it with l
         */
        swap(inputVec[l], inputVec[rand() % (r - l + 1) + l]);
        int j{l}, v{inputVec[l]};
        for (int i = l + 1; i <= r; ++i) {
            if (inputVec[i] < v) {
                swap(inputVec[j + 1], inputVec[i]);
                j++;
            }
        }
        swap(inputVec[l], inputVec[j]);
        return j;
    }

    void _optimizedQuickSort(vector<int>& inputVec, int l, int r) {
        if (r - l <= 15)
            _insertSort(inputVec, r, l);
        // arr[l - p-1] < arr[p] and arr[p+1, r] > arr[p]
        int p = _partition(inputVec, l, r);
        _quickSort(inputVec, l, p - 1);
        _quickSort(inputVec, p + 1, r);
    }

    void _insertSort(vector<int>& inputVec, int l, int r) {
        // this is an optimized insert sorting where multiple swaps is avoided
        int curVal;
        for (int i = l + 1; i <= r; ++i) {
            curVal = inputVec[i];
            int j;
            for (j = i; j > l && curVal < inputVec[j - 1]; j--)
                inputVec[j] = inputVec[j - 1];
            inputVec[j] = curVal;
        }
    }

    void _quickSort2(vector<int>& inputVec, int l, int r) {
        if (r - l <= 15) {
            _insertSort(inputVec, l, r);
            return;
        }
        int p = _partition2(inputVec, l, r);
        _quickSort2(inputVec, l, p - 1);
        _quickSort2(inputVec, p + 1, r);
    }

    int _partition2(vector<int>& inputVec, int l, int r) {
        swap(inputVec[l], inputVec[rand() % (r - l + 1) + l]);
        int val = inputVec[l];
        /*
          arr[l + 1, ..., i) =< arr[l]
          arr(j, ... r] >= arr[l]
         */
        int i = l + 1, j = r;
        while (true) {
            while (i <= r && inputVec[i] < val)
                i++;
            while (j >= l + 1 && inputVec[j] > val)
                j--;
            if (i > j)
                break;
            swap(inputVec[i], inputVec[j]);
            i++;
            j--;
        }
        swap(inputVec[l], inputVec[j]);
        return j;
    }

    void _quickSort3(vector<int>& inputVec, int l, int r) {
        if (r - l <= 15) {
            _insertSort(inputVec, l, r);
            return;
        }
        // randomize and set the mark value
        swap(inputVec[l], inputVec[rand() % (r - l + 1) + l]);
        int markerVal = inputVec[l], curVal;
        /*
            the vector is partitioned into 3 pieces:
            - arr[l + 1, ... lt] < v
            - arr[lt + 1, i) == v
            - arr[gt, r] > v;
            with initial condition lt = l, [l + 1 ... lt] is empty
            with initial condition gt = r + 1, [gt, r] is also empty
         */
        int lt = l, gt = r + 1;
        int i = l + 1;
        while (i < gt) {
            curVal = inputVec[i];
            if (curVal == markerVal)
                i++;
            if (curVal > markerVal) {
                swap(inputVec[gt - 1], inputVec[i]);
                gt--;
            }
            if (curVal < markerVal) {
                swap(inputVec[lt + 1], inputVec[i]);
                lt++;
                i++;
            }
        }
        swap(inputVec[l], inputVec[lt]);
        lt--;
        _quickSort3(inputVec, l, lt);
        _quickSort3(inputVec, gt, r);
    }

};