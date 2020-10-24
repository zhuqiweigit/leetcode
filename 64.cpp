#include <iostream>
#include <vector>
#include <limits>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0)
            return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += grid[0][i];
            dp[0][i] = sum;
        }
        sum = 0;
        for(int i = 0; i < m; i++){
            sum += grid[i][0];
            dp[i][0] = sum;
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};