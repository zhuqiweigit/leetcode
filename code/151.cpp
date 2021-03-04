#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <cstdlib>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        stringstream is(s);
        string ans, temp;
        bool first = true;
        while(is >> temp){
            if(first == true) {
                ans = temp + ans;
                first = false;
            }else{
                ans = temp + " " + ans;
            }
        }
        return ans;
    }
};