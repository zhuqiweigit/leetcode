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
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        dfs(n, path, 1, 0, k );
        return ans;
    }

    void dfs(int n, vector<int> &path, int idx, int now_k, int k){
        if(path.size() == k || now_k == k){
            ans.push_back(path);
            return;
        }
        for(int i = idx; i <= n; i++){
            path.push_back(i);
            dfs(n, path, i + 1, now_k + 1, k);
            path.pop_back();
        }
    }
};