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
    int sumNumbers(TreeNode* root) {
        return treeSum(root, 0);
    }

    int treeSum(TreeNode* root, int sum){
        if(root == nullptr)
            return 0;
        sum = sum * 10 + root->val;
        if(root->left == nullptr && root->right == nullptr)
            return sum;
        return treeSum(root->left, sum) + treeSum(root->right, sum);
    }
};