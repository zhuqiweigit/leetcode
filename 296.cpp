#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
using namespace std;
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> rows, cols;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());
        int rmid = rows[rows.size() / 2];
        int cmid = cols[cols.size() / 2];
        return helper(rows, rmid) + helper(cols, cmid);

    }

    int helper(vector<int> &num, int mid){
        int sum = 0;
        for(auto n : num){
            sum += abs(n - mid);
        }
        return sum;
    }
};