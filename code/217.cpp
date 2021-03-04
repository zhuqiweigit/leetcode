#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
#include <sstream>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> st;
        for(auto item : nums){
            if(st.find(item) == st.end())
                st.insert(item);
            else return true;
        }
        return false;
    }
};