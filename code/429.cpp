#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> qu;
        vector<vector<int>> ans;
        if(root == nullptr)
            return ans;
        qu.push(root);
        Node* node = root;
        while(!qu.empty()){
            int size = qu.size();
            ans.push_back(vector<int>());
            for(int i = 0; i < size; i++){
                node = qu.front(); qu.pop();
                ans[ans.size() - 1].push_back(node->val);
                for(int j = 0; j < node->children.size(); j++){
                    Node* ch = node->children[j];
                    if(ch){
                        qu.push(ch);
                    }
                }
            }
        }
        return ans;
    }
};