#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
using namespace std;

class Solution {
public:
    vector<vector<int>> offset = {{0,1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1},
                          {-1, 1}, {1, -1}, {1, 1}};
    void gameOfLife(vector<vector<int>>& board) {
        int pre_mask = 0x1, now_mask = 0x2;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                int alive = 0;
                int cnt = 0;
                for(int k = 0; k < 8; k++){
                    int x = i + offset[k][0], y = j + offset[k][1];
                    if(valid(x, y, board) && (pre_mask & board[x][y]) != 0){
                        alive++;
                    }
                }
                if((board[i][j] & pre_mask) != 0 && (alive < 2)) board[i][j] &= (~now_mask);
                else if((board[i][j] & pre_mask) != 0 && (alive == 2 || alive == 3)) board[i][j] |= now_mask;
                else if((board[i][j] & pre_mask) != 0 && (alive > 3)) board[i][j] &= (~now_mask);
                else if((board[i][j] & pre_mask) == 0 && alive == 3) board[i][j] |= now_mask;
            }
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if((board[i][j] & now_mask) == 0)
                    board[i][j] = 0;
                else board[i][j] = 1;
            }
        }

    }

    bool valid(int i, int j, vector<vector<int>>& board){
        if(i >= 0 && i < board.size() && j >= 0 && j < board[0].size())
            return true;
        return false;
    }
};