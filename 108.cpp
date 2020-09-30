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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return  buildTree(nums, 0, nums.size() - 1);
    }
    TreeNode* buildTree(vector<int>& nums, int ll, int rr){
        if(ll > rr)
            return nullptr;
        int rootIdx = (ll + rr) / 2;
        TreeNode* root = new TreeNode(nums[rootIdx]);
        root->left = buildTree(nums, ll, rootIdx - 1);
        root->right = buildTree(nums, rootIdx + 1, rr);
        return root;
    }
};