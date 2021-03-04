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
    ListNode* sortList(ListNode* head) {
        ListNode  *temp = new ListNode(0, head), *fast = temp, *slow = temp;
        if(!head || !head->next){
            return head;
        }
        //find mid
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        //half
        ListNode* ll = head, * rr = slow->next;
        slow->next = nullptr;
        delete temp;
        //sort
        ll = sortList(ll);
        rr = sortList(rr);
        //merge
        ListNode* dummy = new ListNode(0), *cur = dummy;
        while(ll && rr){
            if(ll->val < rr->val){
                cur->next = ll;
                ll = ll->next;
            }else{
                cur->next = rr;
                rr = rr->next;
            }
            cur = cur->next;
            cur->next = nullptr;
        }
        cur->next = ll != nullptr ? ll : rr;
        return dummy->next;
    }
};