#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
using namespace std;
class Solution {
public:
    string order;
    bool valid = true;
    string alienOrder(vector<string>& words) {
        vector<vector<int>> graph(26);
        vector<int> visit(26, -1);
        for(auto const& word : words){
            for(auto ch : word){
                visit[ch - 'a'] = 0;
            }
        }
        for(int i = 0; i < words.size() - 1; i++){
            for(int j = 0; j < words[i].size() && j < words[i + 1].size(); j++){
                if(words[i][j] == words[i + 1][j])
                    continue;
                else{
                    int v1 = words[i][j] - 'a', v2 = words[i + 1][j] - 'a';
                    if(find(graph[v1].begin(), graph[v1].end(), v2) != graph[v1].end())
                        break;
                    graph[v1].push_back(v2);
                    break;
                }
            }
        }
        bool empty = true;
        for(auto &g : graph){
            if(!g.empty())
                empty = false;
        }
        if(empty){
            return "";
        }
        for(int i = 0; i < 26; i++){
            if(visit[i] == 0)
                topology_sort(visit, graph, i);
        }
        reverse(order.begin(), order.end());
        return valid ? order : "";

    }

    void topology_sort(vector<int> &visit, vector<vector<int>> &graph, int node){
        if(valid == false)
            return;
        visit[node] = 1;
        for(auto v : graph[node]){
            if(visit[v] == 1) {
                valid = false;
                return;
            }else if(visit[v] == 0){
                topology_sort(visit, graph, v);
            }
        }
        visit[node] = 2;
        order.push_back('a' + node);
    }
};