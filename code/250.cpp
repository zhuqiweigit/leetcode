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
    int countUnivalSubtrees(TreeNode* root) {
        isUnivalSubTree(root);
        return sum;
    }

    bool isUnivalSubTree(TreeNode* root){
        if(root == nullptr)
            return true;
        bool ll = isUnivalSubTree(root->left);
        bool rr = isUnivalSubTree(root->right);
        if(ll && rr && (root->left && root->val == root->left->val || root->left == nullptr)
        &&(root->right && root->val == root->right->val || root->right == nullptr)){
            sum++;
            return true;
        }
        return false;
    }
};