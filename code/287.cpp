#include <iostream>
#include <vector>
#include <limits>
#include <queue>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        if(n <= 0)
            return -1;
        int ll = 1, rr = n;
        while(ll <= rr){
            int mid = ll + (rr - ll) / 2, cnt = 0;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] <= mid) cnt++;
            }
            if(cnt <= mid){
                ll = mid + 1;
            }else{
                rr = mid - 1;
            }
        }
        return ll;
    }
};