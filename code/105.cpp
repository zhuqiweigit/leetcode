#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
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
    map<int, int> index;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++){
            index[inorder[i]] = i;
        }
        return myBuildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* myBuildTree(vector<int>& preorder, vector<int>& inorder,
            int pre_ll, int pre_rr, int in_ll, int in_rr){
        if(pre_ll > pre_rr)
            return nullptr;
        int rootIdx_pre = pre_ll;
        int rootIdx_in = index[preorder[rootIdx_pre]];
        TreeNode* root = new TreeNode(preorder[rootIdx_pre]);
        int llen = rootIdx_in - in_ll, rlen = in_rr - rootIdx_in;
        root->left = myBuildTree(preorder, inorder, pre_ll + 1, pre_ll + llen, in_ll, rootIdx_in - 1);
        root->right = myBuildTree(preorder, inorder, pre_ll + llen + 1, pre_rr, rootIdx_in + 1, in_rr);
        return root;
    }
};