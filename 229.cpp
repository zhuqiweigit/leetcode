#include <queue>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int can1 = numeric_limits<int>::min(), can2 = numeric_limits<int>::min(), cnt1 = 0, cnt2 = 0;
        for(auto num : nums){
           if(num == can1){
                cnt1++;
            }else if(num == can2){
                cnt2++;
            }else{
               if(cnt1 == 0){
                   cnt1++;
                   can1 = num;
               }else if(cnt2 == 0){
                   cnt2++;
                   can2 = num;
               }else {
                   cnt1--;
                   cnt2--;
               }
            }
        }
        int valid1 = 0, valid2 = 0;
        for(auto num : nums){
            if(num == can1)
                valid1++;
            if(num == can2)
                valid2++;
        }
        vector<int> ans;
        if(valid1 > nums.size() / 3)
            ans.push_back(can1);
        if(valid2 > nums.size() / 3)
            ans.push_back(can2);
        return ans;
    }
};