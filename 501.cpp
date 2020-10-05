#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
#include <sstream>
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
    int pre_num = numeric_limits<int>::min(), pre_count = 0;
    int max_cnt = 0;
    vector<int> ans;
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
    }

    void inorder(TreeNode* root){
        if(root == nullptr)
            return;
        inorder(root->left);

        if(pre_num == numeric_limits<int>::min()){
            pre_num = root->val;
            pre_count = 1;
        }else if(pre_num == root->val){
            pre_count++;
        }else{
            pre_num = root->val;
            pre_count = 1;
        }
        if(pre_count > max_cnt){
            max_cnt = pre_count;
            ans.clear();
            ans.push_back(root->val);
        }else if(pre_count == max_cnt){
            ans.push_back(root->val);
        }

        inorder(root->right);
    }
};