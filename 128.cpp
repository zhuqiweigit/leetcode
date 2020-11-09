#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(int &num : nums){
            st.insert(num);
        }
        int max_len = 0;
        for(auto num : st){
            if(st.find(num - 1) == st.end()){
                int len = 1, temp = num + 1;
                while(st.find(temp) != st.end()){
                    len++;
                    temp++;
                }
                if(len > max_len)
                    max_len = len;
            }
        }
        return max_len;
    }
};