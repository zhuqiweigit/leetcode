#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            ans = ans * 26 + (s[i] - 'A' + 1);
        }
        return ans;
    }
};