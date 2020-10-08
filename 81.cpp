#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int ll = 0, rr = nums.size() - 1;
        while(ll <= rr){
            int mid = ll + (rr - ll) / 2;
            if(target == nums[mid])
                return true;
            if(nums[mid] == nums[ll]){
                ll++;
                continue;
            }else if(nums[mid] > nums[ll]){
                if(target >= nums[ll] && target < nums[mid])
                    rr = mid - 1;
                else ll = mid + 1;
            }else if(nums[mid] < nums[ll]){
                if(target > nums[ mid] && target <= nums[rr])
                    ll = mid + 1;
                else rr = mid - 1;
            }
        }
        return false;
    }
};