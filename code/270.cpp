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
    int closestValue(TreeNode* root, double target) {
        TreeNode* min_ptr = root;
        while(root){
            if(abs(min_ptr->val - target) > abs(root->val - target)){
                min_ptr = root;
            }
            if(target > root->val)
                root = root->right;
            else if(target < root->val)
                root = root->left;
            else break;
        }
        return min_ptr->val;
    }
};