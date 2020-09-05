#include <iostream>
#include <vector>
#include <limits>
#include <queue>
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
    int maxDepth(TreeNode* root) {
        return getDepth(root, 0);
    }
    int getDepth(TreeNode* root, int depth){
        if(root == nullptr){
            return depth;
        }
        int ll = 0, rr = 0;
        if(root->left != nullptr)
            ll = getDepth(root->left, depth);
        if(root->right != nullptr)
            rr = getDepth(root->right, depth);
        return max(ll, rr) + 1;
    }
};