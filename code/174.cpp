#include <stack>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(dungeon.empty())
            return 1;
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX / 2));
        dp[m - 1][n] = dp[m][n - 1] = 1;
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                dp[i][j] = min(max(dp[i + 1][j] - dungeon[i][j], 1), max(dp[i][j + 1] - dungeon[i][j], 1));
            }
        }
        return dp[0][0];
    }
};