#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    // key: 原节点 value：克隆的节点
    unordered_map<Node*, Node*> visited;
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return nullptr;
        if(visited.find(node) != visited.end()){
            return visited[node];
        }
        Node* cloneNode = new Node(node->val);
        visited[node] = cloneNode;
        for(int i = 0; i < node->neighbors.size(); i++){
            cloneNode->neighbors.emplace_back(cloneGraph(node->neighbors[i]));
        }
        return cloneNode;
    }
};