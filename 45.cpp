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
    int jump(vector<int>& nums) {
        int max_pos = 0, end = 0, step = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            max_pos = max(max_pos, i + nums[i]);
            if(i == end){
                end = max_pos;
                step++;
            }
        }
        return step;
    }
};