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
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++){
            if(i > 0 && nums[i - 1] == nums[i])
                continue;
            twoSum(nums, i + 1, nums.size() - 1, nums[i]);
        }
        return ans;
    }

    void twoSum(vector<int>& nums, int ll, int rr, int firnum){
        int sum = -1 * firnum;
        while(ll < rr){
            if(nums[ll] + nums[rr] < sum){
                ll++;
            }else if(nums[ll] + nums[rr] > sum){
                rr--;
            }else{
                vector<int> temp;
                temp.push_back(firnum);
                temp.push_back(nums[ll++]);
                temp.push_back(nums[rr--]);
                ans.push_back(temp);
                while(ll < rr && nums[ll] == nums[ll - 1]){
                    ll++;
                }
                while(ll < rr && nums[rr] == nums[rr + 1]){
                    rr--;
                }
            }
        }
    }
};