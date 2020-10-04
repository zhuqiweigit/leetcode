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
    vector<vector<int>> ans;
    vector<vector<int>> findLeaves(TreeNode* root) {
        dfs(root);
        return ans;
    }
    int dfs(TreeNode* root){
        if(root == nullptr)
            return 0;
        int ll = dfs(root->left), rr = dfs(root->right);
        int depth = max(ll, rr) + 1;
        if(ans.size() < depth)
            ans.push_back(vector<int>());
        ans[depth - 1].push_back(root->val);
        return depth;
    }
};