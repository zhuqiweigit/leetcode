#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
#include <sstream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* x = nullptr, *y = nullptr, *pred = nullptr;
        while(!stk.empty() || root != nullptr){
            while(root){
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if(pred && pred->val >= root->val){
                if(x == nullptr){
                    x = pred;
                    y = root;
                }else{
                    y = root;
                }
            }
            pred = root;
            root = root->right;
        }
        swap(x->val, y->val);
    }
};