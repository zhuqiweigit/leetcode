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
    int trap(vector<int>& height) {
        if(height.size() <= 2)
            return 0;
        vector<int> l_max(height.size(), 0), r_max(height.size(), 0);
        int ans = 0;
        l_max[0] = height[0];
        r_max.back() = height.back();
        for(int i = 1; i < height.size(); i++){
            l_max[i] = max(height[i], l_max[i - 1]);
        }
        for(int j = height.size() - 2; j >= 0; j--){
            r_max[j] = max(height[j], r_max[j + 1]);
        }
        for(int i = 0; i < height.size(); i++){
            ans += min(l_max[i], r_max[i]) - height[i];
        }
        return ans;

    }
};