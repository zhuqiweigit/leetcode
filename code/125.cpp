#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <cctype>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        if(s == "")
            return true;
        string s2;
        for(int i = 0; i < s.length(); i++){
            char ch = s[i];
            if(ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9'){
                s2 += tolower(ch);
            }
        }

        int i = 0, j = s2.length() - 1;
        while(i <= j){
            if(s2[i] != s2[j])
                return false;
            i++; j--;
        }
        return true;
    }
};