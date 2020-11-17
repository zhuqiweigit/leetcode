#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
using namespace std;
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int min_cost = 0, second_cost = 0;
        int color = -1;
        for(auto &v : costs){
            int pre_color = color;
            int pre_min_cost = min_cost, pre_second_cost = second_cost;
            min_cost = INT_MAX;
            second_cost = INT_MAX;
            for(int i = 0; i < v.size(); i++){
                int price = i == pre_color ? v[i] + pre_second_cost : v[i] + pre_min_cost;
                if(price < second_cost){
                    if(price < min_cost){
                        second_cost = min_cost;
                        min_cost = price;
                        color = i;
                    }else{
                        second_cost = price;
                    }
                }
            }
        }
        return min_cost;
    }
};