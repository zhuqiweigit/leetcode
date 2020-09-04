#include <iostream>
#include <vector>
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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        if(n == 0)
            return ans;
        else return subTree(1, n);
    }
    vector<TreeNode*> subTree(int ll, int rr){
        vector<TreeNode*> ans;
        if(ll > rr) {
            ans.push_back(nullptr);
            return ans;
        }else if(ll == rr){
            TreeNode* node = new TreeNode(ll);
            ans.push_back(node);
            return ans;
        }else{
            for(int root = ll; root <= rr; root++){
                vector<TreeNode*> leftSubTrees = subTree(ll, root - 1);
                vector<TreeNode*> rightSubTrees = subTree(root + 1, rr);
                for(auto lt : leftSubTrees){
                    for(auto rt : rightSubTrees){
                        TreeNode* temp = new TreeNode(root, lt, rt);
                        ans.push_back(temp);
                    }
                }
            }
            return ans;
        }
    }
};