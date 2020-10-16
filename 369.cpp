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
    ListNode* plusOne(ListNode* head) {
        int carry = helper(head);
        if(carry){
            ListNode *temp = new ListNode(carry, head);
            return temp;
        }
        return head;
    }

    int helper(ListNode* head){
        if(head->next == nullptr){
            int carry = (head->val + 1) / 10;
            head->val = (head->val + 1) % 10;
            return carry;
        }
        int carry = helper(head->next);
        int this_carry = (head->val + carry) / 10;
        head->val = (head->val + carry) % 10;
        return this_carry;
    }
};