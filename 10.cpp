#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for(int j = 1; j < n; j++){
            if(p[j] == '*'){
                if(j == 1)
                    dp[0][j] = true;
                else
                    dp[0][j] = dp[0][j - 2];
            }
        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(s[i - 1] == p[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }else if(p[j - 1] == '.'){
                       dp[i][j] = dp[i - 1][j - 1];
                }else if(p[j - 1] == '*'){
                    if(p[j - 2] != s[i - 1] && p[j - 2] != '.')
                        dp[i][j] = dp[i][j - 2];
                    else
                        dp[i][j] = dp[i][j - 1] || dp[i - 1][j] || dp[i][j - 2];
                }
            }
        }
        return dp[m][n];

    }
};