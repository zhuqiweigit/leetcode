#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <algorithm>
using namespace std;
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans = "";
        vector<int> cnt(26, 0);
        for(int i = 0; i < s.length(); i++){
            cnt[s[i] - 'a']++;
        }
        for(int i = 0; i < s.length(); i++){
           if(ans.find(s[i]) == string::npos){
               while(ans.size() > 0 && ans[ans.size() - 1] > s[i] && cnt[ans[ans.size() - 1] - 'a'] > 0 ){
                   ans.pop_back();
               }
               ans = ans + s[i];
           }
            --cnt[s[i] - 'a'];
        }
        return ans;
    }
};