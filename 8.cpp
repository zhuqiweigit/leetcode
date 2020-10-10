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
    int myAtoi(string s) {
        stringstream ss(s);
        string str;
        ss >> str;
        int start, minus = 1;
        if(str[0] == '-'){
            minus = -1;
            start = 1;
        }else if(str[0] == '+'){
            minus = 1;
            start = 1;
        }else if(str[0] >= '0' && str[0] <= '9'){
            start = 0;
            minus = 1;
        }else{
            return 0;
        }
        long long ans = 0;
        for(int i = start; i < str.length() && str[i] >= '0' && str[i] <= '9'; i++){
            ans = ans * 10 + str[i] - '0';
            if(ans * minus > numeric_limits<int>::max())
                return numeric_limits<int>::max();
            if(ans * minus < numeric_limits<int>::min())
                return numeric_limits<int>::min();
        }
        return ans * minus;
    }
};