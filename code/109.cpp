#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
using namespace std;


struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    TreeNode* sortedListToBST(ListNode* head) {
        return buildTree(head, nullptr);
    }

    TreeNode* buildTree(ListNode* ll, ListNode* rr){
        ListNode* i = ll, *j = ll, *mid = nullptr;
        if(ll == nullptr)
            return nullptr;
        while(i->next != rr){
            i = i->next;
            if(i && i->next != rr){
                i = i->next;
            }else{
                break;
            }
            j = j->next;
        }
        mid = j;
        TreeNode* root = new TreeNode(mid->val);
        root->left = buildTree(ll, mid);
        root->right = buildTree(mid->next, rr);
        return root;
    }
};