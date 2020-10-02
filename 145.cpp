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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        TreeNode* node = root, *pre = nullptr;
        while(!stk.empty() || node != nullptr){
            while(node != nullptr){
                stk.push(node);
                node = node->left;
            }
            node = stk.top(); stk.pop();
            if(node->right == nullptr || node->right == pre){
                //visit
                ans.push_back(node->val);
                pre = node;
                node = nullptr;
            }else{
                stk.push(node);
                node = node->right;
            }
        }
        return ans;
    }

    vector<int> postorderTraversal2(TreeNode* root){
        vector<int> ans;
        stack<TreeNode*> stk;
        TreeNode* node = root;
        while(!stk.empty() || node != nullptr){
            while(node != nullptr){
                ans.insert(ans.begin(), node->val);
                stk.push(node);
                node = node->right;
            }
            node = stk.top(); stk.pop();
            node = node->left;
        }
        return ans;
    }
};