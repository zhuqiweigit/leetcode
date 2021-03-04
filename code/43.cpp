#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <map>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        int minLen = min(num1.size(), num2.size()), maxLen = max(num1.size(), num2.size());
        if(minLen != num1.size()){
            num1.swap(num2);
        }
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        long double mult = 0;
        long double base2 = 1;
        for(int i = 0; i < minLen; i++){
            long long digit = num1[i] - '0', add = 0;
            long double tempSum = 0, base = 1;
            for(int j = 0; j < maxLen; j++){
                tempSum = tempSum + (((num2[j] - '0') * digit + add) % 10) * base;
                base *= 10;
                add = ((num2[j] - '0') * digit + add) / 10;
            }
            if(add != 0){
                tempSum = tempSum + add * base;
            }
            mult = mult + tempSum * base2;
            base2 *= 10;
        }
        string ans = to_string(mult + 0.1);
        int pointpos = ans.find('.');
        ans = ans.substr(0, pointpos);
        return ans;
    }

};