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
    bool find = false;
    vector<vector<int>> offset = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                dfs(board, word, 0, i, j, visited);
                if(find == true)
                    return true;
            }
        }
        return false;
    }

    void dfs(const vector<vector<char>>& board, const string& word, int idx, int xx, int yy,
             vector<vector<bool>> &visited){
        if(idx >= word.size() || board[xx][yy] != word[idx] || find == true)
            return;
        if(board[xx][yy] == word[idx] && idx == word.size() - 1){
            find = true;
            return;
        }
        visited[xx][yy] = true;
        for(int i = 0; i < 4; i++){
            int new_xx = xx + offset[i][0], new_yy = yy + offset[i][1];
            if(isValid(board, new_xx, new_yy) && visited[new_xx][new_yy] == false){
                dfs(board, word, idx + 1, new_xx, new_yy, visited);
            }
        }
        visited[xx][yy] = false;
    }
private:
    bool isValid(const vector<vector<char>> &board, const int& xx, const int& yy){
        return xx < board.size() && xx >= 0 && yy < board[0].size() && yy >= 0;
    }
};