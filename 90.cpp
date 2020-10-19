#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <map>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        vector<bool> pushed(nums.size(), false);
        vector<int> path;
        sort(nums.begin(), nums.end());
        dfs(nums, path, 0, pushed);
        return ans;
    }

    void dfs(vector<int>& nums, vector<int>& path, int idx, vector<bool> pushed){
        ans.push_back(path);
        if(idx >= nums.size())
            return;
        for(int i = idx; i < nums.size(); i++){
            if(i > idx && nums[i] == nums[i - 1] && pushed[i - 1] == false)
                continue;
            pushed[i] = true;
            path.push_back(nums[i]);
            dfs(nums, path, idx + 1, pushed);
            path.pop_back();
            pushed[i] = false;
        }
    }
};