#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <map>
using namespace std;
class Solution {
public:
    int maxProduct(vector<string>& words) {
        map<int, int>mp;
        int mask;
        for(int i = 0; i < words.size(); i++){
            mask = 0;
            for(int j = 0; j < words[i].size(); j++){
                mask = mask | (1 << (words[i][j] - 'a'));
            }
            if(mp.find(mask) == mp.end() || mp[mask] < words[i].size()){
                mp[mask] = words[i].size();
            }
        }
        int ans = 0;
        for(auto it = mp.begin(); it != mp.end(); it++){
            for(auto it2 = mp.begin(); it2 != mp.end(); it2++){
                if((it->first & it2->first) == 0 && it->second * it2->second > ans){
                    ans = it->second * it2->second;
                }
            }
        }
        return ans;

    }
};