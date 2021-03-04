#include <iostream>
#include <vector>
#include <limits>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m <= 0 || n <= 0)
            return 0;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i = 0; i < m; i++){
            dp[0][i]  = 1;
        }
        for(int i = 0; i < n; i++){
            dp[i][0] = 1;
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[j][i] = dp[j - 1][i] + dp[j][i - 1];
            }
        }
        return dp[n - 1][m - 1];
    }
};