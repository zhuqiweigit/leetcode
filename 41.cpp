#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int N = nums.size();
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= 0)
                nums[i] = N + 1;
        }
        for(int i = 0; i < nums.size(); i++){
            if(abs(nums[i]) <= N){
                if(nums[abs(nums[i]) - 1] > 0)
                    nums[abs(nums[i]) - 1] *= -1;
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0)
                return i + 1;
        }
        return N + 1;
    }
};