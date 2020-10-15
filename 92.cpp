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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode( 0, nullptr),
        *dummy_old = new ListNode(0, head), *cur = dummy_old;
        for(int i = 0; i < m - 1; i++){
            cur = cur->next;
        }
        ListNode* point = cur;
        cur = cur->next;
        ListNode* last_head_insert = cur;
        for(int i = m; i <= n; i++){
            ListNode* temp = dummy->next;
            dummy->next = cur;
            cur = cur->next;
            dummy->next->next = temp;
        }
        point->next = dummy->next;
        if(last_head_insert){
            last_head_insert->next = cur;
        }
        return dummy_old->next;
    }
};