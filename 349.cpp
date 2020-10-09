#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st(nums1.begin(), nums1.end()), ans;
        for(auto item : nums2){
            if(st.find(item) != st.end())
                ans.insert(item);
        }
        vector<int> ans_vec(ans.begin(), ans.end());
        return ans_vec;
    }
};