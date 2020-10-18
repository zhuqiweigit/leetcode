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
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        dfs(candidates, temp, 0, 0, target);
        return ans;
    }

    void dfs(vector<int>& candidates, vector<int> path, int idx, int sum, int target){
        if(idx >= candidates.size() || sum >= target){
            if(sum == target){
                ans.push_back(path);
                return;
            }
            return;
        }

        for(int i = idx; i < candidates.size(); i++){
            if(i > idx && candidates[i] == candidates[i - 1])
                continue;
            path.push_back(candidates[i]);
            dfs(candidates, path, i + 1, sum + candidates[i], target);
            path.pop_back();
        }
        return;
    }
};