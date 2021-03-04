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
    int largestRectangleArea(vector<int>& heights) {
        return helper2(heights);
    }

    int helper1(vector<int>& heights){
        int len = heights.size(), max_size = 0;
        for(int i = 0; i < len; i++){
            int ll = i, rr = i;
            while(ll >= 0 && heights[ll] >= heights[i]) ll--;
            while(rr < len && heights[rr] >= heights[i]) rr++;
            max_size = max(max_size, (rr - ll - 1) * heights[i]);
        }
        return max_size;
    }
    int helper2(vector<int>& heights){
        heights.emplace_back(0);
        stack<int> stk;
        int len = heights.size(), max_size = 0;
        for(int i = 0; i < len; i++){
            if(stk.empty()){
                stk.push(i);
                continue;
            }
            int idx = stk.top();
            if(heights[i] >= heights[idx]){
                stk.push(i);
            }else if(heights[i] < heights[idx]){
                while(!stk.empty() && heights[i] < heights[stk.top()]){
                    idx = stk.top();
                    stk.pop();
                    int ll = idx;
                    if(stk.empty())
                        ll = -1;
                    else ll = stk.top() + 1;
                    max_size = max(max_size, heights[idx] * (i - ll));
                }
                stk.push(i);
            }
        }
        return max_size;
    }
};
int main(){
    Solution solution;
    vector<int> k = {2,4,6,5,3,1};
    cout << solution.largestRectangleArea(k);
    return 0;
}