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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        if(!head)
            return nullptr;
        ListNode* cur = head->next;
        head->next = nullptr;
        while(cur){
            ListNode* item = cur;
            cur = cur->next;
            item->next = nullptr;
            ListNode *dummy_cur = dummy->next, *pre = dummy;
            bool succeed = false;
            while(dummy_cur){
                if(dummy_cur->val > item->val){
                    pre->next = item;
                    item->next = dummy_cur;
                    succeed = true;
                    break;
                }else{
                    dummy_cur = dummy_cur->next;
                    pre = pre->next;
                }
            }
            if(succeed == false){
                pre->next = item;
            }
        }
        return dummy->next;
    }
};