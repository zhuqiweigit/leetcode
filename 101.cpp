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
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;
        return checkSubTree(root->left, root->right);
    }
private:
    bool checkSubTree(TreeNode* p, TreeNode* q){
        if(p == q && p == nullptr)
            return true;
        else if(p == nullptr && q != nullptr || p != nullptr && q == nullptr){
            return false;
        }
        return p->val == q->val && checkSubTree(p->left, q->right) && checkSubTree(p->right, q->left);
    }
};