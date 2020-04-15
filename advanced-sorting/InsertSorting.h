//
// Created by strobe on 4/11/20.
//

#pragma once

#include <iostream>
#include <vector>

using namespace std;


void primitiveInsertSort(vector<int>& inputVec) {
    /*
        primitive insert order
        swap is expensive
     */
    for (int i = 1; i < inputVec.size(); ++i) {
        for (int j = i; j > 0; j--) {
            if (inputVec[j] < inputVec[j - 1]) {
                swap(inputVec[j], inputVec[j - 1]);
            } else {
                break;
            }
        }
    }
}

void optimizedInsertSort(vector<int>& inputVec) {
    /*
        optimize version
        this version avoids multiple swap
     */
    for (int i = 1; i < inputVec.size(); ++i) {
        int currentVal = inputVec[i], j;
        for (j = i; j > 0 && currentVal < inputVec[j - 1]; j--)
            inputVec[j] = inputVec[j - 1];
        inputVec[j] = currentVal;
    }
}