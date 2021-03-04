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
    vector<vector<int>> getFactors(int n) {
        return dfs(n, 2);
    }
    vector<vector<int>> dfs(int n, int factor){
        vector<vector<int>> ans;
        for(int i = factor; i * i <= n; i++){
            if(n % i == 0){
                ans.push_back({n / i, i});
                for(auto& v : dfs(n / i, i)){
                    v.push_back(i);
                    ans.push_back(v);
                }
            }
        }
        return ans;
    }
};