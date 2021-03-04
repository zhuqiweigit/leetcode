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
    int countNodes(TreeNode* root) {
        getCount(root);
        return sum;
    }
    void getCount(TreeNode* root){
        if(root == nullptr)
            return;
        sum += 1;
        getCount(root->left);
        getCount(root->right);
    }
};