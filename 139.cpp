#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.length() == 0)
            return false;
        int n = s.length();
        vector<bool> dp(n, false);
        vector<string>::iterator it = find(wordDict.begin(), wordDict.end(), s.substr(0, 1));
        if(it != wordDict.end()) {
            dp[0] = true;
        }else{
            dp[0] = false;
        }
        for(int i = 1; i < n; i++){
            if((it = find(wordDict.begin(), wordDict.end(), s.substr(0, i + 1))) != wordDict.end()){
                dp[i] = true;
                continue;
            }else{
                for(int j = 0; j < i; j++){
                    if(dp[j] == true && (it = find(wordDict.begin(), wordDict.end(), s.substr(j + 1, i - j))) != wordDict.end()){
                        dp[i] = true;
                        continue;
                    }
                }
            }
        }
        return dp[n - 1];
    }

};