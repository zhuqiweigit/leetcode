#include <queue>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums);
        int mul = 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            mul = mul * nums[i];
            ans[i] = mul;
        }
        mul = 1;
        for(int i = 0; i < nums.size() - 1; i++){
            ans[i] = mul * ans[i + 1];
            mul = mul * nums[i];
        }
        ans.back() = mul;
        return ans;
    }
};