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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root){
            if(root == q || root == p)
                return root;
            if(root->val > p->val && root->val > q->val){
                root = root->left;
            }else if(root->val < p->val && root->val < q->val){
                root = root->right;
            }else{
                return root;
            }
        }
        return nullptr;
    }


    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr)
            return nullptr;
        if(root == p || root == q)
            return root;
        if(root->val > p->val && root->val > q->val){
            return lowestCommonAncestor2(root->left, p, q);
        }else if(root->val < p->val && root->val < q->val){
            return lowestCommonAncestor2(root->right, p, q);
        }else{
            return root;
        }
    }
};