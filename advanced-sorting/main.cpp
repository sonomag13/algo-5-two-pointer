
#include "AdvSorting.h"
#include "Helper.h"
#include "InsertSorting.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {

    int nNum = 1000000;
    int nDiviser = 20;
    clock_t startTime, endTime;
    vector<int> vecRandNum0 = generateRandomNum(nNum, nDiviser);
    // vector<int> vecRandNum0 = generateQuasiOrderedNum(nNum, 10);
    vector<int> vecRandNum1 = duplicateVect(vecRandNum0);
    vector<int> vecRandNum2 = duplicateVect(vecRandNum0);
    vector<int> vecRandNum3 = duplicateVect(vecRandNum0);
    vector<int> vecRandNum4 = duplicateVect(vecRandNum0);
    vector<int> vecRandNum5 = duplicateVect(vecRandNum0);
    vector<int> vecRandNum6 = duplicateVect(vecRandNum0);
    SortingMethod sortingMethod;

    cout << "\n\n\ntest with completely random number array" << endl;

    // insert sorting
    /*
    startTime = clock();
    primitiveInsertSort(vecRandNum0);
    endTime = clock();
    printRunTime("primitive insert sorting", startTime, endTime);
    printSortStatus(isSorted(vecRandNum0));

    startTime = clock();
    optimizedInsertSort(vecRandNum5);
    endTime = clock();
    printRunTime("optimized insert sorting", startTime, endTime);
    printSortStatus(isSorted(vecRandNum5));
     */

    // recursive merge sorting - top down
    startTime = clock();
    sortingMethod.recursiveMergeSort(vecRandNum1);
    endTime = clock();
    printRunTime("recursive merge sorting", startTime, endTime);
    printSortStatus(isSorted(vecRandNum1));

    // nonrecursive merge sorting - bottom up
    /*
    startTime = clock();
    sortingMethod.nonrecursiveMergeSort(vecRandNum2);
    endTime = clock();
    printRunTime("nonrecursive merge sorting", startTime, endTime);
    printSortStatus(isSorted(vecRandNum2));
     */

    // primitive quick sorting
    /*
    startTime = clock();
    sortingMethod.primitiveQuickSort(vecRandNum3);
    endTime = clock();
    printRunTime("primitive quick sort", startTime, endTime);
    printSortStatus(isSorted(vecRandNum3));


    // optimized quick sorting
    startTime = clock();
    sortingMethod.optimizedQuickSort(vecRandNum4);
    endTime = clock();
    printRunTime("optimized quick sort", startTime, endTime);
    printSortStatus(isSorted(vecRandNum4));
     */

    // 2-way quick sorting
    startTime = clock();
    sortingMethod.quickSort2(vecRandNum5);
    endTime = clock();
    printRunTime("2-way quick sort", startTime, endTime);
    printSortStatus(isSorted(vecRandNum5));

    // 3-way quick sort
    startTime = clock();
    sortingMethod.quickSort3(vecRandNum6);
    endTime = clock();
    printRunTime("3-way quick sort", startTime, endTime);
    printSortStatus(isSorted(vecRandNum6));

    return 0;
}
