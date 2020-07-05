#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0)
            return 0;
        vector<int> profit(n, 0);
        int min_price = prices[0], max_profit = 0;
        for(int i = 1; i < n; i++){
            profit[i] = max(profit[i - 1], prices[i] - min_price);
            if(min_price > prices[i])
                min_price = prices[i];
            if(profit[i] > max_profit)
                max_profit = profit[i];
        }
        return max_profit;
    }
};