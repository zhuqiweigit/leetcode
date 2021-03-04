#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
using namespace std;
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.size(), n = s.size();
        if(m == 0 && t == 0)
            return 1;
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        dp[0][0] = 1;
        for(int j = 1; j <= n; j++)
            dp[0][j] = 1;
        for(int i = 1; i <= m; i++){
            for(int j = i; j <= n; j++){
                if(t[i - 1] == s[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                }else{
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};