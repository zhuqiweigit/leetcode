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
    bool verifyPreorder(vector<int>& preorder) {
        return helpVerify(preorder, 0, preorder.size() - 1);
    }

    bool helpVerify(vector<int>& preorder, int ll, int rr){
        if(ll > rr)
            return true;
        int rootIdx = ll, llen = 0;
        //find left tree
        for(int i = ll + 1; i <= rr; i++){
            if(preorder[rootIdx] < preorder[i]){
                break;
            }else{
                llen++;
            }
        }
        //varify right tree
        for(int i = ll + llen + 1; i <= rr; i++){
            if(preorder[rootIdx] > preorder[i]){
                return false;
            }
        }
        return helpVerify(preorder, ll + 1, ll + llen) && helpVerify(preorder, ll + llen + 1, rr);
    }

};