#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        map<string, int> mp;
        vector<vector<string>> ans;
        for(string &ss : strings){
            string temp = ss;
            int len = temp[0] - 'a';
            for(char &c : temp){
                c = c - len;
                if(c < 'a')
                    c = c + 26;
            }
            if(mp.find(temp) != mp.end()){
                ans[mp[temp]].push_back(ss);
            }else{
                mp[temp] = ans.size();
                vector<string> vec;
                vec.push_back(ss);
                ans.push_back(vec);
            }
        }
        return ans;
    }
};