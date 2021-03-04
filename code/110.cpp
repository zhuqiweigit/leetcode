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
    bool isValid;
    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;
        isValid = true;
        getTreeHeightAndValid(root);
        return isValid;
    }
    int getTreeHeightAndValid(TreeNode* root){
        if(root == nullptr)
            return 0;
        int left = getTreeHeightAndValid(root->left), right = getTreeHeightAndValid(root->right);

        if(abs(left - right) > 1)
            isValid = false;
        return max(left, right) + 1;
    }
};