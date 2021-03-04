#include <vector>
#include <iostream>
#include <limits>
using namespace std;
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for(int len = 0; len < n; len++){
            for(int i = 1; i + len <= n; i++){
                int j = i + len;
                if(len == 0) {
                    dp[i][j] = 0;
                }else if(len == 1) {
                    dp[i][j] = i;
                }else{
                    int sum = numeric_limits<int>::max();
                    for(int chose = i + 1; chose < j; chose++){
                        int temp = max(chose + dp[i][chose - 1], chose + dp[chose + 1][j]);
                        if(temp < sum)
                            sum = temp;
                    }
                    sum = min(sum, min(i + dp[i + 1][j], j + dp[i][j - 1]));
                    dp[i][j] = sum;
                }
            }
        }
        return dp[1][n];
    }
};