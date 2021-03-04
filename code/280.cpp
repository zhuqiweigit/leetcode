#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
using namespace std;
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.empty() || nums.size() == 1)
            return;
        bool less = true;
        for(int i = 0; i < nums.size() - 1; i++){
            if(less){
                if(nums[i] >= nums[i + 1])
                    swap(nums[i], nums[i + 1]);
            }else{
                if(nums[i] <= nums[i + 1])
                    swap(nums[i], nums[i + 1]);
            }
            less = !less;
        }
    }
};