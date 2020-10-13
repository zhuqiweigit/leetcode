#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <algorithm>
using namespace std;
class Solution {
public:
    int calculate(string s) {
        stack<char> sign;
        stack<int> number;
        const int empty_num = numeric_limits<int>::min();
        int tempnum = empty_num;
        s = s + "#";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' ')
                continue;
            if(isdigit(s[i])){
                if(tempnum == empty_num)
                    tempnum = 0;
                tempnum = tempnum * 10 + (s[i] - '0');
                continue;
            }
            if(isSign(s[i])){
                if(tempnum != empty_num){
                    number.push(tempnum);
                    tempnum = empty_num;
                }
                if(s[i] == ')'){
                    while(sign.top() != '('){
                        int b = number.top(); number.pop();
                        int a = number.top(); number.pop();
                        number.push(cacl(a, b, sign.top()));
                        sign.pop();
                    }
                    sign.pop();
                }else if(sign.empty() || larger(s[i], sign.top())){
                    sign.push(s[i]);
                }else{
                    while(!sign.empty() && larger(s[i], sign.top()) == false) {
                        int b = number.top(); number.pop();
                        int a = number.top(); number.pop();
                        number.push(cacl(a, b, sign.top()));
                        sign.pop();
                    }
                    sign.push(s[i]);
                }
            }
        }
        return number.top();
    }
    bool isSign(char c){
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '#';
    }
    bool larger(char a, char instk){
        if(a == '('){
            return true;
        }
        if(a == '*' || a == '/'){
            if(instk == '+' || instk == '-')
                return true;
        }
        if(a == '+' || a == '-'){
            if(instk == '+' || instk == '-')
                return true;
        }
        return false;
    }
    int cacl(int a, int b, char ss){
        if(ss == '+')
            return a + b;
        else if(ss == '-')
            return a - b;
        else if(ss == '*')
            return a * b;
        else return a / b;
    }
};