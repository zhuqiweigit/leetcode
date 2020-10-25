#include <queue>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int idx = 0;
        vector<string> ans;
        if(nums.size() == 0)
            return ans;
        for(int i = 1; i < nums.size(); i++){
            if(i - idx == (long long)nums[i] - nums[idx])
                continue;
            else{
                if(i - 1 - idx != 0 && (long long)nums[i - 1] - nums[idx] == i - 1 - idx){
                    ans.push_back(to_string(nums[idx]) + "->" + to_string(nums[i - 1]));
                }else{
                    ans.push_back(to_string(nums[idx]));
                }
                idx = i;
            }
        }
        if(nums.size() - 1 - idx != 0 && (long long)nums.back() - nums[idx] == nums.size() - 1 - idx){
            ans.push_back(to_string(nums[idx]) + "->" + to_string(nums.back()));
        }else{
            ans.push_back(to_string(nums.back()));
        }
        return ans;
    }
};