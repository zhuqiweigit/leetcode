#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
#include <set>
using namespace std;
class Solution {
public:
    using ll = long long;
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<ll> tree_set;
        for(int i = 0; i < nums.size(); i++){
            auto upp = tree_set.upper_bound(nums[i]);
            auto don = tree_set.lower_bound(nums[i]);
            if(upp != tree_set.begin() && nums[i] <= *--upp + t)
                return true;
            if(don != tree_set.end() && *don - nums[i] <= t)
                return true;
            if(tree_set.size() >= k){
                tree_set.erase(nums[i - k]);
                tree_set.insert(nums[i]);
            }else{
                tree_set.insert(nums[i]);
            }
        }
        return false;
    }
};