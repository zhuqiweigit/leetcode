#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        int bit = 0, sign = x > 0 ? 1 : -1;
        long long xx = x, sum = 0;
        xx = abs(xx);
        while(xx > 0){
            bit = xx % 10;
            xx = xx / 10;
            sum = sum * 10 + bit;
        }
        sum = sum * sign;
        if(sum > numeric_limits<int>::max() || sum < numeric_limits<int>::min())
            return 0;
        else return (int)sum;
    }
};