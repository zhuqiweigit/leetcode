#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isPerfectSquare(int num) {
        long long ll = 1, rr = num;
        while(ll <= rr){
            long long mid = ll + (rr - ll) / 2;
            if(mid * mid == num)
                return true;
            else if(mid * mid > num)
                rr = mid - 1;
            else ll = mid + 1;
        }
        return false;
    }
};