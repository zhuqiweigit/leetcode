#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <list>
#include <unordered_map>
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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        return helper(root);
    }

    TreeNode* helper(TreeNode* root){
        if(root == nullptr || root->left == nullptr)
            return root;
        TreeNode* ll = helper(root->left);
        TreeNode* new_root = ll;
        TreeNode* new_root_right = new_root;
        while(new_root_right->right){
            new_root_right = new_root_right->right;
        }
        new_root_right->left = root->right;
        new_root_right->right = root;
        root->left = nullptr;
        root->right = nullptr;
        return new_root;
    }
};