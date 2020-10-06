#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(i != 0 && nums[i - 1] == nums[i])
                continue;
            for(int j = i + 1; j < nums.size(); j++){
                if(j != i + 1 && nums[j - 1] == nums[j])
                    continue;
                twoSum(nums, nums[i], nums[j], target, j + 1, nums.size() - 1);
            }
        }
        return ans;
    }

    void twoSum(vector<int>& nums, int a, int b, int target, int ll, int rr){
        int sum = target - a - b;
        while(ll < rr){
            if(nums[ll] + nums[rr] < sum){
                ll++;
            }else if(nums[ll] + nums[rr] > sum){
                rr--;
            }else{
                vector<int>temp;
                temp.push_back(a);
                temp.push_back(b);
                temp.push_back(nums[ll++]);
                temp.push_back(nums[rr--]);
                ans.push_back(temp);
                while(ll < rr && nums[ll - 1] == nums[ll])
                    ll++;
                while(ll < rr && nums[rr] == nums[rr + 1])
                    rr--;
            }
        }
    }
};