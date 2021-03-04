#include <iostream>
#include <vector>
#include <limits>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        vector<int> dp(n, 0);
        dp[0] = 1;
        int ans = 1;
        for(int i = 1; i < n; i++){
            int max_pre_len = 1;
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j] && dp[j] >= max_pre_len){
                    max_pre_len = dp[j] + 1;
                }
            }
            dp[i] = max_pre_len;
            if(dp[i] > ans)
                ans = dp[i];
        }
        return ans;
    }
};
int main(){
    vector<int> nums = {10,9,2,5,3,7,101,18};
    Solution solution;
    solution.lengthOfLIS(nums);
    return 0;
}