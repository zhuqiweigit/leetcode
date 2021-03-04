#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        return dp_helper(s);
    }

    int dp_helper(const string &s){
        if(s.empty())
            return 0;
        vector<int> dp(s.size(), 0);
        int max_ans = 0;
        for(int i = 2; i < s.size(); i++){
            if(s[i - 1] == '(')
                continue;
            if(s[i - 2] == '(')
                dp[i] = dp[i - 2] + 2;
            else{
                if(s[i - dp[i - 1] - 2] == '(')
                    dp[i] = dp[i - dp[i - 1] - 2] + dp[i - 1] + 2;
            }
            if(dp[i] > max_ans)
                max_ans = dp[i];
        }
        return max_ans;
    }

    int normal(const string& s){
        if(s.empty())
            return 0;
        int ll = 0, rr = 0, max_ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(')
                ll++;
            else rr++;
            if(rr > ll){
                ll = 0;
                rr = 0;
            }else if(rr == ll){
                if(max_ans < ll * 2)
                    max_ans = ll * 2;
            }
        }
        return max_ans;
    }
};