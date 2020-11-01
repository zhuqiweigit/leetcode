#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool valid = false;
    bool line[9][10], col[9][10], block[3][3][10];
    vector<pair<int, int>> blank;
    void solveSudoku(vector<vector<char>>& board) {
        memset(line, false, sizeof(line));
        memset(col, false, sizeof(col));
        memset(block, false, sizeof(block));
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    blank.emplace_back(i, j);
                }else{
                    int digit = board[i][j] - '0';
                    line[i][digit] = col[j][digit] = block[i / 3][j / 3][digit] = true;
                }
            }
        }
        dfs(board, 0);
    }

    void dfs(vector<vector<char>> &board, int idx){
        if(idx == blank.size()){
            valid = true;
            return;
        }
        auto [i, j] = blank[idx];
        for(int num = 1; num <= 9; num++){
            if(!valid && !line[i][num] && !col[j][num] && !block[i / 3][j / 3][num]){
                line[i][num] = col[j][num] = block[i / 3][j / 3][num] = true;
                board[i][j] = num + '0';
                dfs(board, idx + 1);
                line[i][num] = col[j][num] = block[i / 3][j / 3][num] = false;
            }
        }
    }
};