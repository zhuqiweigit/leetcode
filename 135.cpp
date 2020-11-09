#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum_gas = 0, cur_gas = 0, start = 0;
        for(int i = 0; i < gas.size(); i++){
            sum_gas += (gas[i] - cost[i]);
            cur_gas += (gas[i] - cost[i]);
            if(cur_gas < 0){
                start = i + 1;
                cur_gas = 0;
            }
        }
        return sum_gas < 0 ? -1 : start;
    }
};