#include <iostream>
#include <vector>
#include <limits>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> str_t, str_now;
        int sum_t = 0, sum_now = 0;
        for(const auto &c : t){
            str_t[c]++;
            sum_t++;
        }

        int j = -1;
        int min_len = numeric_limits<int>::max();
        string ans;
        for(int i = 0; i < s.size(); i++){
            if(str_t.find(s[i]) != str_t.end()){
                if(j == -1)
                    j = i;
                str_now[s[i]]++;
                sum_now++;
            }else{
                continue;
            }
            if(sum_now >= sum_t){
                if(check(str_t, str_now)){
                    while(check(str_t, str_now)){
                        if(str_now.find(s[j]) != str_now.end()){
                            str_now[s[j]]--;
                            sum_now--;
                        }
                        j++;
                    }
                    if(min_len > i - j + 2){
                        min_len = i - j + 2;
                        ans = s.substr(j - 1, min_len);
                    }
                }
            }
        }
        return ans;
    }
private:
    bool check(unordered_map<char, int> &str_t, unordered_map<char, int> &str_now){
        for(auto &it : str_t){
            if(str_now.find(it.first) == str_now.end() || str_now[it.first] < it.second)
                return false;
        }
        return true;
    }
};