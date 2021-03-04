#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        vector<int> check;
        while(x > 0){
            int bit = x % 10;
            x = x / 10;
            check.push_back(bit);
        }
        int i = 0, j = check.size() - 1;
        while(i <= j){
            if(check[i] != check[j])
                return false;
            i++; j--;
        }
        return true;
    }
};