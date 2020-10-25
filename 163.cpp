#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        if(nums.size() == 0){
            if(lower == upper)
                ans.push_back(to_string(lower));
            else ans.push_back(to_string(lower) + "->" + to_string(upper));
            return ans;
        }
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i + 1] - nums[i] == 2)
                ans.push_back(to_string(nums[i] + 1));
            else if(nums[i + 1] - nums[i] > 2){
                ans.push_back(to_string(nums[i] + 1) + "->" + to_string(nums[i + 1] - 1));
            }
        }
        if(nums[0] - lower == 1){
            ans.insert(ans.begin(), to_string(lower));
        }else if(nums[0] - lower > 1){
            ans.insert(ans.begin(), to_string(lower) + "->" + to_string(nums[0] - 1));
        }
        if(upper - nums.back() == 1){
            ans.push_back(to_string(upper));
        }else if(upper - nums.back() > 1){
            ans.push_back(to_string(nums.back() + 1) + "->" + to_string(upper));
        }
        return ans;
    }
};