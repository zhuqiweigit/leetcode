#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
#include <sstream>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mp;
        if(s.size() != t.size())
            return false;
        for(int i = 0; i < s.size(); i++){
            if(mp.find(s[i]) == mp.end())
                mp[s[i]] = 1;
            else mp[s[i]]++;
        }
        for(int j = 0; j < t.size(); j++){
            if(mp.find(t[j]) == mp.end())
                return false;
            if(mp[t[j]] <= 0)
                return false;
            mp[t[j]]--;
        }
        return true;
    }
};