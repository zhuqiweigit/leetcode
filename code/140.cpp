#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <list>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<string> ans;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool>mp;
        for(auto& word : wordDict){
            mp[word] = true;
        }
        vector<bool> dp(s.length() + 1, false);
        for(int i = 1; i <= s.length(); i++){
            for(int j = i - 1; j >= 0; j--){
                string sub = s.substr(j, i - j);
                if(dp[j] == true && mp.find(sub) != mp.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        list<string> path;
        back_trace(s, path, s.length(), mp, dp);
        return ans;
    }

    void back_trace(string &s, list<string> &path, int len, unordered_map<string, bool>& mp, vector<int> dp){
        if(len == 0){
            string ss;
            for(auto iter = path.begin(); iter != path.end(); iter++){
                if(iter == path.begin()){
                    ss = ss + *iter;
                }else{
                    ss = ss + " " + *iter;
                }
            }
            ans.push_back(ss);
            return;
        }

        for(int i = 1; i <= len; i++){
            string subss = s.substr(len - i, i);
            if(dp[len - i] && mp.find(subss) != mp.end()){
                path.insert(path.begin(), subss);
                back_trace(s, path, len - i, mp);
                path.erase(path.begin());
            }
        }
    }

};