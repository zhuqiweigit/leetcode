#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>mp1;
        for(auto item : nums1){
            if(mp1.find(item) != mp1.end()){
                mp1[item]++;
            }else{
                mp1[item] = 1;
            }
        }
        vector<int> ans;
        for(auto item : nums2){
            if(mp1.find(item) != mp1.end() && mp1.find(item)->second > 0){
                ans.push_back(item);
                --mp1[item];
            }
        }
        return ans;
    }
};