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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>&b){
            if(a[0] != b[0])
                return a[0] < b[0];
            else return a[1] < b[1];
        });
        for(int i = 0; i < intervals.size(); i++){
            if(ans.empty() || ans.back()[1] < intervals[i][1])
                ans.push_back(intervals[i]);
            else{
                int L = intervals[i][0], R = intervals[i][1];
                ans.back()[1] = max(ans.back()[1], R);

            }
        }
        return ans;
    }
};