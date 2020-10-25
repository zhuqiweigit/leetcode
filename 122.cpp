#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i = 0; i < prices.size(); i++){
            //find valley
            while(i < prices.size() - 1 && prices[i] >= prices[i + 1]) i++;
            int valley = i;
            while(i < prices.size() - 1 && prices[i] <= prices[i + 1]) i++;
            int top = i;
            profit += (prices[top] - prices[valley]);
        }
        return profit;
    }
};