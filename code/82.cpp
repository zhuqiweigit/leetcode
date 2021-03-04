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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head), *cur = dummy;
        while(cur->next && cur->next->next){
            if(cur->next->val == cur->next->next->val){
                while(cur->next->next && cur->next->val == cur->next->next->val){
                    ListNode* temp = cur->next->next;
                    cur->next->next = cur->next->next->next;
                    delete temp;
                }
                ListNode* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            }else{
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};