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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;
        queue<TreeNode*> qu;
        qu.push(root->left);
        qu.push(root->right);
        while(!qu.empty()){
            TreeNode* p, *q;
            p = qu.front();
            qu.pop();
            q = qu.front();
            qu.pop();
            if(p == nullptr && q != nullptr || p != nullptr && q == nullptr)
                return false;
            else if(p != nullptr && q != nullptr && p->val != q->val)
                return false;
            if(p == q && p == nullptr)
                continue;
            qu.push(p->left);
            qu.push(q->right);
            qu.push(p->right);
            qu.push(q->left);
        }
        return true;
    }

};