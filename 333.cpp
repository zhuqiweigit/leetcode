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
    int maxNodeNum = 0;
    int largestBSTSubtree(TreeNode* root) {
        findHelper(root);
        return maxNodeNum;
    }

    class subTreeInfo{
    public:
        int node_num = 0, max_val = numeric_limits<int>::min(), min_val = numeric_limits<int>::max();
    };

    // return node num of subTree
    subTreeInfo findHelper(TreeNode* root){
        subTreeInfo info;
        if(root == nullptr) {
            return info;
        }
        subTreeInfo ll, rr;
        ll = findHelper(root->left);
        rr = findHelper(root->right);
        bool rootValid = (root->left && root->val > ll.max_val || root->left == nullptr) &&
                (root->right && root->val < rr.min_val || root->right == nullptr);
        if(ll.node_num != -1 && rr.node_num != -1 && rootValid){
            int curNodeNum = ll.node_num + rr.node_num + 1;
            if(curNodeNum > maxNodeNum)
                maxNodeNum = curNodeNum;
            info.node_num = curNodeNum;
            info.min_val = root->val < ll.min_val ? root->val : ll.min_val;
            info.max_val = root->val > rr.max_val ? root->val : rr.max_val;
            return info;
        }else{
            info.node_num = -1;
            return info;
        }
    }

};