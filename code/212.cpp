#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
#include <sstream>
#include <unordered_map>
using namespace std;

class Solution {
    class Tire{
    public:
        bool isEnd;
        Tire* next[26];
        Tire(){
            isEnd = false;
            memset(next, 0, sizeof(next));
        }
    };
public:
    vector<string> ans;
    Tire* root;
    int offset[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new Tire();
        Tire* node;
        for(const auto& wd : words){
            node = root;
            for(const auto &w : wd){
                if(node->next[w - 'a'] == nullptr)
                    node->next[w - 'a'] = new Tire();
                node = node->next[w - 'a'];
            }
            node->isEnd = true;
        }
        string path;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(root->next[board[i][j] - 'a'] != nullptr) {
                    char ch = board[i][j];
                    board[i][j] = '.';
                    path.push_back(board[i][j]);
                    back_trace(make_pair(i, j), path, board, root->next[ch - 'a']);
                    path.pop_back();
                    board[i][j] = ch;

                }
            }
        }
        return ans;
    }

    void back_trace(const pair<int, int>& pos, string &path, vector<vector<char>>& board, Tire* root){
        if(root->isEnd){
            ans.push_back(path);
            root->isEnd = false;
        }
        for(int i = 0; i < 4; i++){
            int x = pos.first + offset[i][0];
            int y = pos.second + offset[i][1];
            if(x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && board[x][y] != '.'){
                char ch = board[x][y];
                if(root->next[ch - 'a'] != nullptr){
                    char temp = board[x][y];
                    board[x][y] = '.';
                    path.push_back(ch);
                    back_trace(make_pair(x, y), path, board, root->next[ch - 'a']);
                    path.pop_back();
                    board[x][y] = temp;
                }
            }
        }
    }
};