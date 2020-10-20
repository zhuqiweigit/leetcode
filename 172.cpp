#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0, cnt5 = 0, k = 0;
        for(int i = 5; i <= n; i = i * 5){
            cnt = n / i;
            cnt5 = cnt5 + cnt;
        }
        return cnt5;
    }
};