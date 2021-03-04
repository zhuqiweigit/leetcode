#include <iostream>
#include <string>
#include <vector>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        curr = root;
    }

    /** @return the next smallest number */
    int next() {
        int val = -1;
        while(curr != nullptr || !stk.empty()){
            while(curr != nullptr){
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            val = curr->val;
            curr = curr->right;
            break;
        }
        return  val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return curr != nullptr || !stk.empty();
    }
private:
    TreeNode* curr = nullptr;
    stack<TreeNode*> stk;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */



int main(){
    return 0;
}