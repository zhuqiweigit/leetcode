#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <set>
#include <map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        map<char, int> mp;
        int i = -1, j = 0;
        int max_len = -1;
        while(i < s.length() && j < s.length()){
            if(i == -1){
                mp[s[j]] = j;
                j++;
                mp[s[j]] = j;
                j++;
                i++;
                max_len = 2;
                continue;
            }
            if(mp.find(s[j]) != mp.end() || mp.size() < 2){
                if(j - i + 1 > max_len)
                    max_len = j - i + 1;
                if(mp.size() < 2)
                    mp[s[j]] = j;
                j++;
            }else{
                int minIdx = s.length() + 1;
                char key;
                for(auto k : mp){
                    if(k.second < minIdx){
                        key = k.first; minIdx = k.second;
                    }
                }
                mp.erase(key);
                i = minIdx + 1;
            }
        }
        return max_len;
    }
};