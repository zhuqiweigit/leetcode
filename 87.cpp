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
    bool isScramble(string s1, string s2) {
        int len = s1.size();
        if(s1.size() != s2.size())
            return false;
        bool dp[len][len][len + 1];
        memset(dp, false, sizeof(dp));
        for(int i = 0; i < len; i++){
            dp[i][i][1] = s1[i] == s2[i] ? true : false;
        }
        for(int str_len = 2; str_len <= len; str_len++){
            for(int i = 0; i + str_len <= len; i++){
                for(int j = 0; j + str_len <= len; j++){
                    for(int idx = 1; idx < str_len; idx++){
                        if(dp[i][j][idx] && dp[i + idx][j + idx][str_len - idx]){
                            dp[i][j][str_len] = true;
                            break;
                        }else if(dp[i][str_len - idx][idx] && dp[i + idx][j][str_len - idx]){
                            dp[i][j][str_len] = true;
                            break;
                        }
                    }

                }
            }
        }
        return dp[0][0][len];
    }
};