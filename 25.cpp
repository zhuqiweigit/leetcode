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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(), *cur = dummy, *cur_tail;
        ListNode* front = head, *tail = head;
        while(tail != nullptr){
            int i;
            for(i = 0; i < k && tail; i++, tail = tail->next);
            if(i != k){
                cur->next = front;
                break;
            }
            cur_tail = front;
            while(front != tail){
                ListNode* temp = cur->next;
                cur->next = front;
                front = front->next;
                cur->next->next = temp;
            }
            cur = cur_tail;
        }
        return dummy->next;
    }
};