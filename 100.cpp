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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return checkTree(p, q);
    }

private:
    bool checkTree(TreeNode* p, TreeNode* q) {
        if (p == q && p == nullptr)
            return true;
        else if (p == nullptr && q != nullptr || q == nullptr && p != nullptr)
            return false;
        return checkTree(p->left, q->left) && checkTree(p->right, q->right) && p->val == q->val;
    }
};