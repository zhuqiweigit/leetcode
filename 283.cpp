#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                nums[idx] = nums[i];
                idx++;
            }else{
                continue;
            }
        }
        for(int i = idx; i < nums.size(); i++){
            nums[i] = 0;
        }
    }
};