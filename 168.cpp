#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while(n > 0){
           int bit = n % 26;
           n = n / 26;
           if(bit == 0){
               bit = 26;
               n--;
           }
           ans = (char)('A' + bit - 1) + ans;
        }
        return ans;
    }
};