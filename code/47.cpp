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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> pushed(nums.size(), false);
        vector<int> temp;
        sort(nums.begin(), nums.end());
        dfs(nums, temp, pushed);
        return ans;
    }

    void dfs(vector<int>& nums, vector<int> &path, vector<bool>& pushed){
        if(path.size() == nums.size()){
            ans.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i - 1] && !pushed[i - 1] || pushed[i])
                continue;
            path.push_back(nums[i]);
            pushed[i] = true;
            dfs(nums, path, pushed);
            pushed[i] = false;
            path.pop_back();
        }
        return;
    }
};