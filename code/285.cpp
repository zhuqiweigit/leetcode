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
    TreeNode* pre = nullptr, *ans;
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        inorder(root, p);
        return ans;
    }

    void inorder(TreeNode* root, TreeNode* p){
        if(root == nullptr)
            return;
        inorder(root->left, p);
        if(pre == p && ans == nullptr){
            ans = root;
            return;
        }else{
            pre = root;
        }
        inorder(root->right, p);
    }
};