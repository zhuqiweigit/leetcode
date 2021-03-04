#include <iostream>
#include <vector>
#include <limits>
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
private:
    long long pre_val = numeric_limits<long long>::min();
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr)
            return true;
        if(!isValidBST(root->left))
            return false;
        if(root->val <= pre_val)
            return false;
        pre_val = root->val;
        return isValidBST(root->right);
    }
};