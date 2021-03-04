#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <cstdlib>
using namespace std;
class Solution {
public:
    vector<string> ans;
    vector<string> restoreIpAddresses(string s) {
        dfs(s, "", 0, 1);
        return ans;
    }

    void dfs(string& s, string ip, int beginIdx, int numberIdx){
        if(numberIdx == 4){
            string temp = s.substr(beginIdx, s.length() - beginIdx);
            int num = stoi(temp);
            if(num > 255 && !to_string(num) == temp)
                return;
            ans.push_back(ip + "." + temp);
            return;
        }
        for(int len = 1; len <= 3 && beginIdx + len < s.length(); len++){
            string temp = s.substr(beginIdx, len);
            int num = stoi(temp);
            if(num <= 255 && to_string(num) == temp){
                if(numberIdx == 1)
                    dfs(s, ip + temp, beginIdx + len, numberIdx + 1);
                else dfs(s, ip + "." + temp, beginIdx + len,  numberIdx + 1);
            }
        }
        return;
    }
};