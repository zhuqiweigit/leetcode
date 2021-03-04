#include <vector>
#include <iostream>
#include <limits>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size, 0);
        dp[0] = nums[0];
        nume
        int max_sum = dp[0];
        for(int i = 1; i < size; i++){
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            max_sum = dp[i] > max_sum ? dp[i] : max_sum;
        }
        return max_sum;
    }
};

int main(){

    vector<int> num = {-2,1,-3,4,-1,2,1,-5,4};
    Solution solution;
    cout << solution.maxSubArray(num);
    return 0;
}