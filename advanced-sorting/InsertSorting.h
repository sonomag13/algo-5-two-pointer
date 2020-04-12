//
// Created by strobe on 4/11/20.
//

#pragma once

#include <iostream>
#include <vector>

using namespace std;

void insertSort(vector<int>& inputVec) {
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