#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
using namespace std;
class Solution {
public:
    map<string, bool> memo;
    bool canWin(string s) {
        if (memo.count(s)) return memo[s];
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '+' && s[i - 1] == '+') {
                string t = s;
                t[i] = t[i - 1] = '-';
                if (!canWin(t)) {
                    memo[s] = true;
                    return true;
                }
            }
        }
        memo[s] = false;
        return memo[s];
    }
};