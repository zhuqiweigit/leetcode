#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
#include <sstream>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int max_vol = numeric_limits<int>::min();
        while(i < j){
            int vol = (j - i) * min(height[i], height[j]);
            if(max_vol < vol)
                max_vol = vol;
            if(height[i] < height[j]){
                i++;
            }else{
                j--;
            }
        }
        return max_vol;
    }
};