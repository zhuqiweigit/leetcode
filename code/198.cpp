#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        int pre_steal = nums[0];
        int pre_not_steal = 0;
        for(int i = 1; i < n; i++){
            int now_steal = pre_not_steal + nums[i];
            int now_not_steal = max(pre_not_steal, pre_steal);
            pre_not_steal = now_not_steal;
            pre_steal = now_steal;
        }
        return max(pre_steal, pre_not_steal);
    }
};