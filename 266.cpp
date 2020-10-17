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
    bool canPermutePalindrome(string s) {
        map<char, int> mp;
        for(int i = 0; i < s.size(); i++){
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]] = 1;
            }else{
                mp[s[i]]++;
            }
        }
        int odd_cnt = 0;
        for(auto &kv : mp){
            if(kv.second % 2 != 0)
                odd_cnt++;
        }
        if(odd_cnt > 1)
            return false;
        return true;
    }
};