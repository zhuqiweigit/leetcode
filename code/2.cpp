#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <stack>
#include <sstream>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr, *tail = nullptr;
        int carry = 0;
        while(l1 || l2){
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            if(head == nullptr){
                head = new ListNode((n1 + n2 + carry) % 10);
                tail = head;
            }else{
                tail->next = new ListNode((n1 + n2 + carry) % 10);
                tail = tail->next;
            }
            carry = (n1 + n2 + carry) / 10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(carry > 0){
            tail->next = new ListNode(carry);
            tail = tail->next;
        }
        return head;
    }
};