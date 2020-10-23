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
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int idx = 1;
        int ll = 0, rr = n - 1, up = 0, down = n - 1;
        while(ll <= rr && up <= down){
            for(int i = ll; i <= rr; i++) {
                ans[up][i] = idx;
                idx++;
            }
            for(int i = up + 1; i <= down; i++){
                ans[i][rr] = idx;
                idx++;
            }
            if(ll < rr && up < down){
                for(int i = rr - 1; i >= ll; i--){
                    ans[down][i] = idx;
                    idx++;
                }
                for(int i = down - 1; i > up; i--){
                    ans[i][ll] = idx;
                    idx++;
                }
            }
            ll++; rr--; up++; down--;
        }
        return ans;
    }
};