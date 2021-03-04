#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
using namespace std;
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> temp;
        for(auto num : nums){
            temp.push_back(to_string(num));
        }
        sort(temp.begin(), temp.end(), [](string &a, string &b){
            if(a + b > b + a)
                return true;
            else return false;
        });
        string ans;
        for(int i = 0; i < temp.size(); i++){
            if(ans == "0" && temp[i] == "0")
                continue;
            ans = ans + temp[i];
        }
        return ans;
    }
};