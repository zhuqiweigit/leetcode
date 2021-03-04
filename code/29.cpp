#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        int minus = dividend >= 0 && divisor > 0 || dividend <= 0 && divisor < 0 ? 1 : -1;
        dividend = dividend > 0 ? -dividend : dividend;
        divisor = divisor > 0 ? -divisor : divisor;
        long long ans = helper(dividend, divisor);
        ans = ans * minus;
        if(ans > numeric_limits<int>::max() || ans < numeric_limits<int>::min())
            return numeric_limits<int>::max();
        return ans;
    }


    //a, b > 0
    long long helper(long long a, long long b){
        long long temp = b;
        if(a > b)
            return 0;
        long long count = 1;
        while(a <= b){
            b += b;
            count += count;
        }
        b = b >> 1;
        count = count >> 1;
        return count + helper(a - b, temp);
    }
};