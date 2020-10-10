#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int arrangeCoins(int n) {
        int ll = 1, rr = n;
        while(ll <= rr){
            int mid = ll + (rr - ll) / 2;
            if(countCoin(mid) <= n){
                ll = mid + 1;
            }else{
                rr = mid - 1;
            }
        }
        return rr;
    }

private:
    long long countCoin(long long level){
        return (1 + level) * level / 2;
    }
};