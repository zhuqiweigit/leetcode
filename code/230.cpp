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
    int kthSmallest(TreeNode* root, int k) {
        return findKth(root, k);
    }

    int findKth(TreeNode* root, int& k){
        if(root == nullptr)
            return -1;
        int ans = findKth(root->left, k);
        if(ans != -1)
            return ans;
        if(k == 1) {
            return root->val;
        }else{
            --k;
        }
        return findKth(root->right, k);
    }

};