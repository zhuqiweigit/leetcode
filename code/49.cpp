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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, int>mp;
        vector<vector<string>> ans;
        for(auto str : strs){
            string temp = str;
            sort(temp.begin(), temp.end());
            if(mp.find(temp) != mp.end()){
                ans[mp[temp]].push_back(str);
            }else{
                mp[temp] = ans.size();
                vector<string> v;
                v.push_back(str);
                ans.push_back(v);
            }
        }
        return ans;
    }
};