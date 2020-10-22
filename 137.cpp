#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <cctype>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int X = 0, Y = 0;
        for(auto num : nums){
            int Z = num;
            int Xt = (X & (~Y) & (~Z)) | (~(X) & Y & Z);
            int Yt = ((~X) & Y & (~Z)) | ((~X) & (~Y) & Z);
            X = Xt;
            Y = Yt;
        }
        return Y;
    }
};