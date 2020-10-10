#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
       vector<string> ans(numRows);
       int direct = -1, curRow = 0;
       if(numRows == 1)
           return s;
       for(auto ch : s){
           ans[curRow] += ch;
           if(curRow == 0 || curRow == numRows - 1)
               direct *= -1;
           curRow += direct;
       }
       string str;
       for(auto ss : ans){
           str = str + ss;
       }
        return str;
    }
};