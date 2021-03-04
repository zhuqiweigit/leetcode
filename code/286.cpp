#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
using namespace std;
class Solution {
public:
    int offset[4][2] = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};

    void wallsAndGates(vector<vector<int>>& rooms) {
        bfs(rooms);
    }

    void bfs(vector<vector<int>>& rooms){
        const int EMPTY = INT_MAX;
        const int WALL = -1;
        const int DOOR = 0;
        queue<pair<int, int>> qu;
        int m = rooms.size();
        if(m == 0) return;
        int n = rooms[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(rooms[i][j] == DOOR){
                    qu.push(make_pair(i, j));
                }
            }
        }

        while(!qu.empty()){
            pair<int, int> node = qu.front(); qu.pop();
            int x = node.first, y = node.second;
            for(int i = 0; i < 4; i++){
                int xx = x + offset[i][0], yy = y + offset[i][1];
                if(xx < 0 || xx >= m || yy < 0 || yy >= m || rooms[xx][yy] != EMPTY)
                    continue;
                rooms[xx][yy] = rooms[x][y] + 1;
                qu.push(make_pair(xx, yy));
            }
        }
    }
};