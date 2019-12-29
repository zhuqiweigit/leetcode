#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> stk1, stk2;
        for(const auto & c : S){
            if(c == '#' && !stk1.empty())
                stk1.pop();
            else if(c != '#')stk1.push(c);
        }
        for(const auto &c : T){
            if(c == '#'&& !stk2.empty()) stk2.pop();
            else if(c != '#')stk2.push(c);
        }
        if(stk1.size() != stk2.size())
            return false;
        while(!stk1.empty()){
            if(stk1.top() != stk2.top())
                return false;
            stk1.pop(); stk2.pop();
        }
        return true;
    }
};


int main(){
    string S = "y#fo##f", T = "y#f#o##f";
    Solution solution;
    cout << solution.backspaceCompare(S, T);
    return 0;
}