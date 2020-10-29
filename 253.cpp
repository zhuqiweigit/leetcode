#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
using namespace std;
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pri_q;
        for(auto& itv : intervals){
            if(!pri_q.empty() && itv[0] >= pri_q.top()){
                pri_q.pop();
            }
            pri_q.push(itv[1]);
        }
        return pri_q.size();
    }
};