#include <iostream>
#include <vector>
#include <limits>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0, p2 = nums.size() - 1, cur = 0;
        while(cur < p2){
            if(nums[cur] == 0){
                swap(nums[p0], nums[cur]);
                p0++;
            }else if(nums[cur] == 1){
                cur++;
                continue;
            }else{
                swap(nums[p2], nums[cur]);
                p2--;
            }
        }

    }
};