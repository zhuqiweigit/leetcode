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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* ll = dummy, *rr = dummy;
        for(int i = 0; i <= n; i++){
            rr = rr->next;
        }
        while(rr){
            rr = rr->next;
            ll = ll->next;
        }
        ListNode* temp = ll->next;
        ll->next = ll->next->next;
        delete temp;
        return dummy->next;
    }
};