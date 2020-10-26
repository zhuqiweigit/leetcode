#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
using namespace std;
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int cnt = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            int sum = target - nums[i];
            int j = i + 1, k = nums.size() - 1;
            while(j < k){
                if(nums[j] + nums[k] < sum){
                    cnt = cnt + (k - j);
                    j++;
                }else{
                    k--;
                }
            }
        }
        return cnt;
    }
};