#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
using namespace std;
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        int k = primes.size();
        vector<int> index(k, 0);
        for(int i = 1; i < n; i++){
            int min_ugly = numeric_limits<int>::max();
            for(int j = 0; j < k; j++){
                if(primes[j] * dp[index[j]] < min_ugly)
                    min_ugly = primes[j] * dp[index[j]];
            }
            for(int j = 0; j < k; j++){
                if(primes[j] * dp[index[j]] == min_ugly)
                    index[j]++;
            }
            dp[i] = min_ugly;
        }
        return dp[n - 1];
    }
};