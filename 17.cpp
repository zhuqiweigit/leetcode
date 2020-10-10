#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <map>
using namespace std;
class Solution {
public:
    vector<string> ans;
    map<string, string>mp = {{"2","abc"}, {"3","def"}, {"4","ghi"}, {"5","jkl"}, {"6","mno"}, {"7","pqrs"},
                             {"8","tuv"}, {"9","wxyz"}};
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return ans;
        dfs(digits, 0, "");
        return ans;
    }

    void dfs(string& digits, int idx, string ss){
        if(idx >= digits.size()){
            ans.push_back(ss);
            return;
        }
        for(auto ch : mp[digits.substr(idx, 1)]){
            dfs(digits, idx + 1, ss + ch);
        }
    }
};