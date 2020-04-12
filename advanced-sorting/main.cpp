
#include "AdvSorting.h"
#include "Helper.h"
#include "InsertSorting.h"

#include <iostream>
#include <vector>


using namespace std;

int main() {

    int nNum = 100000;
    clock_t startTime, endTime;
    vector<int> vecRandNum0 = generateRandomNum(nNum);
    vector<int> vecRandNum1 = duplicateVect(vecRandNum0);
    vector<int> vecRandNum2 = duplicateVect(vecRandNum0);
    SortingMethod sortingMethod;

    cout << "\n\n\ntest with completely random number array" << endl;

    // insert sorting
    startTime = clock();
    insertSort(vecRandNum0);
    endTime = clock();
    printRunTime("insert sorting", startTime, endTime);
    printSortStatus(isSorted(vecRandNum0));

    // recursive merge sorting - top down
    startTime = clock();
    sortingMethod.recursiveMergeSort(vecRandNum1);
    endTime = clock();
    printRunTime("recursive merge sorting", startTime, endTime);
    printSortStatus(isSorted(vecRandNum1));

    // nonrecursive merge sorting - bottom up
    startTime = clock();
    sortingMethod.nonrecursiveMergeSort(vecRandNum2);
    endTime = clock();
    printRunTime("nonrecursive merge sorting", startTime, endTime);
    printSortStatus(isSorted(vecRandNum2));

    // quick sorting

    return 0;

}
