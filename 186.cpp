#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <algorithm>
using namespace std;
class Solution {
public:
    void reverseWords(vector<char>& s) {
        int i = 0;
        for(int j = 0; j < s.size(); j++){
            if(j == ' '){
                reverse(s.begin() + i, s.begin() + j);
                i = j + 1;
            }
        }
        reverse(s.begin(), s.end());
        return;
    }
};