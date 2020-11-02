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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i;
        for(i = 0; i < intervals.size(); i++){
            if(intervals[i][0] > newInterval[0])
                break;
            ans.push_back(intervals[i]);
        }
        if(ans.size() == 0){
            ans.push_back(newInterval);
        }else{
            if(newInterval[0] > ans.back()[1]){
                ans.push_back(newInterval);
            }else if(newInterval[0] <= ans.back()[1]){
                ans.back()[1] = max(newInterval[1], ans.back()[1]);
            }
        }
        for(; i < intervals.size(); i++){
            if(intervals[i][0] > ans.back()[1]){
                ans.push_back(intervals[i]);
            }else if(intervals[i][0] <= ans.back()[1]){
                ans.back()[1] = max(intervals[i][1], ans.back()[1]);
            }
        }
        return ans;
    }
};