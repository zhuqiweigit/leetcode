#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> ans;
        if(s.size() < 2)
            return ans;
        for(int i = 0; i < s.size() - 1; i++){
            if(s[i] == '+' && s[i + 1] == '+'){
                s[i] = '-'; s[i + 1] = '-';
                ans.push_back(s);
                s[i] = '+'; s[i + 1] = '+';
            }
        }
        return ans;
    }
};