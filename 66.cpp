#include <iostream>
#include <vector>
#include <limits>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i = digits.size() - 1; i >= 0; i--){
            int temp = (digits[i] + carry) % 10;
            carry = (digits[i] + carry) / 10;
            digits[i] = temp;
        }
        if(carry != 0){
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};