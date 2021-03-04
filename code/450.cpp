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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)
            return nullptr;
        if(root->val > key){
            root->left = deleteNode(root->left, key);  //如果待删除的key较小，那需要去root的左子树删除某个节点，而不用删除root
            return root;
        }else if(root->val < key){
            root->right = deleteNode(root->right, key); //如果待删除的key较大，需要去root的右子树删除某个节点
            return root;
        }else{   //如果待删除的key就是root
            if(root->left == nullptr){  //删除root，如果root的左子树为空，则用root的右孩子代替root，然后直接删除root
                TreeNode* temp = root;
                root = root->right;
                delete temp;
                return root;
            }else if(root->right == nullptr){ //同理
                TreeNode* temp = root;
                root = root->left;
                delete temp;
                return root;
            }else{
                //如果root的左右子树都不空。则从右子树里找到root的后继节点，交换一下它俩的值；
                // 现在root已经不是key了，然后继续递归删除key元素
                TreeNode* temp = root->right;
                while(temp->left) temp = temp->left;
                swap(root->val, temp->val);
                root->right = deleteNode(root->right, key);
                return root;
            }
        }
    }
};