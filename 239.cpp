#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
#include <sstream>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    deque<int> window;
    void push(int x){
        while(!window.empty() && window.back() < x){
            window.pop_back();
        }
        window.push_back(x);
    }
    void pop(int x){
        if(!window.empty() && window.front() == x)
            window.pop_front();
    }
    void max(){
        return window.front();
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            if(i < k - 1){
                push(nums[i]);
                continue;
            }else{
                push(nums[i]);
                int x = max();
                ans.push_back(x);
                pop(nums[i - k + 1]);
            }
        }
        return ans;
    }
};