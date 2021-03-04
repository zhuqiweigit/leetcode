#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans;
        if(numerator == 0)
            return "0";
        int sign = numerator >= 0 && denominator >= 0 || numerator < 0 && denominator < 0 ? 1 : -1;
        long long numerator2 = abs(numerator);
        long long denominator2 = abs(denominator);
        if(numerator2 >= denominator2){
            ans = ans + to_string(numerator2 / denominator2);
            numerator2 = numerator2 % denominator2;
            if(numerator2 == 0)
                return sign > 0 ? ans : "-" + ans;;
            ans = ans + ".";
        }else{
            ans = "0.";
        }
        string ans2;
        map<long long, int> mp;
        int idx = 0;
        while(numerator2 != 0){
            if(mp.find(numerator2) == mp.end()){
                mp[numerator2] = idx;
            }else{
                idx = mp[numerator2];
                ans2.insert(idx, "(");
                ans2.insert(ans2.size(), ")");
                break;
            }
            int bit = numerator2 * 10 / denominator2;
            numerator2 = numerator2 * 10 % denominator2;
            ans2 = ans2 + to_string(bit);
            idx++;
        }
        string ss = sign > 0 ? ans + ans2 : "-" + ans + ans2;
        return ss;
    }
};