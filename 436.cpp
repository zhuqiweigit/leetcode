#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <unordered_set>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<vector<int>, int> mp;
        int idx = 0;
        for(auto item : intervals){
            mp[item] = idx++;
        }
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
            return *a.begin() < *b.begin();
        });
        vector<int> ans(intervals.size());
        for(int i = 0; i < intervals.size(); i++){
            int target = intervals[i][1];
            int ll = i + 1, rr = intervals.size() - 1;
            while(ll <= rr){
                int mid = ll + (rr - ll) / 2;
                if(intervals[mid][0] >= target)
                    rr = mid - 1;
                else ll = mid + 1;
            }
            if(ll >= intervals.size())
                ans[mp[intervals[i]]] = -1;
            else ans[mp[intervals[i]]] = mp[intervals[ll]];
        }

        return ans;
    }
};