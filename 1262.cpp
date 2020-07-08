#include <iostream>
#include <vector>
#include <limits>
using namespace std;
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        vector<vector<int>> dp(3, vector<int>(n, 0));
        dp[0][0] = nums[0] % 3 == 0 ? nums[0] : 0;
        dp[1][0] = nums[0] % 3 == 1 ? nums[0] : numeric_limits<int>::min();
        dp[2][0] = nums[0] % 3 == 2 ? nums[0] : numeric_limits<int>::min();
        for(int i = 1; i < n; i++){
            int mod = nums[i] % 3;
            dp[0][i] = max(dp[0][i - 1] , mod == 0 ? dp[0][i - 1] + nums[i] : mod == 1 ? dp[2][i - 1] + nums[i] : dp[1][i - 1] + nums[i]);
            dp[1][i] = max(dp[1][i - 1], mod == 0 ? dp[1][i - 1] + nums[i] : mod == 1 ? dp[0][i - 1] + nums[i] : dp[2][i - 1] + nums[i]);
            dp[2][i] = max(dp[2][i - 1], mod == 0 ? dp[2][i - 1] + nums[i] : mod == 1 ? dp[1][i - 1] + nums[i] : dp[0][i - 1] + nums[i]);
        }
        return dp[0][n - 1];
    }
};
int main(){
    vector<int> nums = {3,6,5,1,8};
    Solution solution;
    cout << solution.maxSumDivThree(nums);
    return 0;
}