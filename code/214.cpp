#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
#include <sstream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string ss = s;
        reverse(ss.begin(), ss.end());
        ss = s + "#" + ss + ".";
        vector<int> next = getNextArr(ss);
        int len = next.back();
        string sub = s.substr(len, s.size());
        reverse(sub.begin(), sub.end());
        return sub + s;
    }

    vector<int> getNextArr(const string& p){
        int k = -1;
        int j = 0;
        vector<int> next(p.size());
        next[0] = -1;
        while(j < p.size() - 1){
            if(k == -1 || p[k] == p[j]){
                next[++j] = ++k;
            }else{
                k = next[k];
            }
        }
        return next;
    }
};