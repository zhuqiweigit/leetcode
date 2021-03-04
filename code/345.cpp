#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        if(s.length() == 0)
            return s;
        while(i < j){
            while(i < j && !isAE(s[i])) i++;
            while(i < j && !isAE(s[j])) j--;
            if(isAE(s[i]) && isAE(s[j])) {
                swap(s[i], s[j]);
            }
            i++; j--;
        }
        return s;
    }

    bool isAE(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O'
        || c == 'U';
    }
};