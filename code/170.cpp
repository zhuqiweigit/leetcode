#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

class TwoSum {
private:
    vector<int> nums;
public:
    /** Initialize your data structure here. */
    TwoSum() {

    }

    /** Add the number to an internal data structure.. */
    void add(int number) {
        nums.emplace_back(number);
    }

    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        while(i < j) {
            if (nums[i] + nums[j] < value) {
                i++;
            } else if (nums[i] + nums[j] > value) {
                j--;
            } else {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */