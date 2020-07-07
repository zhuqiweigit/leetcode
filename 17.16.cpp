#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int massage(vector<int>& nums) {
        int n = nums.size();
        if(n <= 0)
            return 0;
        int pre_accept = nums[0], pre_reject = 0;
        for(int i = 1; i < n; i++){
            int now_accept = pre_reject + nums[i];
            int now_reject = max(pre_accept, pre_reject);
            pre_accept = now_accept;
            pre_reject = now_reject;
        }
        return max(pre_reject, pre_accept);
    }
};