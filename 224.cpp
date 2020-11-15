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
    int calculate(string s) {
        stack<int> stk;
        stack<char> sign;
        s = s + "#";
        int idx = 0, ans = 0;
        while(idx < s.size()) {
            if (s[idx] >= '0' && s[idx] <= '9') {
                int num = 0;
                while (s[idx] >= '0' && s[idx] <= '9') {
                    num = num * 10 + (s[idx] - '0');
                    idx++;
                }
                stk.push(num);
            }else if(s[idx] == '+' || s[idx] == '-') {
                if(sign.empty() || !sign.empty() && sign.top() == '(')
                    sign.push(s[idx++]);
                else{
                    int num1 = stk.top(); stk.pop();
                    int num2 = stk.top(); stk.pop();
                    if(sign.top() == '+')
                        stk.push(num2 + num1);
                    else stk.push(num2 - num1);
                    sign.pop();
                    sign.push(s[idx++]);
                }
            }else if(s[idx] == '('){
                sign.push(s[idx++]);
            }else if(s[idx] == ')' || s[idx] == '#'){
                while(s[idx] == ')' && !sign.empty() && sign.top() != '(' || s[idx] == '#' && !sign.empty()){
                    int num1 = stk.top(); stk.pop();
                    int num2 = stk.top(); stk.pop();
                    if(sign.top() == '+')
                        stk.push(num2 + num1);
                    else stk.push(num2 - num1);
                    sign.pop();
                }
                sign.pop();
                idx++;
            }else{
                idx++;
            }
        }
        return stk.top();
    }
};