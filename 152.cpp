#include <vector>
#include <iostream>
#include <limits>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        else if(n == 1)
            return nums[0];
        vector<int>dp_min(n, 0), dp_max(n, 0);
        dp_max[0] = nums[0];
        dp_min[0] = nums[0];
        int ans = dp_max[0];
        for(int i = 1; i < n; i++){
            dp_max[i] = max(dp_max[i - 1] * nums[i], max(dp_min[i - 1] * nums[i], nums[i]));
            dp_min[i] = min(dp_min[i - 1] * nums[i], min(dp_max[i - 1] * nums[i], nums[i]));
            if(dp_max[i] > ans)
                ans = dp_max[i];
        }
        return ans;
    }
};