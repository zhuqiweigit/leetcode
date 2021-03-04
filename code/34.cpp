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
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(binSearchll(nums, target));
        ans.push_back(binSearchrr(nums, target));
        return ans;
    }

    int binSearchll(vector<int>& nums, int target){
        int ll = 0, rr = nums.size() - 1;
        while(ll <= rr){
            int mid = ll + (rr - ll) / 2;
            if(target > nums[mid]){
                ll = mid + 1;
            }else if(target < nums[mid]){
                rr = mid - 1;
            }else if(target == nums[mid]){
                rr = mid - 1;
            }
        }
        if(ll >= nums.size() || nums[ll] != target)
            return -1;
        return ll;
    }
    int binSearchrr(vector<int>&nums, int target){
        int ll = 0, rr = nums.size() - 1;
        while(ll <= rr){
            int mid = ll + (rr - ll) / 2;
            if(target > nums[mid]){
                ll = mid + 1;
            }else if(target < nums[mid]){
                rr = mid - 1;
            }else if(target == nums[mid]){
                ll = mid + 1;
            }
        }
        if(rr < 0 || nums[rr] != target){
            return -1;
        }
        return rr;
    }
};