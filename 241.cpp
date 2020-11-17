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
    vector<int> diffWaysToCompute(string input) {
        return helper(input, 0, input.size() - 1);
    }

    vector<int> helper(string &input, int ll, int rr){
        vector<int> ans;
        for(int i = ll; i <= rr; i++){
            if(input[i] == '+' || input[i] == '-' || input[i] == '*'){
                vector<int> resl = helper(input, ll, i - 1);
                vector<int> resr = helper(input, i + 1, rr);
                for(auto const &rl : resl){
                    for(auto const& rr : resr){
                        ans.push_back(cacl(rl, rr, input[i]));
                    }
                }
            }
        }
        if(ans.empty()){
            ans.push_back(stoi(input.substr(ll, rr - ll + 1)));
        }
        return ans;
    }
private:
    int cacl(int a, int b, char op){
        if(op == '+')
            return a + b;
        else if(op == '-')
            return a - b;
        else return a * b;
    }
};