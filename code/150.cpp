#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <list>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(const auto& tk : tokens){
            if(tk == "+" || tk == "-" || tk == "*" || tk == "/"){
                int a = stk.top(); stk.pop();
                int b = stk.top(); stk.pop();
                if(tk == "+")
                    stk.push(b + a);
                else if(tk == "-")
                    stk.push(b - a);
                else if(tk == "*")
                    stk.push(b * a);
                else
                    stk.push(b / a);
                }
            }else{
                int num = stoi(tk);
                stk.push(num);
            }
        }
        return stk.top();
    }
};