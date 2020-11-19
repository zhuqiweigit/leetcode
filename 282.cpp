#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
using namespace std;
class Solution {
public:
    vector<string> ans;
    vector<string> addOperators(string num, int target) {
        string path;
        back_trace(num, path, 0, target, 0, 0);
        return ans;
    }

    void back_trace(string& num, string& path, int idx, int target, int val, int pre_num){
        if(idx == num.size() && val == target){
            ans.push_back(path);
            return;
        }

        int len = path.size();
        for(int i = idx; i < num.size(); i++){
            string tempsub = num.substr(idx, i - idx + 1);
            int n = stoi(tempsub);
            if(idx == 0){
                path += tempsub;
                back_trace(num, path, i + 1, target, n, n);
                path.resize(len);
            }else{
                //+
                path += "+" + tempsub;
                back_trace(num, path, i + 1, target, val + n, n);
                path.resize(len);
                //-
                path += "-" + tempsub;
                back_trace(num, path, i + 1, target, val - n, -n);
                path.resize(n);
                //*
                path += "*" + tempsub;
                back_trace(num, path, i + 1, target, val - pre_num + pre_num * n, pre_num * n);
            }
            if(n == 0) return;
        }

    }
};