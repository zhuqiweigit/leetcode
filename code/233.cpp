#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
#include <sstream>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int cnt = 0;
        for(int k = 1; k <= n; k *= 10){
            int xyzd = n / k;
            int abc = n % k;
            int d = xyzd % 10;
            int xyz = xyzd / 10;
            cnt += xyz * k;
            if(d > 1){
                cnt += k;
            }else if(d == 1){
                cnt += abc + 1;
            }
            if(xyz == 0){
                break;
            }
        }
        return cnt;
    }
};