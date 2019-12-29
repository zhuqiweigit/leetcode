#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(const auto& c: s){
            if(c == '(' || c == '[' || c == '{')
                stk.push(c);
            else if(!stk.empty() && (c == ')' && stk.top() == '(' || c == '}' && stk.top() == '{' || c == ']' && stk.top() == '['))
                stk.pop();
            else stk.push(c);
        }
        return stk.empty();
    }
};



int main(){

    return 0;
}