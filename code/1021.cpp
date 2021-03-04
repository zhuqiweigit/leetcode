#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string removeOuterParentheses(string S) {
        int notPair = 1;
        string ans;
        for(int i = 1; i < S.size(); ++i){
            if(S[i] == '(') {
                ++notPair;
            }
            else{
                --notPair;
            }
            if(notPair != 0){
                ans.push_back(S[i]);
            }else{
                notPair = 1;
                ++i;
            }
        }
        return ans;
    }
};



int main(){
    string S = "((()))()";
    Solution solution;
    solution.removeOuterParentheses(S);
    return 0;
}