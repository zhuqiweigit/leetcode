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
    int ans = numeric_limits<int>::min();
    int maxPathSum(TreeNode* root) {
        helper(root);
        return ans;
    }

    int helper(TreeNode* root){
        if(root == nullptr)
            return 0;
        int ll = helper(root->left);
        int rr = helper(root->right);
        int max_val = max(max(root->val, ll + root->val), max(rr + root->val, ll + rr + root->val));
        if(max_val > ans)
            ans = max_val;
        if(max_val != ll + rr + root->val){
            return max_val;
        }else{
            return max(root->val, max(ll + root->val, rr + root->val));
        }
    }
};