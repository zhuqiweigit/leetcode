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
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
        if(nums.size() == 0)
            return -1;
        while(left <= right){
            mid = (left + right) / 2;
            if(nums[mid] == target)
                return mid;
           if(nums[0] <= nums[mid]){
               if(target < nums[mid] && target >= nums[0])
                   right = mid - 1;
               else left = mid + 1;
           }else{
               if(target > nums[mid] && target <= nums[nums.size() - 1])
                   left = mid + 1;
               else right = mid - 1;
           }
        }
        return -1;
    }
};