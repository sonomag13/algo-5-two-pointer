/*
607. Two Sum III - Data structure design
Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

Example
Example 1:

add(1); add(3); add(5);
find(4) // return true
find(7) // return false
*/

class TwoSum {
public:
    /**
     * @param number: An integer
     * @return: nothing
     */
    
    void add(int number) {
        // write your code here
        numVec.push_back(number); 
    }

    /**
     * @param value: An integer
     * @return: Find if there exists any pair of numbers which sum is equal to the value.
     */
    bool find(int value) {
        unordered_map<int, int> mapValIdx; 
        for (int i = 0; i < numVec.size(); ++i) {
            
            if(mapValIdx.find(value - numVec[i]) == mapValIdx.end()) {
                mapValIdx[numVec[i]] = i; 
            }
            else {
                return true;
            }
        }
        return false; 
    }
    
private:
    vector<int> numVec;  
    
};