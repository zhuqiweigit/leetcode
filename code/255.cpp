#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
using namespace std;
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> stk;
        int root = INT_MIN;
        for(auto const &node : preorder){
            if(node < root)
                return false;
            while(!stk.empty() && stk.top() < node){
                root = stk.top();
                stk.pop();
            }
            stk.push(node);
        }
        return true;
    }
};