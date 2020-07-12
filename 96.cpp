#include <iostream>
#include <vector>
#include <limits>
using namespace std;
class Solution {
public:
    int numTrees(int n) {
        if(n == 0 || n == 1)
            return 1;
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for(int node_num = 2; node_num <= n; node_num++){
            for(int root = 1; root <= node_num; root++){
               dp[node_num] += dp[root - 1] * dp[node_num - root];
            }
        }
        return dp[n];
    }
};