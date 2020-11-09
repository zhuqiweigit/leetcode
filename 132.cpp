#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int offset[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void solve(vector<vector<char>>& board) {
        if(board.empty())
            return;
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O')
                bfs(make_pair(i, 0), board);
            if(board[i][n - 1] == 'O')
                bfs(make_pair(i, n - 1), board);
        }
        for(int j = 0; j < n; j++){
            if(board[0][j] == 'O')
                bfs(make_pair(0, j), board);
            if(board[m - 1][j] == 'O')
                bfs(make_pair(m - 1, j), board);
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'A'){
                    board[i][j] = 'O';
                }else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }

    void bfs(pair<int, int> begin, vector<vector<char>> &board){
        queue<pair<int, int>> qu;
        qu.push(begin);
        board[begin.first][begin.second] = 'A';
        while(!qu.empty()){
            pair<int, int> now = qu.front(); qu.pop();
            int x = now.first, y = now.second;
            for(int i = 0; i < 4; i++){
                int xx = x + offset[i][0], yy = y + offset[i][1];
                if(xx >= 0 && xx < board.size() && yy >= 0 && yy < board[0].size()
                   && board[xx][yy] == 'O'){
                    qu.emplace(xx, yy);
                    board[xx][yy] = 'A';
                }
            }
        }
    }
};