#include <iostream>
#include <vector>
#include <limits>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 0 || n == 1)
            return s;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        string ans;
        for(int len = 0; len < n; len++){
            for(int i = 0; i + len < n; i++){
                int j = i + len;
                if(i == j){
                    dp[i][j] = true;
                }else if(s[i] == s[j]){
                    if(len == 1)
                        dp[i][j] = true;
                    else if(dp[i + 1][j - 1]) dp[i][j] = true;
                }
                if(dp[i][j] && j - i + 1 > ans.length()) ans = s.substr(i, j - i + 1);
            }
        }
        return ans;
    }
};

int main(){
    Solution solution;
    string s = "aba";
    cout << solution.longestPalindrome(s);
    return 0;
}