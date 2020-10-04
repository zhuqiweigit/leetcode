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
    map<TreeNode*, int> select, no_select;
    int rob(TreeNode* root) {
        select[nullptr] = 0;
        no_select[nullptr] = 0;
        dfs(root);
        return max(select[root], no_select[root]);
    }

    void dfs(TreeNode* root){
        if(root == nullptr)
            return;
        dfs(root->left);
        dfs(root->right);
        select[root] = root->val + no_select[root->left] + no_select[root->right];
        no_select[root] = max(select[root->left], no_select[root->left]) + max(select[root->right], no_select[root->right]);
    }
};