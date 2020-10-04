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
    int sum = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root);
        return sum;
    }

    void dfs(TreeNode* root){
        if(root == nullptr)
            return;
        dfs(root->left);
        dfs(root->right);
        if(isLeaf(root->left)){
            sum += root->left->val;
        }
    }
private:
    bool isLeaf(TreeNode* node){
        return node && node->left == nullptr && node->right == nullptr;
    }
};