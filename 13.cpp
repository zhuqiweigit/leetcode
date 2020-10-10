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
    int romanToInt(string s) {
        vector<int> base = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> sbase = {"M","CM","D","CD", "C", "XC", "L","XL", "X","IX", "V","IV", "I"};
        map<string, int>mp;
        for(int i = 0; i < sbase.size(); i++){
            mp[sbase[i]] = base[i];
        }
        int sum = 0;
        for(int i = 0; i < s.length(); i++){
            if(i + 1 < s.length() && mp.find(s.substr(i, 2)) != mp.end()){
                sum += mp[s.substr(i, 2)];
                i++;
                continue;
            }
            sum += mp[s.substr(i, 1)];
        }
        return sum;
    }
};