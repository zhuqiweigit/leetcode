#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        TreeNode* node = root;
        while(!stk.empty() || node){
            while(node != nullptr){
                ans.push_back(node->val);
                stk.push(node);
                node = node->left;
            }
            node = stk.top(); stk.pop();
            node = node->right;
        }
        return ans;
    }

    vector<int> preorderTraversal2(TreeNode* root){
        vector<int> ans;
        stack<TreeNode*> stk;
        TreeNode* node = root;
        if(node != nullptr)
            stk.push(node);
        while(!stk.empty()){
            node = stk.top(); stk.pop();
            ans.push_back(node->val);
            if(node->right)
                stk.push(node->right);
            if(node->left)
                stk.push(node->left);
        }
        return ans;
    }
};
