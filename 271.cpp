#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <algorithm>
using namespace std;
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        int cnt = 0;
        string ans;
        for(auto &ss : strs){
            cnt = ss.length();
            ans = ans + to_string(cnt)  + " " + ss;
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        int len = 0, idx = 0;
        string temp;
        while(idx < s.length()){
            len = 0;
            while(isdigit(s[idx])){
                len = len * 10 + (s[idx] - '0');
                idx++;
            }
            idx++;
            ans.push_back(s.substr(idx, len));
            idx += len;
        }
        return ans;
    }
};