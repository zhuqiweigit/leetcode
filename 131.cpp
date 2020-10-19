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
    vector<vector<string>> partition(string s) {
        vector<string> path;
        dfs(s, path);
        return ans;
    }


    void dfs(string s, vector<string> &path){
        if(s.empty()) {
            ans.push_back(path);
            return;
        }

        for(int len = 1; len <= s.length(); len++){
            string llstr = s.substr(0, len);
            if(check_str(llstr) == false)
                continue;
            string rrstr = s.substr(len, s.length() - len);
            path.push_back(llstr);
            dfs(rrstr, path);
            path.pop_back();
        }
    }

    bool check_str(const string& ss){
        int i = 0, j = ss.length() - 1;
        while(i <= j){
            if(ss[i] != ss[j])
                return false;
            i++; j--;
        }
        return true;
    }
};

int main(){
    string ss = "aab";
    Solution solution;
    vector<vector<string>> ans = solution.partition(ss);
    return 0;

}