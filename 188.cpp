#include <stack>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n <= 1 || k <= 0)
            return 0;
        int dp[k + 1][2];
        fill(dp[0], dp[0] + (k + 1) * 2, INT_MIN / 2);
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        int ans = -1;
        for(int i = 1; i < n; i++){
            dp[0][0] = 0;
            ans = max(ans, dp[0][0]);
            for(int j = 1; j <= k; j++){
                dp[j][0] = max(dp[j - 1][1] + prices[i], dp[j][0]);
                dp[j][1] = max(dp[j][0] - prices[i], dp[j][1]);
                ans = max(ans, dp[j][0]);
            }
        }
        return ans;
    }
};