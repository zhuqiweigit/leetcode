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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++){
            index[inorder[i]] = i;
        }
        return myBuildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }

    TreeNode* myBuildTree(vector<int>& inorder, vector<int>& postorder,
            int in_ll, int in_rr, int post_ll, int post_rr
    ){
        if(post_ll > post_rr){
            return nullptr;
        }
        int postRootIdx = post_rr, inRootIdx = index[postorder[postRootIdx]];
        int llen = inRootIdx - in_ll, rlen = in_rr - inRootIdx;
        TreeNode* root = new TreeNode(postorder[postRootIdx]);
        root->left = myBuildTree(inorder, postorder, in_ll, inRootIdx - 1, post_ll, post_ll + llen - 1);
        root->right = myBuildTree(inorder, postorder, inRootIdx + 1, in_rr, post_ll + llen, post_rr - 1);
        return root;
    }
};