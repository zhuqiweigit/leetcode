#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {
        int len = pow(2, n);
        vector<int> ans(len, 0);
        helper(ans, 0, 0, ans.size() - 1, true, n);
        return ans;
    }

    void helper(vector<int> &nums, int idx, int ll, int rr, bool zero_first, int n){
        if(idx >= n || ll >= rr)
            return;
        int mid = ll + (rr - ll) / 2;
        if(zero_first){
            for(int i = ll; i <= mid; i++)
                nums[i] = nums[i] & ~(1U << idx);
            for(int i = mid + 1; i <= rr; i++)
                nums[i] = nums[i] | (1u << idx);
        }else{
            for(int i = ll; i <= mid; i++)
                nums[i] = nums[i] | (1U << idx);
            for(int i = mid + 1; i <= rr; i++)
                nums[i] = nums[i] & ~(1u << idx);
        }
        helper(nums, idx + 1, ll, mid, true, n);
        helper(nums, idx + 1, mid + 1, rr, false, n);
    }


};