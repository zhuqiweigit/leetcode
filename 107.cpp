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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        stack<vector<int>> stk;
        queue<TreeNode*> qu;
        if(root == nullptr)
            return vector<vector<int>>();
        qu.push(root);
        while(!qu.empty()){
            vector<int> level;
            int size = qu.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = qu.front();
                qu.pop();
                level.push_back(node->val);
                if(node->left){
                    qu.push(node->left);
                }
                if(node->right){
                    qu.push(node->right);
                }
            }
            stk.push(level);
        }
        vector<vector<int>> ans;
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
    }
};