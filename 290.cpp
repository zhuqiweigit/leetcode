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
    bool wordPattern(string pattern, string s) {
        stringstream is(s);
        string word;
        map<char, string> mp;
        map<string, char> mp2;
        for(int i = 0; i < pattern.size(); i++){
            if(!(is >> word)){
                return false;
            }
            if(mp.find(pattern[i]) == mp.end()){
                mp[pattern[i]] = word;
            }else{
                if(mp[pattern[i]] !=word)
                    return false;
            }
            if(mp2.find(word) == mp2.end()){
                mp2[word] = pattern[i];
            }else{
                if(mp2[word] != pattern[i])
                    return false;
            }
        }
        if(is >> word)
            return false;

        return true;
    }
};