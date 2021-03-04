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
    string countAndSay(int n) {
        string pre = "1", cur;
        for(int i = 2; i <= n; i++){
            char pre_ch;
            int cnt = 0, j;
            for(j = 0; j < pre.size(); j++){
                if(j == 0){
                    pre_ch = pre[0];
                    cnt = 1;
                    continue;
                }
                if(pre[j] == pre_ch){
                    cnt++;
                    continue;
                }else{
                    cur = cur + to_string(cnt) + pre_ch;
                    pre_ch = pre[j];
                    cnt = 1;
                }
            }
            cur = cur + to_string(cnt) + pre[j - 1];

            pre = cur;
            cur = "";
        }
        return pre;
    }
};