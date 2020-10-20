#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long i = 1;
        while(i <= n){
            if(i == n)
                return true;
            i *= 2;
        }
        return false;
    }
};