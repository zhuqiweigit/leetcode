#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <map>
using namespace std;
class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0, "");
        return ans;
    }

    void dfs(int n, int llnum, int rrnum, string str){
        if(llnum >= n && rrnum >= n){
            ans.push_back(str);
            return;
        }
        if(llnum < n){
            dfs(n, llnum + 1, rrnum, str + "(");
        }
        if(rrnum < llnum){
            dfs(n, llnum, rrnum + 1, str + ")");
        }
    }
};