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
public:
    bool valid = true;
    vector<int> ans;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       vector<vector<int>> graph(numCourses);
       vector<int> visit(numCourses, 0);
       for(auto const& vec : prerequisites){
           graph[vec[1]].push_back(vec[0]);
       }
       for(int i = 0; i < numCourses; i++){
           if(visit[i] == 0){
               dfs(i, visit, graph);
           }else if(valid == false){
               return false;
           }
       }
       return true;

    }

    void dfs(int node, vector<int> &visit, vector<vector<int>>& graph){
        visit[node] = 1;
        for(auto v : graph[node]){
            if(visit[v] == 0){
                dfs(v, visit, graph);
                if(valid == false){
                    return;
                }
            }else if(visit[v] == 1){
                valid = false;
                return;
            }
        }
        visit[node] = 2;
        ans.push_back(node);
    }
};