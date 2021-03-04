#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int minCut(string s) {
        if(s.empty() || s.size() == 1)
            return 0;
        int m = s.size();
        vector<int> dp(m, 0);
        for(int i = 1; i < m; i++){
            if(check(0, i))
                dp[i] = 0;
            else{
                int min_cut = INT_MAX;
                for(int j = 1; j < i; j++){
                    if(check(j, i) && dp[j - 1] + 1 < min_cut)
                        min_cut = dp[j - 1] + 1;
                }
                dp[i] = min_cut;
            }
        }
        return dp.back();
    }

    bool  check(string& s, int i, int j){
        while(i <= j){
            if(s[i] != s[j])
                return false;
        }
        return true;
    }
};