#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <cctype>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans(2, 0);
        int xor_num = 0;
        for(auto num : nums){
            xor_num = xor_num ^ num;
        }
        int cnt = 0;
        while((xor_num & 1) == 0){
            cnt++;
            xor_num = xor_num >> 1;
        }
        int tag = 1 << cnt;
        for(auto num : nums){
            if(num & tag){
                ans[0] = ans[0] ^ num;
            }else{
                ans[1] = ans[1] ^ num;
            };
        }
        return ans;
    }
};