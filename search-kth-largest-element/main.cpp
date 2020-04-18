
#include "Solution.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> vecInt {1, 3, 4, 2};
    Solution solution;
    char resultStr[128];
    int k = 1;
    int kthLargestNum = solution.findKthLargestElement(k, vecInt);

    sprintf(resultStr, "\nthe %dth largest element = %d", k, kthLargestNum);

    cout << resultStr << endl;

    return 0;
}
