#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
#include <sstream>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> hep;
        for(auto const & num : nums){
            hep.push(num);
            if(hep.size() > k)
                hep.pop();
        }
        return hep.top();
    }
};