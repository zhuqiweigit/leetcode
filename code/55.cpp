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
    bool canJump(vector<int>& nums) {
        int farest = nums[0];
        for(int i = 0; i < nums.size(); i++){
            if(i <= farest){
                if(i + nums[i] > farest)
                    farest = i + nums[i];
                if(farest > nums.size() - 1)
                    return true;
            }
        }
        return false;
    }
};