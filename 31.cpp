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
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while(i >= 0){
            if(nums[i] < nums[i + 1])
                break;
            i--;
        }
        int j = i + 1;
        if(i == -1){
            reverse(nums.begin(), nums.end());
            return;
        }else{
            int k;
            for(k = nums.size() - 1; k > i; k--){
                if(nums[k] > nums[i])
                    break;
            }
            swap(nums[i], nums[k]);
            reverse(nums.begin() + j, nums.end());
        }
        return;
    }
};