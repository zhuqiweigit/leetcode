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
    unordered_map<string, int> wordId;
    int idx = 0;
    vector<vector<int>> graph;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        add_edge(beginWord);
        for(string &word : wordList){
            add_edge(word);
        }
        if(wordId.find(endWord) == wordId.end())
            return 0;
        queue<int> qu;
        vector<int> dst(idx, INT_MAX);
        int beginId = wordId[beginWord], endId = wordId[endWord];
        qu.push(beginId);
        dst[beginId] = 0;
        while(!qu.empty()){
            int temp = qu.front(); qu.pop();
            if(temp == endId)
                return dst[temp] / 2 + 1;
            for(int id : graph[temp]){
                if(dst[id] == INT_MAX){
                    dst[id] = dst[temp] + 1;
                    qu.push(id);
                }
            }
        }
        return 0;
    }

    void add_word(string& word){
        if(wordId.find(word) == wordId.end()){
            graph.emplace_back();
            wordId[word] = idx;
            idx++;
        }
    }

    void add_edge(string& word){
        add_word(word);
        int id1 = wordId[word];
        for(auto &c : word){
            char tmp = c;
            c = '*';
            add_word(word);
            int id2 = wordId[word];
            graph[id1].push_back(id2);
            graph[id2].push_back(id1);
            c = tmp;
        }
    }
};