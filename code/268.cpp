#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1 = 0, xor2 = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            xor1 = xor1 ^ nums[i];
            xor2 = xor2 ^ i;
        }
        xor2 = xor2 ^ n;
        return xor1 ^ xor2;
    }
};