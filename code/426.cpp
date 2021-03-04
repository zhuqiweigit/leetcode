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
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* pre = nullptr;
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr)
            return root;
        Node* head = root;
        while(head && head->left){
            head = head->left;
        }
        inorder(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
    void inorder(Node* root){
        if(root == nullptr)
            return;
        inorder(root->left);
        root->left = pre;
        if(pre != nullptr)
            pre->right = root;
        pre = root;
        inorder(root->right);
    }
};