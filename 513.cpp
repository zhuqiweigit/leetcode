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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> qu;
        TreeNode* node = root, *left = root;
        if(node == nullptr)
            return 0;
        qu.push(node);
        while(!qu.empty()){
            int size = qu.size();
            left = qu.front();
            for(int i = 0; i < size; i++){
                node = qu.front(); qu.pop();
                if(node->left)
                    qu.push(node->left);
                if(node->right)
                    qu.push(node->right);
            }
        }
        return left->val;
    }
};