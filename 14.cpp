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
    string longestCommonPrefix(vector<string>& strs) {
        int min_len = numeric_limits<int>::max();
        string ss;
        if(strs.size() == 0)
            return ss;
        for(auto &vec : strs){
            if(vec.size() < min_len)
                min_len = vec.size();
        }
        for(int i = 0; i < min_len; i++){
            char c;
            for(int j = 0; j < strs.size(); j++){
                if(j == 0)
                    c = strs[j][i];
                if(strs[j][i] != c)
                    return ss;
                if(j == strs.size() - 1)
                    ss = ss + c;
            }
        }
        return ss;
    }
};