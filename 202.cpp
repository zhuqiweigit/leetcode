#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
#include <set>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        set<int> st;
        while(true){
            if(st.find(n) != st.end())
                return false;
            st.insert(n);
            if(n == 1)
                return true;
            n = getNext(n);
        }
    }

    int getNext(int n){
        int sum = 0;
        while(n > 0){
            int digit = n % 10;
            n = n / 10;
            sum += digit * digit;
        }
        return sum;
    }
};