#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
#include <sstream>
using namespace std;

class Solution {
public:
    //<val, loc>
    map<int, int> mp;
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++){
            if(mp.count(target - nums[i]) != 0 && mp[target - nums[i]] != i){
                ans.push_back(i);
                ans.push_back(mp[target - nums[i]]);
                break;
            }
        }
        return ans;
    }
};