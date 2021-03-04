#include <stack>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
    const int min_val = numeric_limits<int>::min();
    int ans = min_val;
public:
    int findPeakElement(vector<int>& nums) {
        int ll = 0, rr = nums.size() - 1;
        while(ll <= rr){
            int mid = ll + (rr - ll) / 2;
            if(mid < rr && nums[mid] < nums[mid + 1]){
                ll = mid + 1;
            }else if(mid > ll && nums[mid] < nums[mid - 1]){
                rr = mid - 1;
            }else return mid;
        }
        return ll;
    }
};