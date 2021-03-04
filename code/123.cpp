#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = prices.size();
        if(m == 0)
            return 0;
        const int min_val = numeric_limits<int>::min();
        int dp[m][2][3];
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 0;
        dp[0][0][1] = min_val;
        dp[0][0][2] = min_val;
        dp[0][1][0] = -prices[0];
        dp[0][1][1] = min_val;
        dp[0][1][2] = min_val;
        for(int i = 1; i < m; i++){
            dp[i][0][0] = 0;
            dp[i][0][1] = max(dp[i - 1][1][0] + prices[i], dp[i - 1][0][1]);
            dp[i][0][2] = max(dp[i - 1][1][1] + prices[i], dp[i - 1][0][2]);
            dp[i][1][0] = max(dp[i - 1][0][0] - prices[i], dp[i - 1][1][0]);
            dp[i][1][1] = max(dp[i - 1][0][1] - prices[i], dp[i - 1][1][1]);
            dp[i][1][2] = min_val;
        }
        return max(dp[m - 1][0][2], max(dp[m - 1][0][1], 0));
    }
};