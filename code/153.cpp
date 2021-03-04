#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int ll = 0, rr = nums.size() - 1;
        if(nums.size() == 1)
            return nums[0];
        while(ll <= rr){
            int mid = ll + (rr - ll) / 2;
            if(mid - 1 >= 0 && nums[mid - 1] > nums[mid])
                return nums[mid];
            else if(mid < nums.size() - 1 && nums[mid + 1] < nums[mid])
                return nums[mid + 1];
            if(nums[ll] < nums[mid]){
                ll = mid + 1;
            }else{
                rr = mid - 1;
            }
        }
        return nums[0];
    }
};