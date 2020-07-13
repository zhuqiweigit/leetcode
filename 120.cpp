#include <iostream>
#include <vector>
#include <limits>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n == 0)
            return 0;
        vector<int> dp_pre(n, 0);
        vector<int> dp(n, 0);
        dp_pre[0] = dp[0] = triangle[0][0];
        for(int level = 1; level < n; level++){
            for(int index = 0; index <= level; index++){
                if(index == 0){
                    dp[index] = dp_pre[index] + triangle[level][index];
                }else if(index == level){
                    dp[index] = dp_pre[index - 1] + triangle[level][index];
                }else{
                    dp[index] = min(dp_pre[index - 1], dp_pre[index]) + triangle[level][index];
                }
            }
            dp_pre = dp;
        }
        int ans = numeric_limits<int>::max();
        for(int i = 0; i < n; i++){
            if(dp[i] < ans)
                ans = dp[i];
        }
        return ans;
    }
};

