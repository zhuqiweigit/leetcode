#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
#include <sstream>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size(), k = s3.size();
        if(m + n != k)
            return false;
        bool dp[m + 1][n + 1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        for(int i = 1; i <= m; i++){
            if(s1[i - 1] == s3[i - 1]){
                dp[i][0] = dp[i - 1][0];
            }
        }
        for(int j = 1; j <= n; j++){
            if(s2[j - 1] == s3[j - 1]){
                dp[0][j] = dp[0][j - 1];
            }
        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(s1[i - 1] == s3[i + j - 1])
                    dp[i][j] |= dp[i - 1][j];
                if(s2[j - 1] == s3[i + j - 1])
                    dp[i][j] |= dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};