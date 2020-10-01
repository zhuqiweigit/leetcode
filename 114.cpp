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
    void flatten(TreeNode* root) {

    }
    void linkNode1(TreeNode* root){
        if(root == nullptr)
            return;
        vector<TreeNode*> vec;
        stack<TreeNode*> stk;
        TreeNode* node = root;
        while(node != nullptr || !stk.empty()){
            while(node){
                vec.push_back(node);
                stk.push(node);
                node = node->left;
            }
            node = stk.top();
            stk.pop();
            node = node->right;
        }
        for(int i = 0; i < vec.size() - 1; i++){
            vec[i]->left = nullptr;
            vec[i]->right = vec[i + 1];
        }
        vec[vec.size() - 1]->right = nullptr;
        return;
    }

    void linkNode2(TreeNode* root){
        if(root == nullptr)
            return;
        stack<TreeNode*> stk;
        TreeNode* node = root, *pre = nullptr;
        stk.push(node);
        while(!stk.empty()){
            node = stk.top();
            stk.pop();
            if(pre != nullptr){
                pre->left = nullptr;
                pre->right = node;
            }
            if(node->right){
                stk.push(node->right);
            }
            if(node->left){
                stk.push(node->left);
            }
            pre = node;
        }
    }

    void linkNode3(TreeNode* root){
        TreeNode * node = root;
        while(node != nullptr){
            if(node->left != nullptr){
                TreeNode* pre = node->left;
                while(pre->right != nullptr)
                    pre = pre->right;
                pre->right = node->right;
                node->right = node->left;
                node->left = nullptr;
            }
            node = node->right;
        }
    }

};