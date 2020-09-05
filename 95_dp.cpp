#include <iostream>
#include <vector>
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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> dp[n + 1];
        if(n == 0)
            return dp[0];
        dp[0].push_back(nullptr);
        for(int len = 1; len <= n; len++){
            for(int root = 1; root <= len; root++){
                //left subTree: 0....root - 1, 【len = root - 1】
                //right subTree: root + 1 ... len, 【len = len - root】
                int leftLen = root - 1;
                int rightLen = len - root;
                for(auto llSubTree : dp[leftLen]){
                    for(auto rrSubTree : dp[rightLen]){
                        TreeNode* r = cloneSubTree(rrSubTree, len - rightLen);
                        TreeNode* rootNode = new TreeNode(root,  llSubTree, r);
                        dp[len].push_back(rootNode);
                    }
                }
            }
        }
        return dp[n];
    }

private:
    TreeNode* cloneSubTree(TreeNode* root, int offset){
        if(root == nullptr)
            return nullptr;
        TreeNode* ans = new TreeNode(root->val + offset);
        ans->left = cloneSubTree(root->left, offset);
        ans->right = cloneSubTree(root->right, offset);
        return ans;
    }
};