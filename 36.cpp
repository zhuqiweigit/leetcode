#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<map<char, int>> row(9), line(9), grid(9);
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.')
                    continue;
                if(row[i].find(board[i][j]) != row[i].end()){
                    return false;
                }else{
                    row[i][board[i][j]] = 1;
                }
                if(line[j].find(board[i][j]) != line[j].end()){
                    return false;
                }else{
                    line[j][board[i][j]] = 1;
                }
                int ii = i / 3, jj = j / 3;
                int gridIdx = ii * 3 + jj;
                if(grid[gridIdx].find(board[i][j]) != grid[gridIdx].end()){
                    return false;
                }else{
                    grid[gridIdx][board[i][j]] = 1;
                }
            }
        }
        return true;

    }
};