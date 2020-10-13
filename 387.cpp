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
    int firstUniqChar(string s) {
        map<char, int>mp;
        for(auto ch : s){
            if(mp.find(ch) == mp.end())
                mp[ch] = 1;
            else mp[ch]++;
        }
       for(int i = 0; i < s.size(); i++){
           if(mp[s[i]] == 1)
               return i;
       }
       return -1;
    }
};