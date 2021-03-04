#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0)
            return 0;
        unordered_set<char> st;
        int maxLen = -1;
        int ll = 0, rr = ll + 1;
        for(; ll < s.length(); ll++){
            if(ll == 0)
                st.insert(s[ll]);
            while(rr < s.length() && st.find(s[rr]) == st.end()){
                st.insert(s[rr++]);
            }
            if(maxLen < rr - ll)
                maxLen = rr - ll;
            st.erase(s[ll]);
        }
        return maxLen;
    }
};