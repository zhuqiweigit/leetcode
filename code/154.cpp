#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <list>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int ll = 0, rr = nums.size() - 1;
        while(ll <= rr){
            int mid = ll + (rr - ll) / 2;
            if(nums[ll] > nums[mid]) rr = mid;
            else if(nums[mid] > nums[rr]) ll = mid + 1;
            else if(nums[ll] < nums[mid]) rr = mid - 1;
            else rr = rr - 1;
        }
        return ll;
    }
};