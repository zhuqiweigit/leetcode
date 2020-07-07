#include <iostream>
#include <vector>
#include <limits>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        int max_ans = dp[0];
        for(int i = 1; i < n; i++){
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            if(max_ans < dp[i])
                max_ans = dp[i];
        }
        return max_ans;
    }
};