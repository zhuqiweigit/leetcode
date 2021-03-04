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
    int mySqrt(int x) {
        int ll = 0, rr = x;
        while(ll <= rr){
            int mid = ll + (rr - ll) / 2;
            if((long long)mid * mid < x){
                ll = mid + 1;
            }else if((long long)mid * mid > x){
                rr = mid - 1;
            }else return mid;
        }
        return ll - 1;
    }
};