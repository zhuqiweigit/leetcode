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
    bool isIsomorphic(string s, string t) {
        return helper(s, t) && helper(t, s);
    }

    bool helper(string s, string t){
        if(s.length() != t.length())
            return false;
        if(s.empty() && t.empty())
            return true;
        map<char, char> mp;
        for(int i = 0; i < s.length(); i++){
            if(mp.find(s[i]) == mp.end())
                mp[s[i]] = t[i];
            else{
                if(mp[s[i]] != t[i]) return false;
            }
        }
        return true;
    }
};