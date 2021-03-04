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
    int min_target = numeric_limits<int>::max();
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            twoSum(nums, target, nums[i], i + 1, nums.size() - 1);
        }
        return min_target;
    }

    void twoSum(vector<int>& nums, int target, int a, int ll, int rr){
        int sum = target - a;
        while(ll < rr){
            if(min_target ==  numeric_limits<int>::max() || abs(nums[ll] + nums[rr] + a - target) < abs(min_target - target)){
                min_target = nums[ll] + nums[rr] + a;
            }
            if(nums[ll] + nums[rr] < sum){
                ll++;
            } else{
                rr--;
            }
        }
    }
};