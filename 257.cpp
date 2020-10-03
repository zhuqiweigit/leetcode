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
    vector<string> ans;
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
        return ans;
    }
    void dfs(TreeNode* root, string s){
        if(root == nullptr){
            return;
        }
        if(root->left == nullptr && root->right == nullptr){
            ans.push_back(s + to_string(root->val));
            return;
        }
        dfs(root->left, s + to_string(root->val) + "->");
        dfs(root->right, s + to_string(root->val) + "->");
    }
};