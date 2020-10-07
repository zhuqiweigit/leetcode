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
    int searchInsert(vector<int>& nums, int target) {
        int ll = 0, rr = nums.size() - 1;
        while(ll <= rr){
            int mid = ll + (rr - ll) / 2;
            if(target > nums[mid]){
                ll = mid + 1;
            }else if(target < nums[mid]){
                rr = mid - 1;
            }else return mid;
        }
        return ll;
    }
};