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
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<pair<int, int>> points;
        for(auto const& tup : buildings){
            points.insert(make_pair(tup[0], -tup[2]));
            points.insert(make_pair(tup[1], tup[2]));
        }
        multiset<int> skyline;
        skyline.insert(0);
        int pre_height = 0;
        vector<vector<int>> ans;
        for(const auto& pt : points){
            if(pt.second < 0){
                skyline.insert(-pt.second);
            }else{
                skyline.erase(skyline.find(pt.second));
            }
            if(*skyline.rbegin() != pre_height){
                pre_height = *skyline.rbegin();
                ans.push_back(vector{pt.first, pre_height});
            }
        }
        return ans;
    }
};