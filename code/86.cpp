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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy = new ListNode(0, head), *cur = dummy,
                *ll = new ListNode(0, nullptr), *rr = new ListNode(0, nullptr),
                *newHead = ll, *rrhead = rr;
        while(cur->next){
            if(cur->next->val < x){
                ll->next = cur->next;
                ll = ll->next;
            }else{
                rr->next = cur->next;
                rr = rr->next;
            }
            cur = cur->next;
        }
        rr->next = nullptr;
        ll->next = nullptr;
        ll->next = rrhead->next;
        return newHead->next;
    }
};

int main(){
    vector<int> num = {1,4,3,2,5,2};
    ListNode* head = nullptr , *cur;
    for(int i = 0; i < num.size(); i++){
        if(i == 0){
            head = new ListNode(num[i], nullptr);
            cur = head;
        }else{
            ListNode* temp = new ListNode(num[i], nullptr);
            cur->next = temp;
            cur = cur->next;
        }
    }
    Solution solution;
    solution.partition(head, 3);
    return 0;

}