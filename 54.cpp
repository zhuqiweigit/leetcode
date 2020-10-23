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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.size() == 0)
            return ans;
        int ll = 0, rr = matrix[0].size() - 1, up = 0, down = matrix.size() - 1;
        while(ll <= rr && up <= down){
            for(int i = ll; i <= rr; i++)
                ans.push_back(matrix[up][i]);
            for(int i = up + 1; i <= down; i++)
                ans.push_back(matrix[i][rr]);
            if(ll < rr && up < down){
                for(int i = rr - 1; i >= ll; i--)
                    ans.push_back(matrix[down][i]);
                for(int i = down - 1; i > up; i--)
                    ans.push_back(matrix[i][ll]);
            }
            ll++; rr--; up++; down--;

        }
        return ans;
    }
};