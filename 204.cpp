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
    int countPrimes(int n) {

        int cnt = 0;
        for(int i = 2; i < n; i++){
            if(helper2(i))
                cnt++;
        }
        return cnt;
    }

    int helper1(int n){
        vector<bool> isPrime(n + 1, true);
        int cnt = 0;
        //从2开始判断素数
        for(int i = 2; i < n; i++){
            //如果当前数字是素数
            if(isPrime[i]) {
                cnt++;
                //把它的倍数全部设置为非素数
                for (int j = i; j <= n; j += i) isPrime[j] = false;
            }
        }
        return cnt;
    }

    bool helper2(int n){
        if(n == 3)
            return true;
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0)
                return false;
        }
        return true;
    }
};