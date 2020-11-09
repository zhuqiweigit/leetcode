#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, int> string2int;
    vector<string> int2string;
    int idx = 0;
    vector<vector<int>> graph;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        for(int i = 0; i < wordList.size(); i++){
            add_word(wordList[i]);
        }
        if(string2int.find(beginWord) == string2int.end()){
            add_word(beginWord);
            wordList.push_back(beginWord);
        }
        for(int i = 0; i < wordList.size(); i++){
            for(int j = i + 1; j < wordList.size(); j++){
                add_edge(wordList[i], wordList[j]);
            }
        }
       /* if(string2int.find(beginWord) == string2int.end()){
            for(int i = 0; i < wordList.size(); i++){
                add_edge(wordList[i], beginWord);
            }
        }*/
        if(string2int.find(endWord) == string2int.end())
            return {};
        vector<int> cost(idx, INT_MAX);
        int beginId = string2int[beginWord], endId = string2int[endWord];
        cost[beginId] = 0;
        queue<vector<int>> qu;
        qu.push(vector<int>{beginId});
        while(!qu.empty()){
            vector<int> now = qu.front(); qu.pop();
            int now_id = now.back();
            if(now_id == endId){
                vector<string> temp;
                for(int &id : now){
                    temp.push_back(int2string[id]);
                }
                ans.push_back(temp);
            }
            for(int i = 0; i < graph[now_id].size(); i++){
                int to = graph[now_id][i];
                if(cost[now_id] + 1 <= cost[to]){
                    cost[to] = cost[now_id] + 1;
                    vector<int> new_path(now);
                    new_path.push_back(to);
                    qu.push(new_path);
                }
            }
        }
        return ans;
    };

    void add_word(string& word){
        if(string2int.find(word) == string2int.end()){
            graph.emplace_back();
            string2int[word] = idx;
            int2string.emplace_back();
            int2string[idx] = word;
            idx++;
        }
    }

    void add_edge(string &worda, string &wordb){
        int id1 = string2int[worda], id2 = string2int[wordb];
        if(check(worda, wordb)){
            graph[id1].push_back(id2);
            graph[id2].push_back(id1);
        }
    }

    bool check(string &a, string& b){
        if(a.size() != b.size())
            return false;
        int cnt = 0;
        for(int i = 0; i < a.size() && cnt < 2; i++){
            if(a[i] != b[i])
                cnt++;
        }
        return cnt == 1;
    }


};