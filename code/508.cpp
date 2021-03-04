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
    int max_cnt = 0;
    map<int, int> mp;
    vector<int> ans;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        postorder(root);
        return ans;
    }

    int postorder(TreeNode* root){
        if(root == nullptr)
            return 0;
        int ll = postorder(root->left), rr = postorder(root->right);
        int sum = ll + rr + root->val;
        if(mp.count(sum) != 0){
            mp[sum]++;
        }else{
            mp[sum] = 1;
        }
        if(mp[sum] > max_cnt){
            max_cnt = mp[sum];
            ans.clear();
            ans.push_back(sum);
        }else if(mp[sum] == max_cnt){
            ans.push_back(sum);
        }
        return sum;
    }
};