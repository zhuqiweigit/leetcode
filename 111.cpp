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
    int minDepth(TreeNode* root) {
        return getMinDepth(root);
    }
    int getMinDepth(TreeNode* root){
        if(root == nullptr)
            return 0;
        if(root->left == nullptr && root->right == nullptr)
            return 1;
        if(root->left && root->right)
            return min(getMinDepth(root->left), getMinDepth(root->right)) + 1;
        if(root->left)
            return getMinDepth(root->left) + 1;
        else
            return getMinDepth(root->right) + 1;
    }
};