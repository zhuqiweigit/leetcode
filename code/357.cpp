#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        n = min(n, 10);
        int first = 10, second = 9 * 9;
        int ans = first + second;
        if(n == 0)
            return 1;
        if(n == 1 || n == 2)
            return n == 1 ? first : first + second;
        for(int i = 3; i <= n; i++){
            second = second * (10 - i + 1);
            ans += second;
        }
        return ans;
    }
};