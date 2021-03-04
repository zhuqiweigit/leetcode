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
    priority_queue<pair<double, int>, vector<pair<double, int>>, less<pair<double, int>>> heap;

    void dfs(TreeNode* root, double target, int k){
        if(root == nullptr)
            return;
        dfs(root->left, target, k);
        double diff = abs(target - root->val);
        heap.push(make_pair(diff, root->val));
        if(heap.size() > k)
            heap.pop();
        dfs(root->right, target, k);
    }

    vector<int> closestKValues(TreeNode* root, double target, int k) {
        dfs(root, target, k);
        vector<int> ans;
        while(!heap.empty()){
            ans.push_back(heap.top().second);
            heap.pop();
        }
        return ans;
    }
};