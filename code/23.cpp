#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <unordered_set>
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
    class data{
    public:
        int val;
        ListNode* head;
        bool operator<(const data& rhs)const{
            return val > rhs.val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<data> pri_q;
        for(auto &head : lists){
            if(head != nullptr){
                pri_q.push({head->val, head});
            }
        }
        ListNode* dummy = new ListNode(), *cur = dummy;
        while(!pri_q.empty()){
            auto head = pri_q.top(); pri_q.pop();
            cur->next = head.head;
            cur = cur->next;
            if(head.head->next){
                pri_q.push({head.head->next->val, head.head->next});
            }
            cur->next = nullptr;
        }
        return dummy->next;
    }
};