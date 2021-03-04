#include <iostream>
#include <vector>
#include <limits>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n == 0)
            return 0;
        vector<int> dp(n, 0);
        dp[0] = 0;
        dp[1] = 0;
        for(int i = 2; i < n; i++){
            dp[i] = min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
        }
        return min(dp[n - 1] + cost[n - 1], dp[n - 2] + cost[n - 2]);
    }
};