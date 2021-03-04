#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    map<string, int> mp;
    vector<string> findRepeatedDnaSequences(string s) {
        for(int i = 0; i + 10 <= s.size(); i++){
            string str = s.substr(i, 10);
            if(mp.find(str) == mp.end())
                mp[str] = 1;
            else mp[str]++;
        }
        vector<string> ans;
        for(auto &kv : mp){
            if(kv.second > 1)
                ans.push_back(kv.first);
        }
        return ans;
    }
};