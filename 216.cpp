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
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        dfs(n, k, 0, 0, 1, path);
        return ans;
    }

    void dfs(int n, int k, int sum_now, int cnt_now, int idx, vector<int>& path){
        if(cnt_now > k || sum_now > n){
            return;
        }else if(cnt_now == k){
            if(sum_now == n)
                ans.push_back(path);
            return;
        }
        for(int i = idx; i <= 9; i++){
            path.push_back(i);
            dfs(n, k, sum_now + i, cnt_now + 1, i + 1, path);
            path.pop_back();
        }
    }
};