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
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        dfs(nums, 0, path);
    }

    void dfs(vector<int>& nums, int idx, vector<int>& path){
        ans.push_back(path);
        for(int i = idx; i < nums.size(); i++){
            path.push_back(nums[i]);
            dfs(nums, i + 1, path);
            path.pop_back();
        }
    }
};