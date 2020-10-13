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
    void reverseString(vector<char>& s) {
        int i = 0,j = s.size() - 1;
        if(s.size() == 0)
            return;
        while(i <= j){
            swap(s[i], s[j]);
            i++; j--;
        }

    }
};