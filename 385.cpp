#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <map>
using namespace std;
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        int idx = 0;
        return dfs(s, idx);
    }

    NestedInteger dfs(string& s, int &idx){
        if(s[idx] == '['){
            NestedInteger lst;
            idx++;
            while(s[idx] != ']') {
                lst.add(dfs(s, idx));
                if(idx < s.length() && s[idx] == ',')
                    idx++;
            }
            return lst;
        }else{
            int num = numeric_limits<int>::min(), minus = 1;
            if(s[idx] == '-') {
                minus = -1;
                idx++;
            }
            while(isdigit(s[idx])){
                if(num == numeric_limits<int>::min())
                    num = 0;
                num = num * 10 + (s[idx] - '0');
                idx++;
            }
            NestedInteger itg;
            if(num != numeric_limits<int>::min())
                itg.setInteger(num * minus);
            return itg;
        }
    }
};