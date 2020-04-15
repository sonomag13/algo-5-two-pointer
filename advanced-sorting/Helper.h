//
// Created by strobe on 4/11/20.
//

#pragma once

#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

static vector<int> generateRandomNum(int n, int divisor) {
    vector<int> vecRandomNum;
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        vecRandomNum.push_back(rand() % divisor);
    }
    return vecRandomNum;
}

static vector<int> generateQuasiOrderedNum(int nNum, int nSwap) {
    vector<int> outputVec;
    int n1, n2;
    for (int i = 0; i < nNum; ++i) {
        outputVec.push_back(i);
    }
    for (int i = 0; i < nSwap - 1; ++i) {
        n1 = rand() % nNum;
        n2 = rand() % nNum;
        swap(outputVec[n1], outputVec[n2]);
    }
    return outputVec;
}

static vector<int> duplicateVect(vector<int> inputVec) {
    vector<int> outputVec;
    for (int i = 0; i < inputVec.size(); ++i) {
        outputVec.push_back(inputVec[i]);
    }
    return outputVec;
}

void printRunTime(const string& methodName, clock_t startTime, clock_t endTime) {
    char* str2Print;
    sprintf(str2Print,
            "\nrun time of %s = %f sec",
            methodName.c_str(),
            double(endTime - startTime) / CLOCKS_PER_SEC);
    cout << str2Print << endl;
}

void printSortStatus(bool isSorted) {
    cout << "\tSort status = " << isSorted << endl;
}

void printVec(vector<int> inputVec) {
    int k = 0, n = 49;
    for (int i = 0; i < inputVec.size(); ++i) {
        cout << inputVec[i] << " -> ";
        k++;
        if (k == n) {
            k = 0;
            cout << endl;
        }
    }
}

bool isSorted(vector<int>& inputVec) {
    for (int i = 1; i < inputVec.size(); ++i) {
        if (inputVec[i - 1] > inputVec[i])
            return false;
    }
    return true;
}