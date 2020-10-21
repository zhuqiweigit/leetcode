#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
using namespace std;
class Solution {
public:
    int addDigits(int num) {
        int root = num % 9;
        if(root == 0 && num == 0)
            return 0;
        else if(root == 0 && num != 0)
            return 9;
        else return root;
    }
};