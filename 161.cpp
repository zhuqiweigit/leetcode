#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <cstdlib>
using namespace std;
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int min_len = min(s.length(), t.length());
        if(s.length() != min_len)
            s.swap(t);
        if(t.length() - s.length() >= 2)
            return false;
        if(t == s)
            return false;
        if(s.empty() && t.length() <= 1)
            return true;
        int idx = -1;
        for(int i = 0; i < min_len; i++){
            if(s[i] != t[i]){
                idx = i;
                break;
            }
        }
        if(idx == -1){
            if(t.length() - s.length() == 1)
                return true;
            else return false;
        }

        if(idx < min_len && (s.substr(idx + 1, s.length() - idx - 1) == t.substr(idx + 1, t.length() - idx - 1) ||
                s.substr(idx, s.length() - idx) == t.substr(idx + 1, t.length() - idx - 1)))
            return true;
        return false;

    }
};