#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int size = costs.size();
        vector<int> pre_red(size, 0), pre_blue(size, 0), pre_green(size, 0);
        pre_red[0] = costs[0][0]; pre_blue[0] = costs[0][1]; pre_green[0] = costs[0][2];
        for(int i = 1; i < size; i++){
            pre_red[i] = min(pre_blue[i - 1], pre_green[i - 1]) + costs[i][0];
            pre_green[i] = min(pre_red[i - 1], pre_blue[i - 1]) + costs[i][2];
            pre_blue[i] = min(pre_red[i - 1], pre_green[i - 1]) + costs[i][1];
        }
        return min(pre_green[size - 1], min(pre_blue[size - 1], pre_red[size - 1]));
    }
};

int main(){
    Solution solution;
    vector<vector<int>> cost = {{14,3,19}};
    cout << solution.minCost(cost);
    return 0;
}