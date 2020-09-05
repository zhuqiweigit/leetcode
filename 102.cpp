#include <iostream>
#include <vector>
#include <limits>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> qu;
        if(root == nullptr)
            return ans;
        qu.push(root);
        while(!qu.empty()){
            vector<int> layer;
            int width = qu.size();
            for(int i = 0; i < width; i++){
                TreeNode* temp = qu.front();
                qu.pop();
                layer.push_back(temp->val);
                if(temp->left != nullptr)
                    qu.push(temp->left);
                if(temp->right != nullptr)
                    qu.push(temp->right);
            }
            ans.push_back(layer);
        }
        return ans;
    }
};