#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;
        vector<int> dp(amount + 1, numeric_limits<int>::max());
        for(int i = 0; i < coins.size(); i++){
            if(coins[i] <= amount){
                dp[coins[i]] = 1;
            }
        }
        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < coins.size(); j++){
                if(i - coins[j] >= 0 && dp[i - coins[j]] != numeric_limits<int>::max()) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] == numeric_limits<int>::max() ? -1 : dp[amount];
    }
};