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

lass Solution {
        public:
        int maxLen = 0;
        int longestConsecutive(TreeNode* root) {
            dfs(root, -2, 0);
            return maxLen;
        }
        void dfs(TreeNode* root, int fatherValue, int curLen){
            if(root == nullptr)
                return;
            if(root->val == fatherValue + 1){
                curLen++;
            }else{
                curLen = 1;
            }
            if(curLen > maxLen)
                maxLen = curLen;
            dfs(root->left, root->val, curLen);
            dfs(root->right, root->val, curLen);
        }

};