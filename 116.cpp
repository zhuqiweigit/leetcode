#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> qu;
        if(root == nullptr)
            return root;
        Node* node = root;
        qu.push(node);
        while(!qu.empty()){
            int cnt = qu.size();
            Node* pre = nullptr;
            for(int i = 0; i < cnt; i++){
                node = qu.front(); qu.pop();
                if(node->left){
                    qu.push(node->left);
                }
                if(node->right){
                    qu.push(node->right);
                }
                if(pre != nullptr){
                    pre->next = node;
                }
                pre = node;
            }
        }
        return root;
    }
};