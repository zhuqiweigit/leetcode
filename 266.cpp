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
    bool isStrobogrammatic(string num) {
        int i = 0, j = num.size() - 1;
        if(num.size() == 0)
            return true;
        while(i <= j){
            if(num[i] != '0' && num[i] != '1' && num[i] != '6'
            && num[i] != '8' && num[i] != '9')
                return false;
            if(num[j] != '0' && num[j] != '1' && num[j] != '6'
               && num[j] != '8' && num[j] != '9')
                return false;
            if(num[i] == '6' && num[j] == '9' || num[i] == '9' && num[j] == '6'
            || num[i] != '6' && num[i] != '9' && num[i] == num[j]){
                i++; j--;
                continue;
            }
            return false;
        }
        return true;
    }
};