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
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(j == 0 && matrix[i][j] == '1')
                    dp[i][j] = 1;
                else if(matrix[i][j] == '1')
                    dp[i][j] = dp[i][j - 1] + 1;
                else dp[i][j] = 0;
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int min_len = n + 2;
                int top = i;
                while(top >= 0 && dp[top][j] > 0){
                    min_len = min(min_len, dp[top][j]);
                    ans = max(ans, (i - top + 1) * min_len);
                    top--;
                }
            }
        }
        return ans;
    }

};