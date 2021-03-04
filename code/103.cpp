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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        return levelTravel(root);
    }
private:
    vector<vector<int>> levelTravel(TreeNode* root){
        queue<TreeNode*> qu;
        vector<vector<int>> ans;
        if(root == nullptr){
            return ans;
        }
        qu.push(root);
        int depth = 1;
        while(!qu.empty()){
            vector<int> layer;
            int width = qu.size();
            for(int i = 0; i < width; i++) {
                TreeNode *temp = qu.front();
                qu.pop();
                if (depth % 2 != 0)
                    layer.push_back(temp->val);
                else layer.insert(layer.begin(), temp->val);
                if (temp->left) {
                    qu.push(temp->left);
                }
                if (temp->right) {
                    qu.push(temp->right);
                }
            }
            depth++;
            ans.push_back(layer);
        }
        return ans;
    }
};