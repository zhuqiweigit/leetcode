#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> stk(ops.size());
        int ptr = -1, ans = 0, temp;
        for(auto str : ops){
            if(!isOP(str)){
                stringstream ss(str);
                ss >> temp;
                ans += temp;
                stk[++ptr] = temp;
            }else if(str == "+"){
                temp = stk[ptr] + stk[ptr - 1];
                ans += temp;
                stk[++ptr] = temp;
            }else if(str == "D"){
                temp = stk[ptr] * 2;
                ans += temp;
                stk[++ptr] = temp;
            }else if(str == "C"){
                temp = stk[ptr] * -1;
                ans += temp;
                --ptr;
            }
        }
        return ans;
    }
    inline
    bool isOP(const string & s){
        return s == "+" || s == "D" || s == "C";
    }
};
int main(){
    vector<string> op = {"5","-2","4","C","D","9","+","+"};
    Solution solution;
    cout << solution.calPoints(op);
    return 0;
}