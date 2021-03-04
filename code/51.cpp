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
    vector<vector<string>> ans;
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> line(n, false), row(n, false);
        unordered_set<int> bais_add, bais_sub;
        vector<string> temp;
        back_trace(0, n, temp, line, row, bais_add, bais_sub);
        return ans;
    }
    void back_trace(int idx, int n, vector<string> &temp, vector<bool> &line, vector<bool>& row,
            unordered_set<int> &bais_add, unordered_set<int> &bais_sub){
        if(idx == n){
            ans.emplace_back(temp);
            return;
        }
        string ss(n, '.');
        for(int i = 0; i < n; i++){
            if(line[idx] || row[i] || bais_add.find(idx + i) != bais_add.end()
            || bais_sub.find(idx - i) != bais_sub.end())
                continue;
            line[idx] = true;
            row[i] = true;
            bais_add.insert(idx + i);
            bais_sub.insert(idx - i);
            ss[i] = 'Q';
            temp.emplace_back(ss);
            back_trace(idx + 1, n, temp, line, row, bais_add, bais_sub);
            ss[i] = '.';
            temp.pop_back();
            bais_add.erase(idx + i);
            bais_sub.erase(idx - i);
            row[i] = false;
            line[idx] = false;
        }
    }
};