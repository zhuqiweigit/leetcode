#include <stack>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int min_len = numeric_limits<int>::max();
    int minSubArrayLen(int s, vector<int>& nums) {
        int i = 0, j = 0;
        int sum = 0;
        while(j < nums.size()){
            sum += nums[j++];
            if(sum < s){
                continue;
            }
            while(i <= j && sum >= s){
                sum -= nums[i];
                i++;
                if(j - i + 1< min_len)
                    min_len = j - i + 1;
            }

        }
        return min_len == numeric_limits<int>::max() ? 0 : min_len;
    }

};