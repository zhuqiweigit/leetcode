#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
#include <sstream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), ans_max = 0;
        if(n == 0)
            return 0;
        else if(n == 1)
            return nums[0];
        int rob_pre1, rob_pre2 = 0;
        rob_pre1 = nums[0];
        //抢第0个
        for(int i = 1; i < n - 1; i++){
            int rob = max(rob_pre1, rob_pre2 + nums[i]);
            rob_pre2 = rob_pre1;
            rob_pre1 = rob;
            ans_max = max(rob, ans_max);
        }
        rob_pre1 = nums[1];
        rob_pre2 = 0;
        for(int i = 2; i < n; i++){
            int rob = max(rob_pre1, rob_pre2 + nums[i]);
            rob_pre2 = rob_pre1;
            rob_pre1 = rob;
            ans_max = max(ans_max, rob);
        }
        return ans_max;
    }
};