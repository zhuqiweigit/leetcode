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
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        s = "";
        while(ss >> s);
        return s.length();
    }
};