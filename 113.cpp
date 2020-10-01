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
    vector<int> path;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return ans;
    }

    void dfs(TreeNode* root, int sum){
        if(root == nullptr)
            return;
        if(root->left == nullptr && root->right == nullptr && root->val == sum){
            path.push_back(root->val);
            ans.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(root->val);
        dfs(root->left, sum - root->val);
        dfs(root->right, sum - root->val);
        path.pop_back();
    }
};