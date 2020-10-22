#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <cctype>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int canditate, cnt = 0;
        for(auto num : nums){
            if(cnt == 0){
                canditate = num;
            }
            if(canditate == num)
                cnt++;
            else cnt--;
        }
        return canditate;
    }
};