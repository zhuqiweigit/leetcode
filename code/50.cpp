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
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        else if(n < 0){
            return 1 / fastPow(x, -(long long)n);
        }else return fastPow(x, n);
    }


    double fastPow(double x, long long n){
        if(n == 1)
            return x;
        double temp = fastPow(x, n / 2);
        return n % 2 == 0 ? temp * temp: temp * temp * x;
    }
};