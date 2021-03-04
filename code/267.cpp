#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
using namespace std;
class Solution {
public:
    vector<string> ans;
    vector<string> generatePalindromes(string s) {
        map<char, int> count;
        for(auto ch : s){
            count[ch]++;
        }
        string odds;
        int len = 0;
        for(auto &[k, v] : count){
            if(v % 2 != 0) {
                odds += k;
                v--;
                len--;
            }
            if(odds.size() > 1)
                return {};
            v /= 2;
            len += v;
        }
        string path;
        dfs(count, path, odds, 0, len);
        return ans;
    }

    void dfs(map<char, int> &count, string& path, string &odds, int idx, int len){
        if(idx == len){
            string temp(path);
            reverse(temp.begin(), temp.end());
            ans.push_back(path + odds + temp);
            return;
        }
        for (auto &[k, v] : count) {
            if (v > 0) {
                v--;
                path.push_back(k);
                dfs(count, path, odds, idx + 1, len);
                path.pop_back();
                v++;
            }
        }
    }
};