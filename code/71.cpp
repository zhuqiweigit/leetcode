#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <cstdlib>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        stringstream is(path);
        string tmp;
        vector<string> paths;
        while(getline(is, tmp, '/')){
            if(tmp == ".." && !paths.empty()){
                paths.pop_back();
            }else if(tmp == "."){
                continue;
            }else if(tmp != ".." && tmp != "." && tmp != ""){
                paths.push_back(tmp);
            }
        }
        string ans = "";
        for(auto str : paths){
            ans = ans + "/" + str;
        }
        if(ans.empty())
            ans = "/";
        return ans;
    }
};