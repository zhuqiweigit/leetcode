#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <unordered_map>
#include <stack>
using namespace std;
class Solution {
public:
    bool wordPatternMatch(string pattern, string s) {
        unordered_map<string, char> stop;
        unordered_map<char, string> ptos;
        return back_trace(pattern, 0, s, 0, ptos, stop);
    }

    bool back_trace(string& pattern, int idx_p, string& s, int idx_s,
                    unordered_map<char, string>& ptos, unordered_map<string, char>& stop){
        if(idx_p == pattern.size() && idx_s == s.size()){
            return true;
        }else if(idx_p == pattern.size() || idx_s == s.size()){
            return false;
        }

        if(ptos.find(pattern[idx_p]) != ptos.end()){
            int len = ptos[pattern[idx_p]].size();
            return ptos[pattern[idx_p]] == s.substr(idx_s, len) && back_trace(pattern, idx_p + 1, s, idx_s + ptos[pattern[idx_p]].size(), ptos, stop);
        }else{
            for(int i = idx_s; i < s.size(); i++){
                string sub_s = s.substr(idx_s, i - idx_s + 1);
                if(stop.find(sub_s) != stop.end())
                    continue;
                ptos[pattern[idx_p]] = sub_s;
                stop[sub_s] = pattern[idx_p];
                bool succeed = back_trace(pattern, idx_p + 1, s, i + 1, ptos, stop);
                stop.erase(sub_s);
                ptos.erase(pattern[idx_p]);
                if(succeed) return true;
            }
            return false;
        }

    }
};