#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <list>
#include <unordered_map>
#include <set>
using namespace std;
class Solution {
    struct bucket{
        int max_val = INT_MIN;
        int min_val = INT_MAX;
        bool used = false;
    };
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() <= 1)
            return 0;
        int max_num = *max_element(nums.begin(), nums.end());
        int min_num = *min_element(nums.begin(), nums.end());
        int bucket_num = nums.size();
        int bucket_size = (max_num - min_num) / bucket_num;
        vector<bucket> buckets(bucket_num);
        for(const auto &item: nums){
            int id = (item - min_num) / bucket_size;
            buckets[id].min_val = min(buckets[id].min_val, item);
            buckets[id].max_val = max(buckets[id].max_val, item);
            buckets[id].used = true;
        }
        int ans = -1, pre_bucket_max = min_num;
        for(const auto &bk : buckets){
            if(bk.used == false)
                continue;
            ans = max(bk.min_val - pre_bucket_max, ans);
            pre_bucket_max = bk.max_val;
        }
        return ans;
    }
};