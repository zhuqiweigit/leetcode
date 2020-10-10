#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        vector<int> base = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> sbase = {"M","CM","D","CD", "C", "XC", "L","XL", "X","IX", "V","IV", "I"};
        string ss;
        int idx = 0;
        while(num > 0 && idx >= 0){
            while(num >= base[idx]){
                num = num - base[idx];
                ss = ss + sbase[idx];
            }
            idx--;
        }
        return ss;
    }
};