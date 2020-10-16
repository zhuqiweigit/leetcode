#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
#include <sstream>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool succeed = true;
    bool isPalindrome(ListNode* head) {
        ListNode* cur = head;
        int n = 0;
        while(cur){
            n++;
            cur = cur->next;
        }
        if(n == 0)
            return true;
        helper(head, n);
        return succeed;
    }

    ListNode* helper(ListNode* head, int n){
        if(n == 1)
            return head->next;
        if(n == 2){
            if(head->val != head->next->val)
                succeed = false;
            return head->next->next;
        }
        ListNode* temp = helper(head->next, n - 2);
        if(head->val != temp->val)
            succeed = false;
        return temp->next;
    }
};