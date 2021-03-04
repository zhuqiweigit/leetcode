#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
using namespace std;
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> father(n, 0);
        for(int i = 0; i < n; i++){
            father[i] = i;
        }
        for(const auto& e : edges){
            if(find(e[0], father) == find(e[1], father))
                return false;
            union_set(e[0], e[1], father);
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(father[i] == i)
                cnt++;
        }
        return cnt == 1;
    }

private:
    int find(int x, vector<int>& father){
        if(x == father[x])
            return x;
        //路径压缩
        father[x] = find(father[x], father);
        return father[x];
    }
    void union_set(int x, int y, vector<int>& father){
        int fx = find(x, father);
        int fy = find(y, father);
        if(fx != fy){
            father[fx] = fy;
        }
    }
};