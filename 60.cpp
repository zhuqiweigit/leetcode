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
    string ans;
    bool valid = false;
    int factor[10];
    string getPermutation(int n, int k) {
        int ff = 1;
        for(int i = 1; i <= 9; i++){
            ff *= i;
            factor[i] = ff;
        }
        string path(n, ' ');
        vector<bool> visit(n + 1, false);
        int idx = 0;
        back_trace(idx, n, k, path, 0, visit);
        return ans;
    }


    void back_trace(int &idx, int n, int k, string &path, int cnt, vector<bool>& visit){
        if(valid)
            return;
        if(cnt == n){
            idx++;
            if(idx == k) {
                ans = path;
                valid = true;
                return;
            }
            return;
        }

        for(int i = 1; i <= n; i++){
            if(visit[i] == false){
                if(n - cnt - 1 > 0 && idx + factor[n - cnt - 1] < k){
                    idx += factor[n - cnt - 1];
                    continue;
                }
                visit[i] = true;
                path[cnt] = '0' + i;
                back_trace(idx, n, k, path, cnt + 1, visit);
                visit[i] = false;
            }
        }
    }
};