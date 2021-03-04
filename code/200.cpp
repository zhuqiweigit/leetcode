#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
#include <unordered_map>
#include <pair>
using namespace std;


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if(n == 0)
            return 0;
        int m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    queue<pair<int, int>>qu;
                    ans++;
                    qu.push({i, j});
                    while(!qu.empty()) {
                        pair<int, int> p = qu.front();
                        qu.pop();
                        grid[p.first][p.second] = '0';
                        if (p.first - 1 >= 0 && grid[p.first - 1][p.second] == '1') {
                            qu.push({p.first - 1, p.second});
                            grid[p.first - 1][p.second] = '0';
                        }
                        if (p.first + 1 < n && grid[p.first + 1][p.second] == '1') {
                            qu.push({p.first + 1, p.second});
                            grid[p.first + 1][p.second] = '0';
                        }
                        if (p.second - 1 >= 0 && grid[p.first][p.second - 1] == '1') {
                            qu.push({p.first, p.second - 1});
                            grid[p.first][p.second - 1] = '0';
                        }
                        if (p.second + 1 < m && grid[p.first][p.second + 1] == '1') {
                            qu.push({p.first, p.second + 1});
                            grid[p.first][p.second + 1] = '0';
                        }
                    }
                }
            }
        }
        return ans;
    }
};