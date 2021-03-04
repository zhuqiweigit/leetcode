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
    string addBinary(string a, string b) {
        string c;
        if(a.length() < b.length())
            a.swap(b);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int min_len = b.length();
        int add = 0;
        for(int i = 0; i < min_len; i++){
            int tempbit = (a[i] + b[i] - '0' - '0' + add) % 2;
            c = to_string(tempbit) + c;
            add = (a[i] + b[i] - '0' - '0' + add) / 2;
        }
        for(int j = min_len; j < a.length(); j++){
            int tempbit = (a[j] + add - '0') % 2;
            c = to_string(tempbit) + c;
            add = (a[j] - '0' + add) / 2;
        }
        if(add != 0)
            c = to_string(add) + c;
        return c;
    }
};