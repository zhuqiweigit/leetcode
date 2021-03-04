#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
#include <sstream>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return false;
        int row = 0, col = matrix[0].size() - 1;
        while(row < matrix.size() && col >= 0){
            if(target < matrix[row][col]){
                col--;
            }else if(target > matrix[row][col]){
                row++;
            }else{
                return true;
            }
        }
        return false;
    }
};