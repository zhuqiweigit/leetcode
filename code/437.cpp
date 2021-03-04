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
    int pathSum(TreeNode* root, int sum) {
        if(root == nullptr)
            return 0;
        return dfs(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

    int dfs(TreeNode* root, int sum){
        if(root == nullptr)
            return 0;
        int ans = 0;
        if(sum - root->val == 0)
            ans++;
        return ans + dfs(root->left, sum - root->val) + dfs(root->right, sum - root->val);
    }
};