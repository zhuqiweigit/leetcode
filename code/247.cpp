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
    vector<string> findStrobogrammatic(int n) {
        return helper(n, n);
    }

    vector<string> helper(int n, int actual_n){
        if(n == 1){
            vector<string> ans = {"0", "1", "8"};
            return ans;
        }
        if(n == 2){
            vector<string> ans = {"11", "69", "88", "96"};
            if(actual_n != 2)
                ans.push_back("00");
            return ans;
        }

        vector<string> ans = helper(n - 2, actual_n);
        vector<string> temp;
        for(string& str : ans){
            temp.push_back("1" + str + "1");
            temp.push_back("6" + str + "9");
            temp.push_back("8" + str + "8");
            temp.push_back("9" + str + "6");
            if(actual_n != n){
                temp.push_back("0" + str + "0");
            }
        }
        return temp;
    }
};