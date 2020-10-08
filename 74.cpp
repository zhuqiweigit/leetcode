#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0)
            return false;
        int m = matrix[0].size(), n = matrix.size();
        int ll = 0, rr = m * n - 1;
        while (ll <= rr) {
            int mid = ll + (rr - ll) / 2;
            int num_mid = matrix[mid / m][mid % m];
            if (num_mid == target)
                return true;
            else if (num_mid < target) {
                ll = mid + 1;
            } else {
                rr = mid - 1;
            }
        }
        return false;
    }
};