#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> word_count;
        for(auto &wd : words){
            word_count[wd]++;
        }
        int word_len = words[0].size();
        vector<int> ans;
        for(int i = 0; i < word_len; i++){
            int ll = i, rr = ll, cnt = 0;
            unordered_map<string, int> temp_count;
            while(rr + word_len <= s.size()){
                string w = s.substr(rr, word_len);
                rr += word_len;
                if(word_count.find(w) == word_count.end()){
                    ll = rr;
                    cnt = 0;
                    temp_count.clear();
                }else{
                    cnt++;
                    temp_count[w]++;
                    while(temp_count[w] > word_count[w]){
                        temp_count[s.substr(ll, word_len)]--;
                        ll += word_len;
                        cnt--;
                    }
                    if(cnt == words.size())
                        ans.push_back(ll);
                }
            }
        }
        return ans;
    }
};